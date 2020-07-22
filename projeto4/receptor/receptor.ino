/*
  Minicurso Eletrônica básica e Arduino                   
  Universidade Tecnológica Federal do Paraná - UTFPR

  Projeto 4 - Comunicação por Radiofrequência - Receptor

  Felipe Xavier 21/02/2020
*/

#include <RH_ASK.h>                             // Biblioteca RadioHead (modulacao ASK)
#include <SPI.h>                                // Necessário somente para compilacao

RH_ASK driver(2000, 4, 8);                      // 200bps, TX em D8 (pino 7), RX em D4 (pino 3)

uint8_t buf[11];                                // Mensagem recebida sera armazenada aqui
uint8_t buflen = sizeof(buf);
 
void setup()
{
  Serial.begin(9600);
  Serial.println("Inicializando RF 433 MHz");
  if (!driver.init())
         Serial.println("Erro: modulo RF nao inicializado.");  
}
 
void loop()
{
    // Se alguma mensagem for recebida ...
    if(driver.recv(buf, &buflen))
    {
      // Message received with valid checksum
      Serial.print("Distancia recebida: ");
      Serial.println((char*)buf);         
    }
}
