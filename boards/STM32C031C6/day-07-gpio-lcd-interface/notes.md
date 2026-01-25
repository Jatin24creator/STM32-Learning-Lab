# Day 06 – 7 Segment Display Interfacing (Common Anode)

- Wokwi Project: https://wokwi.com/projects/454142242007231489

## What I Learned
- Interfacing a **single-digit 7-segment display** with STM32 GPIO
- Difference between **Common Anode** and **Common Cathode** displays
- Mapping GPIO pins to 7-segment segments (A–G, DP)
- Displaying digits (0–9) using GPIO SET and RESET logic
- Using macros to simplify segment control logic

---

## 7-Segment Display Type Used
- **Type:** Common Anode
- **Logic:**
  - Segment ON  → GPIO **RESET (0)**
  - Segment OFF → GPIO **SET (1)**

---

## 7-Segment Pin Mapping (Common Anode)

| Display Pin | GPIO Pin Number | Segment |
|-----------|------------------|---------|
| 1 | PB4 | Segment E |
| 2 | PB3 | Segment D |
| 3 | GND | Common Anode |
| 4 | PB2 | Segment C |
| 5 | PB7 | Segment DP |
| 6 | PB1 | Segment B |
| 7 | PB0 | Segment A |
| 8 | GND | Common Anode |
| 9 | PB5 | Segment F |
| 10 | PB6 | Segment G |

---

## Common Anode SET / RESET Truth Table

| Digit | A | B | C | D | E | F | G | DP |
|------|---|---|---|---|---|---|---|----|
| 0 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | 0 |
| 1 | 0 | 1 | 1 | 0 | 0 | 0 | 0 | 0 |
| 2 | 1 | 1 | 0 | 1 | 1 | 0 | 1 | 0 |
| 3 | 1 | 1 | 1 | 1 | 0 | 0 | 1 | 0 |
| 4 | 0 | 1 | 1 | 0 | 0 | 1 | 1 | 0 |
| 5 | 1 | 0 | 1 | 1 | 0 | 1 | 1 | 0 |
| 6 | 1 | 0 | 1 | 1 | 1 | 1 | 1 | 0 |
| 7 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 |
| 8 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 |
| 9 | 1 | 1 | 1 | 1 | 0 | 1 | 1 | 0 |

> **Note:**  
> `1` → Segment OFF (GPIO SET)  
> `0` → Segment ON (GPIO RESET)

---

## Code Logic Used
- Each digit is defined using two macros:
  - `DxS` → Segments to SET (turn OFF)
  - `DxR` → Segments to RESET (turn ON)
- Digits `0–9` are displayed sequentially using `HAL_Delay(1000)`
- All segment pins are connected to **GPIOB (PB0–PB7)**

Example:
```c
HAL_GPIO_WritePin(GPIOB, D0S, GPIO_PIN_SET);
HAL_GPIO_WritePin(GPIOB, D0R, GPIO_PIN_RESET);
