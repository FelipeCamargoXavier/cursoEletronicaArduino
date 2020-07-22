/*
  Minicurso Eletrônica básica e Arduino
  Universidade Tecnológica Federal do Paraná - UTFPR

  Projeto 5 - Ligar/desligar uma lâmpada automatizada

  Felipe Xavier 24/02/2020
*/

#define buttonPin 3                  // Define Pino 3 botão
#define rele 2                       // Define Pino 2 relé
#define LDR A0                       // Define Pino A0 LDR
#define sensorPIR 4                  // Define Pino 4 sensor PIR
#define resolucao 0.0048828          // Resolucao minima DAC (5V/1024) [V]

int disparoPIR;                      // Disparo do sensor de presenca
int leituraLDR;                      // Leitura do pino analógico do LDR (0..1023)
float tensaoLDR;                     // Tensao do LDR
float tensaoLimiarLDR;               // Tensao referencia claro/escuro do LDR

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);         // Define pino botão como entrada
  pinMode(rele, OUTPUT);             // Define pino relé como saída
  digitalWrite(rele, LOW);           // Inicializa relé desligado

  tensaoLimiarLDR = 3.0;             // Inicializa tensao limiar do LDR  [V]
}

void loop()
{
  leituraLDR = analogRead(LDR);      // Leitura de 0..1023  (DAC 10 bits)
  tensaoLDR = leituraLDR * resolucao; // Converte para tensao 0..5 V

  disparoPIR = digitalRead(sensorPIR);                     // Verifica se há pessoas...

  if (disparoPIR == HIGH && tensaoLDR > tensaoLimiarLDR)   // Se há pessoas E está escuro entao ...
  {
    digitalWrite(rele, HIGH);                              // Aciona o relé
    delay(5000);                                           // Tempo em que a lampada permanece ligada até uma nova verificacao
  }
  else
    digitalWrite(rele, LOW);
}
