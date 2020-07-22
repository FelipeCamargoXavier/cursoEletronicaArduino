/*
  Minicurso Eletrônica básica e Arduino                   
  Universidade Tecnológica Federal do Paraná - UTFPR

  Projeto 3 - Medir distâncias

  Felipe Xavier 21/02/2020
*/

int PinTrigger = 2;                           // Pino para disparar o sensor / emitir sinal
int PinEcho = 3;                              // Pino leitura do sensor - com a largura do pulso obetemos o tempo entre emissao e recepcao
float tempo = 0;                              // tempo entre a emissao e recepcao do pulso

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
}

void loop() 
{
  emitePulsoUltrassonico();                     // Emite pulso
  tempo = pulseIn(PinEcho, HIGH);               // Duracao do pulso echo em nivel HIGH (retorno em us)
  
  Serial.print("Distancia em metros: "); 
  Serial.println(calculaDist(tempo)); 

  Serial.print("Distancia em centimentros: ");
  Serial.println(100*calculaDist(tempo));

  delay(2000);                                  // Atraso 2s

}
