# Mini Project 04 - Multi Mode Input Display

- Wokwi Project Link: 

---

## General
- **Board:** STM32C031C6  
- **Components Used:**
  - Potentiometer
  - Push Buttons
  - LED
  - STM32 Dev Board
  - Single Digit 7-Segment Display (Common Anode)

---

## Objective
- adc threshold display 0-4 LED OFF && 5-9 LED ON
- Button toggles **display mode**
- Mode 0 → Button counter
- Mode 1 → ADC digit display
- LED shows current mode
- Wrap around from `9 → 0` and vice versa
- 

---

## Pin Configuration

### Input
| Pin | Mode | Purpose |
|---|---|---|
| GPIOA Pin 0 | GPIO Input (Pull-up) | Potentiometer |
| GPIOA Pin 3 | GPIO Input (Pull-up) | Mode Button |
| GPIOA Pin 4 | GPIO Input (Pull-up) | Button to Digit ++ |
| GPIOA Pin 5 | GPIO Input (Pull-up) | Button to Digit -- |



### Output
| Pin | Mode | Purpose |
|---|---|---|
| GPIOB Pins 0–7 | GPIO Output | 7-Segment Display (Segments A–G, DP) |
| GPIOA Pin 6 | GPIO Input (Pull-up) | LED |
| GPIOA Pin 7 | GPIO Input (Pull-up) | LED |

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