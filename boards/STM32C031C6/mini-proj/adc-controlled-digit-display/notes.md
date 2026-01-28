# Mini Project 03 - ADC Controlled Digit Display

- Wokwi Project Link: https://wokwi.com/projects/454398826584437761

---

## General
- **Board:** STM32C031C6  
- **Components Used:**
  - Potentiometer
  - STM32 Dev Board
  - Single Digit 7-Segment Display (Common Anode)

---

## Objective
- Implement a **adc-controlled digit counter (0–9)**
- Increment and Decrement digit with pot
- Wrap around from `9 → 0` and vice versa

---

## Pin Configuration

### Input
| Pin | Mode | Purpose |
|---|---|---|
| GPIOA Pin 0 | GPIO Input (Pull-up) | Potentiometer |


### Output
| Pin | Mode | Purpose |
|---|---|---|
| GPIOB Pins 0–7 | GPIO Output | 7-Segment Display (Segments A–G, DP) |

---

## 7-Segment Display Details
- **Type:** Common Anode
- **Logic Used:**
  - `GPIO_PIN_RESET` → Segment ON
  - `GPIO_PIN_SET` → Segment OFF
- Segment control implemented using **macros** for each digit (`D0S/D0R … D9S/D9R`)

**Concept:** Analog → Digital mapping

### Objective

- Use a potentiometer (ADC)
- Display digits **0–9** on 7-segment based on ADC value

### Learning

- ADC polling
- Threshold mapping
- 7-segment digit logic
- Clearing + updating display

### Behavior

| ADC Range | Display |
| --- | --- |
| 0–409 | 0 |
| 410–819 | 1 |
| … | … |
| 3686–4095 | 9 |

### Constraints

❌ No UART

❌ No interrupts

❌ No timers