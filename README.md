# Água-Luz_Arduino

Este projeto é uma jornada em duas partes para transformar o seu Arduino em um super-herói do dia a dia. A primeira missão é salvar a sua planta de ficar com sede. A segunda é fazer a luz aparecer magicamente de duas formas diferentes!

---

## 1. Água: O Super-Herói da Irrigação

Este projeto é como um salva-vidas para a sua planta! Usando um Arduino, você vai construir um sistema inteligente que sente quando o solo está seco e liga uma bomba para dar um gole de água para a sua plantinha.

### O Que Você Vai Precisar (Água)

* **1x Placa Arduino:** O cérebro da nossa operação.
* **1x Mini Bomba 5V:** O coração que vai bombear a água.
* **1x Módulo Relé 5V:** O "interruptor eletrônico" que liga e desliga a bomba.
* **1x Sensor de Umidade de Solo YL-69:** O "dedo" que sente se a terra está seca.
* **2x Fontes de Alimentação 5V:** Uma para o Arduino e outra, separada, para a bomba. É super importante usar duas para não sobrecarregar o seu Arduino.
* **1x Vaso com planta:** O herói precisa de alguém para salvar!
* **1x Recipiente com água:** O reservatório de água.
* **1x Pedaço de mangueira:** Para guiar a água da bomba até a planta.
* **Jumpers (fios):** Macho/Macho, Macho/Fêmea e Fêmea/Fêmea para fazer todas as conexões.
* **Fita isolante ou silicone:** Para manter as conexões seguras.

---

### Montando o Quebra-Cabeça (Água)

Siga este guia para conectar tudo. Pense nos jumpers como estradas que levam a energia e a informação de um lugar para o outro.

#### Sensor de Umidade de Solo

Este sensor é o primeiro a entrar em ação. Ele informa ao Arduino se a terra precisa de água.

-   **Pino VCC** do sensor vai para o **pino 5V** do Arduino.
-   **Pino GND** do sensor vai para o **pino GND** do Arduino.
-   **Pino DO** do sensor vai para o **pino D2** (Digital 2) do Arduino.

#### Módulo Relé

Ele é a chave da energia da bomba. O Arduino vai dar o sinal para ele deixar a energia passar ou não.

-   **Pino VCC** do relé vai para o **pino 5V** do Arduino.
-   **Pino GND** do relé vai para o **pino GND** do Arduino.
-   **Pino IN** do relé vai para o **pino D3** (Digital 3) do Arduino.

#### Mini Bomba

É a parte que faz o trabalho pesado!

-   O polo **positivo (+)** da bomba se conecta ao pino **NO** (Normalmente Aberto) do relé.
-   O polo **negativo (-)** da bomba se conecta ao **GND** da fonte de alimentação separada de 5V.
-   O pino **COMUM** do relé se conecta ao **polo positivo (+)** da fonte de alimentação separada de 5V.

> **Atenção:** Lembre-se, a fonte da bomba é separada. Nunca conecte a bomba direto no Arduino!

---

## 2. Luz: O Guardião da Escuridão

Agora vamos para a segunda missão. Imagine ter uma luz que se acende sozinha quando o quarto fica escuro **ou** quando você faz um gesto perto dela! Com este projeto, você vai fazer exatamente isso, com duas formas diferentes de "ligar a mágica".

### O Que Você Vai Precisar (Luz)

* **1x Placa Arduino:** O mesmo cérebro de antes, mas com uma nova missão.
* **3x LEDs:** As luzes do nosso "fogo".
* **3x Resistores de 220 Ohm:** Para proteger seus LEDs.
* **1x Sensor Ultrassônico HC-SR04:** O "radar" que mede a distância.
* **1x Sensor de Luminosidade LDR:** O "olho mágico" que sente a escuridão.
* **2x Resistores de 10k Ohm:** Para a ligação do sensor de luz
* **1x Folha de sulfite:** Para simular uma luminária.
* **Jumpers:** Para conectar tudo.

---

### Montando o Quebra-Cabeça (Luz)

#### LEDs de Fogo

Estes LEDs vão criar o efeito de "fogo" na sua luminária.

-   **LED Vermelho:** Conecte o pino positivo (ânodo) ao pino **D9**. O pino negativo (catodo) vai para o **GND** do Arduino, usando um resistor de 220 Ohm.
-   **LED Amarelo 1:** Conecte o pino positivo (ânodo) ao pino **D10**. O pino negativo (catodo) vai para o **GND** do Arduino, usando um resistor de 220 Ohm.
-   **LED Amarelo 2:** Conecte o pino positivo (ânodo) ao pino **D11**. O pino negativo (catodo) vai para o **GND** do Arduino, usando um resistor de 220 Ohm.

#### Sensor Ultrassônico HC-SR04

Ele será um dos nossos "interruptores".

-   **Pino VCC** do sensor vai para o **pino 5V** do Arduino.
-   **Pino GND** do sensor vai para o **pino GND** do Arduino.
-   **Pino Trig** do sensor vai para o **pino D7** (Digital 7) do Arduino.
-   **Pino Echo** do sensor vai para o **pino D6** (Digital 6) do Arduino.

#### Sensor de Luminosidade LDR

Ele é o nosso "interruptor automático".

-   Conecte um lado do **LDR** ao **pino 5V** do Arduino.
-   Conecte o outro lado do **LDR** ao **Resistor de 10k Ohm**
-   Conecte o **Resistor de 10k Ohm** ao **GND** do Arduino.
-   Usando um jumper, conecte o "meio" da ligação entre o LDR e o resistor ao**pino A0** (Analógico 0) do Arduino.
