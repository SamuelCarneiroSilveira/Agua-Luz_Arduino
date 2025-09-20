#include <Arduino.h>

//---
// Definições (apelidos para os pinos)
//---
#define LED_VERMELHO 9
#define LED_AMARELO_1 10
#define LED_AMARELO_2 11

#define PINO_TRIGGER 7 // Pino que "dispara" o som
#define PINO_ECHO 6    // Pino que "escuta" o som

#define PINO_LDR A0
#define LIMIAR_LUZ 300 // Nível de escuridão para ligar o fogo automático

//---
// Variáveis Globais (dados que todos podem usar)
//---
bool fogoEstaLigado = false;
bool maoEstaPerto = false;
bool maoEstavaPertoAntes = false;

//---
// Funções (pequenas tarefas que o Arduino pode fazer)
//---

// Função para acender e apagar o fogo
void controlarFogo(bool ligar) {
  if (ligar) {
    // Simulação de fogo: LEDs pulsam de forma aleatória
    analogWrite(LED_VERMELHO, random(120) + 136);
    analogWrite(LED_AMARELO_1, random(120) + 136);
    analogWrite(LED_AMARELO_2, random(120) + 136);
    delay(random(100));
  } else {
    // Apaga todos os LEDs
    analogWrite(LED_VERMELHO, 0);
    analogWrite(LED_AMARELO_1, 0);
    analogWrite(LED_AMARELO_2, 0);
  }
}

// Função para verificar se está escuro
bool estaEscuro() {
  int nivelDeLuz = analogRead(PINO_LDR);
  Serial.print("Nível de Luz: ");
  Serial.println(nivelDeLuz);
  return nivelDeLuz < LIMIAR_LUZ;
}

// Função para medir a distância de um objeto
int medirDistancia() {
  // Dispara o som
  digitalWrite(PINO_TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(PINO_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIGGER, LOW);
  
  // Calcula a distância baseada no tempo que o som leva para voltar
  long duracao = pulseIn(PINO_ECHO, HIGH);
  int distanciaCM = duracao * 0.034 / 2;
  
  Serial.print("Distância: ");
  Serial.print(distanciaCM);
  Serial.println(" cm");
  
  return distanciaCM;
}

//---
// setup() - Onde o programa começa (só roda uma vez)
//---
void setup() {
  // Diz ao Arduino quais pinos são para saída de energia
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO_1, OUTPUT);
  pinMode(LED_AMARELO_2, OUTPUT);
  
  // Diz ao Arduino quais pinos são para o sensor ultrassônico
  pinMode(PINO_TRIGGER, OUTPUT);
  pinMode(PINO_ECHO, INPUT);

  // Inicia a comunicação para ver as mensagens no computador
  Serial.begin(9600);
}

//---
// loop() - Onde o programa se repete para sempre
//---
void loop() {
  // Verifica se está escuro
  if (estaEscuro()) {
    // Se estiver escuro, o fogo fica ligado no modo "automático"
    fogoEstaLigado = true;
    Serial.println("Modo Automático: Escuro detectado!");
  } else {
    // Se estiver claro, usa o sensor de distância
    int distancia = medirDistancia();
    maoEstaPerto = (distancia < 10);
  
    // Detecta se a mão se aproximou (bordas de subida)
    if (maoEstaPerto && !maoEstavaPertoAntes) {
      // Se a mão se aproximou, muda o estado do fogo
      fogoEstaLigado = !fogoEstaLigado;
      delay(500); // Espera um pouco para não "piscar" o fogo sem querer
    }
    maoEstavaPertoAntes = maoEstaPerto;
  }
  
  // Finalmente, acende ou apaga o fogo de acordo com o estado atual
  controlarFogo(fogoEstaLigado);
}