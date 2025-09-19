#include <Arduino.h>

// Pinos dos LEDs
#define vermelho 9
#define amarelo_1 10
#define amarelo_2 11

// Pinos do sensor HC-SR04
#define trigPin 7
#define echoPin 6

// Variáveis para o sensor
long duracao;
int distancia;

// Variável para controlar o estado do fogo (ligado ou desligado)
bool fogoLigado = false;

// Variável para controle do "botão" virtual do sensor
bool estadoAnterior = false;

void setup() {
  // Configuração dos pinos dos LEDs como saída
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo_1, OUTPUT);
  pinMode(amarelo_2, OUTPUT);

  // Configuração dos pinos do sensor como entrada e saída
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Inicia a comunicação serial para monitorar a distância
  Serial.begin(9600);
}

void loop() {
  // Lógica para medir a distância
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracao = pulseIn(echoPin, HIGH);
  distancia = duracao * 0.034 / 2;

  // Lógica do interruptor virtual
  // Verifica se a distância é menor que 10 cm
  bool proximo = (distancia < 10);

  // Detecta a borda de subida (quando a mão fica próxima)
  if (proximo && !estadoAnterior) {
    // Altera o estado do fogo (liga se estiver desligado, e vice-versa)
    fogoLigado = !fogoLigado;
    delay(500); // Pequeno atraso para evitar múltiplas mudanças rápidas
  }

  // Atualiza o estado anterior para a próxima iteração
  estadoAnterior = proximo;

  // Lógica de simulação de fogo
  if (fogoLigado) {
    // Se o fogo estiver ligado, os LEDs pulsam
    analogWrite(vermelho, random(120) + 136);
    analogWrite(amarelo_1, random(120) + 136);
    analogWrite(amarelo_2, random(120) + 136);
    delay(random(100));
  } else {
    // Se o fogo estiver desligado, os LEDs ficam apagados
    analogWrite(vermelho, 0);
    analogWrite(amarelo_1, 0);
    analogWrite(amarelo_2, 0);
  }

  // Opcional: imprimir a distância no monitor serial para debug
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");
  delay(100);
}