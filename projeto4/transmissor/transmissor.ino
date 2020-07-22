/*
  Minicurso Eletrônica básica e Arduino                   
  Universidade Tecnológica Federal do Paraná - UTFPR

  Projeto 4 - Comunicação por Radiofrequência - Transmissor

  Felipe Xavier 21/02/2020
*/

#include <RH_ASK.h>                           // Biblioteca RadioHead (modulacao ASK)
#include <SPI.h>                              // Necessário somente para compilacao

RH_ASK driver(2000, 4, 8);                    // 200bps, TX em D8 (pino 7), RX em D4 (pino 3)

int PinTrigger = 2;                           // Pino para disparar o sensor / emitir sinal
int PinEcho = 3;                              // Pino leitura do sensor - com a largura do pulso obetemos o tempo entre emissao e recepcao
float tempo = 0;                              // tempo entre a emissao e recepcao do pulso
float distancia;                              // distancia percorrida entre emissao e recepcao (metro)
float distanciacm;                            // distancia percorrida entre emissao e recepcao (centimetro)
char msg[5];                                  // Mensagem transmitida por RF 433 MHz

const float velocidadeSom_mpus = 0.000340;    // Velocidade do som em microsegundos - 0.000340 m/us (340 m/s)

void emitePulsoUltrassonico()
{
  digitalWrite(PinTrigger, HIGH);           // Pulso alto Trigger
  delayMicroseconds(10);                    // Atraso 10 us
  digitalWrite(PinTrigger, LOW);            // Pulso alto Trigger  
}

float calculaDist(float tempous)
{
  float distancia = (velocidadeSom_mpus*tempous)/2;      
  return distancia;                                      // Retorna a distância em metros                 
}

void setup() 
{
  pinMode(PinTrigger, OUTPUT);                  // Trigger como pino de saída
  digitalWrite(PinTrigger, LOW);                // Inicializa trigger em nivel baixo
  pinMode(PinEcho, INPUT);                      // Echo como pino de entrada
  Serial.begin(9600);                           // Inicializa monitor serial 
  delay(100);                                   // Atraso 100 us

  if (!driver.init())
         Serial.println("Erro: modulo RF nao inicializado.");
}

void loop() 
{
  
  emitePulsoUltrassonico();                     // Emite pulso
  tempo = pulseIn(PinEcho, HIGH);               // Duracao do pulso echo em nivel HIGH (retorno em us)
  distancia = calculaDist(tempo);               // Calcula distancia
  
  Serial.print("Distancia em metros: "); 
  Serial.println(distancia); 

  Serial.print("Distancia em centimentros: ");
  distanciacm = 100*distancia;
  Serial.println(distanciacm);
  
  /* Funcao que converte de Float para String
   *    dtostrf(float dist, int numeroCasas, int numeroCasasDecimais, String distStr)
   */
  dtostrf(distanciacm, 5, 2, msg);              
  
  driver.send((uint8_t *)msg, strlen(msg));     // Envia distancia ...
  driver.waitPacketSent();
    
  delay(2000);                                  // Atraso 2s
}
