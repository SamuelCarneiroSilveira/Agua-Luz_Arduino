#include <Arduino.h>

// Define os pinos de cada elemento
#define sensor 2
#define rele 3

// Inicia a variável irrigar como falsa
bool irrigar = false;

void setup()
{
  // Define os pinos como entrada ou saída
  pinMode(sensor, INPUT);
  pinMode(rele, OUTPUT);
  
  // Garante que o relé comece desligado
  digitalWrite(rele, HIGH);

  delay(2000); // Aguarda 7 segundos para estabilizar o sensor
}

void loop()
{
  
  // Lê o estado do sensor de umidade
  irrigar = digitalRead(sensor);

  // Verifica se deve ligar ou desligar a bomba
  if(irrigar)
  {
    // Caso irrigar seja verdadeiro, liga a bomba
    digitalWrite(rele, LOW);
    delay(100);
  }
  else
  {
    // Caso contrário, desliga a bomba
    digitalWrite(rele, HIGH);
    delay(10000);
  }  
  // Pequeno atraso para estabilizar a leitura
}