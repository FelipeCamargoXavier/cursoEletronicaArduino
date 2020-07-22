/*
  Minicurso Eletrônica básica e Arduino                   
  Universidade Tecnológica Federal do Paraná - UTFPR

  Projeto 1.1 - Ajuste do brilho de um LED por PWM

  Felipe Xavier 21/02/2020
*/

#define sensorPin A0                    // Define entrada analogica do potenciometro no pino A0
#define ledPin 9                        // Define o pino do LED 

int potenciometroValue = 0;             //Variável que armazena o valor da leitura do potenciômetro

void setup() 
{
  pinMode(ledPin,OUTPUT);               // Configura o pino do LED como saída
}

void loop() 
{   
  potenciometroValue = analogRead(sensorPin);                    // Recebe valores do conversor DAC (10 bits):  0..1023 
  potenciometroValue = map(potenciometroValue,0,1023,0,255);     // Converte a leitura em numeros de 0..255 (0..100% duty cycle)
  analogWrite(ledPin,potenciometroValue);                        // Aciona o LED proporcionalmente ao valor da leitura analógica
}
