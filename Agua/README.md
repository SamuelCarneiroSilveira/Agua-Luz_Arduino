# Agua-Luz_Arduino


## Agua: Sistema de Irrigação Automatizada

Este projeto simples demonstra como usar um Arduino para impedir que sua planta morra de sede. O sistema monitora a umidade do solo e, quando necessário, aciona uma bomba para regar a planta.

Componentes Necessários
* 1x Placa Arduino
* 1x Mini Bomba 5V de Imersão
* 1x Módulo Relé 5V

* 1x Sensor de Umidade de Solo YL-69

* 1x Fonte de Alimentação 5V para o Arduino

* 1x Fonte de Alimentação 5V para a Bomba (importante para evitar danos ao Arduino)

* 1x Vaso com planta

* 1x Recipiente com água

* 1x Pedaço de mangueira (para a bomba)

* Jumpers MM / MF / FF
* Fita isolante ou silicone pra isolar as conexões

---

### Conexões (Água)

As conexões devem ser feitas da seguinte forma:

**Sensor de Umidade de Solo (YL-69)**
O sensor de umidade do solo é a entrada de dados do nosso sistema, ele nos diz se o solo está seco ou úmido.

- Pino VCC do sensor → Pino 5V do Arduino
- Pino GND do sensor → Pino GND do Arduino
- Pino DO do sensor → Pino D2 (Digital 2) do Arduino

**Módulo Relé**
O relé atua como um interruptor eletrônico para a bomba, controlando a passagem de energia.

* Pino VCC do relé → Pino 5V do Arduino
* Pino GND do relé → Pino GND do Arduino
* Pino IN do relé → Pino D3 (Digital 3) do Arduino

**Mini Bomba**
A bomba é o componente que faz a irrigação. A energia dela é controlada pelo relé.

- Polo positivo (+) da bomba → Conecte ao pino NO (Normally Open) do relé.
- Polo negativo (-) da bomba → Conecte ao pino GND da fonte de 5V da bomba.
- Pino COMUM do relé → Conecte ao polo positivo (+) da fonte de 5V da bomba.

Atenção: É crucial usar uma fonte de alimentação separada de 5V para a bomba. A bomba consome mais corrente do que o Arduino pode fornecer, e conectá-la diretamente ao Arduino pode danificar a placa.


Para adicionar um novo capítulo no seu arquivo README para a parte de luz, você pode seguir a mesma estrutura que usamos para o projeto de água. Isso manterá o documento organizado e fácil de ler.

Aqui está o modelo para o capítulo de **Luz**:

---

## Luz: Sistema de Iluminação Automática

Este projeto utiliza um sensor de luminosidade para acender automaticamente uma luz quando o ambiente fica escuro. É ideal para economizar energia e garantir que seu espaço esteja sempre bem iluminado quando necessário.

### Componentes Necessários

* 1x Placa Arduino
* 1x LED
* 1x Resistor de 220 Ohm
* 1x Sensor de Luminosidade LDR
* 1x Módulo Relé 5V
* 1x Lâmpada 110V/220V (ou fita de LED 5V)
* 1x Fonte de Alimentação
* Jumpers MM / MF / FF
* Fita isolante ou silicone para isolar as conexões

---

### Conexões (Luz)

As conexões devem ser feitas da seguinte forma:

#### Sensor de Luminosidade LDR

O LDR (Light Dependent Resistor) é o componente que detecta a quantidade de luz no ambiente.

* **Pino de um lado do LDR** → Conecte ao **pino 5V do Arduino**.
* **Pino do outro lado do LDR** → Conecte ao **pino A0 (Analógico 0) do Arduino**.
* **Resistor de 220 Ohm** → Conecte o resistor entre o pino do LDR que está ligado ao pino A0 e o **GND do Arduino**.

#### LED

O LED será usado para testar a lógica do programa.

* **Pino Anodo (o mais longo) do LED** → Conecte ao **pino D13 (Digital 13) do Arduino**.
* **Pino Catodo (o mais curto) do LED** → Conecte ao **pino GND do Arduino**.

#### Módulo Relé

O relé irá controlar a lâmpada.

* **Pino VCC do relé** → Conecte ao **pino 5V do Arduino**.
* **Pino GND do relé** → Conecte ao **pino GND do Arduino**.
* **Pino IN do relé** → Conecte ao **pino D12 (Digital 12) do Arduino**.

#### Lâmpada (ou fita de LED)

* **Pino COMUM do relé** → Conecte a um dos fios da sua fonte de alimentação (se for AC, um dos fios da tomada).
* **Pino NO (Normally Open) do relé** → Conecte ao **polo positivo (+) da sua lâmpada ou fita de LED**.
* **Polo negativo (-) da lâmpada ou fita de LED** → Conecte ao outro fio da sua fonte de alimentação.

**Atenção:** Se você estiver trabalhando com tensões de 110V/220V, **tome muito cuidado** e isole todas as conexões para evitar curtos-circuitos ou choques elétricos. Se possível, use uma fita de LED com 5V para maior segurança.

---
