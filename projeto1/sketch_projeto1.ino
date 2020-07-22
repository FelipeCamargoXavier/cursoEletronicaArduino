/*
  Minicurso Eletrônica básica e Arduino                   
  Universidade Tecnológica Federal do Paraná - UTFPR

  Projeto 1 - Controle Servo motor

  Felipe Xavier 21/02/2020
*/

#include <Servo.h>    // Bilbioteca Servo

#define sensorPin A0  // Define entrada analogica do potenciometro no pino A0

Servo myservo;        // Cria objeto do tipo Servo com nome 'myservo'

int potenciometroValue = 0;        // Valor recebido do potenciometro (0..1023)
int angulo;                        // Angulo/Posicao do servo motor (0..179)

void setup()
{
  Serial.begin(9600);   // Monitor serial, velocidade 9600 Bps
  myservo.attach(6);    // Configura servo para o pino 6
}


void loop()
{
  potenciometroValue = analogRead(sensorPin);               // Recebe valores do conversor DAC (10 bits):  0..1023 
  angulo = map(potenciometroValue, 0, 1023, 0, 179);        // Converte a leitura em numeros de 0..179 (180°)
  myservo.write(angulo);                                    // Controle PWM servo
  delay(15);                                                // Atraso de 15 milisegundos
}
