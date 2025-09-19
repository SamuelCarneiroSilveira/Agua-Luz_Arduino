#include <Arduino.h>

// Pinos dos LEDs
#define vermelho 9
#define amarelo_1 10
#define amarelo_2 11

// Pinos do sensor HC-SR04 (Ultrassônico)
#define trigPin 7
#define echoPin 6

// Pinos do sensor LDR
#define ldrPin A0
#define ldrLimite 500 // Ajuste este valor. Quanto menor, mais sensível ao escuro.

// Pino para selecionar o modo (com um botão ou chave)
#define modoPin 4

// Variáveis para o sensor ultrassônico
long duracao;
int distancia;
bool estadoAnteriorUltrassonico = false;

// Variável para controlar o estado do fogo (ligado ou desligado)
bool fogoLigado = false;

// Variável para escolher qual sensor usar.
// true = Ultrassônico, false = LDR
bool modoUltrassonico = true;

void setup() {
  // Configuração dos pinos dos LEDs
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo_1, OUTPUT);
  pinMode(amarelo_2, OUTPUT);
  
  // Configuração dos pinos do sensor ultrassônico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Configuração do pino do seletor de modo
  pinMode(modoPin, INPUT);

  // Inicia a comunicação serial para debug
  Serial.begin(9600);
}

void loop() {
  // Lê o estado do pino do seletor. Se o pino estiver em HIGH, usa o ultrassônico.
  // Se estiver em LOW, usa o LDR.
  modoUltrassonico = digitalRead(modoPin);

  if (modoUltrassonico) {
    // Modo Ultrassônico
    
    // Lógica para medir a distância
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
  
    duracao = pulseIn(echoPin, HIGH);
    distancia = duracao * 0.034 / 2;
  
    // Lógica do interruptor virtual
    // Verifica se a distância é menor que 10 cm (ou outro valor que você preferir)
    bool proximo = (distancia < 10);
  
    // Detecta a borda de subida (quando a mão fica próxima)
    if (proximo && !estadoAnteriorUltrassonico) {
      // Altera o estado do fogo (liga se estiver desligado, e vice-versa)
      fogoLigado = !fogoLigado;
      delay(500); // Pequeno atraso para evitar múltiplas mudanças rápidas
    }
    
    estadoAnteriorUltrassonico = proximo;

    // Imprime a distância no monitor serial para debug
    Serial.print("Modo: Ultrassônico | Distância: ");
    Serial.print(distancia);
    Serial.println(" cm");

  } else {
    // Modo LDR
    
    // Lê o valor do sensor de luminosidade
    int valorLDR = analogRead(ldrPin);
    
    // A luz acende se o valor for menor que o limite (está escuro)
    if (valorLDR < ldrLimite) {
      fogoLigado = true;
    } else {
      fogoLigado = false;
    }

    // Imprime o valor do LDR no monitor serial para debug
    Serial.print("Modo: LDR | Luminosidade: ");
    Serial.println(valorLDR);
    
  }

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
}