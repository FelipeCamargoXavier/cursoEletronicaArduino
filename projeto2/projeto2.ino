/*
  Minicurso Eletrônica básica e Arduino                   
  Universidade Tecnológica Federal do Paraná - UTFPR

  Projeto 2 - Ligar/desligar uma lâmpada

  Felipe Xavier 21/02/2020
*/

int buttonPin = 3;                 // Pino 3 botão
int rele = 2;                      // Pino 2 relé

int buttonState;                   // Estado do botão (ON/OFF)
int releState;                     // Estado do relé (ON/OFF)

void setup()
{
  pinMode(buttonPin, INPUT);       // Define pino botão como entrada
  pinMode(rele, OUTPUT);           // Define pino relé como saída
  releState = LOW;                 // Inicializa relé desligado
  digitalWrite(rele, releState);         
}

void loop()
{
  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH)                  // Se o botão está no nível alto (ON/HIGH) ...
  {
    releState = !releState;                // Liga/desliga o relé
    digitalWrite(rele, releState);         // Aciona o relé
  }
}
