/*
  Minicurso Eletrônica básica e Arduino                   
  Universidade Tecnológica Federal do Paraná - UTFPR

  Projeto 1.2 - Divisor de tensão

  Felipe Xavier 25/02/2020
*/

#define tensaoPin A0                    // Define entrada analogica do divisor de tensao
#define resolucao 0.0048828             // Resolucao minima DAC (5V/1024) [V]

int leitura;                            // Variável que armazena o valor da leitura do pino A0
float tensao;                           // Tensão aferida do divisor de tensão

void setup() 
{
  Serial.begin(9600);
  pinMode(tensaoPin, INPUT);             // Configura o pino como entrada
}

void loop() 
{   
  leitura = analogRead(tensaoPin);                               // Recebe valores do conversor DAC (10 bits):  0..1023 
  tensao =  leitura*resolucao;                                   // Converte a leitura em tensão

  Serial.print("leitura pino A0: ");
  Serial.println(leitura);
  Serial.print("tensao: ");
  Serial.println(tensao);

  delay(1000);                                                   // Atraso 1s
  
}
