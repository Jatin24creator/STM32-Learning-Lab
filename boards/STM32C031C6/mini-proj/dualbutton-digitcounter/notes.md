# Mini Project 02 – Dual Push Button Based 7-Segment Digit Counter

- Wokwi Project Link: https://wokwi.com/projects/454320221095241729

---

## General
- **Board:** STM32C031C6  
- **Components Used:**
  - Push Buttons
  - STM32 Dev Board
  - Single Digit 7-Segment Display (Common Anode)
  - 10kΩ Resistor

---

## Objective
- Implement a **push button–based digit counter (0–9)**
- Increment and Decrement digit on every button press via 2 buttons
- Wrap around from `9 → 0` and vice versa

---

## Pin Configuration

### Input
| Pin | Mode | Purpose |
|---|---|---|
| GPIOA Pin 5 | GPIO Input (Pull-up) | Push Button |
| GPIOA Pin 6 | GPIO Input (Pull-up) | Push Button |


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

---

## Logic Implemented
- Button state is continuously polled inside the main loop
- Debounce with delay()
- Button 1 Press ==
- On valid button press:
  - Digit increments by `1`
  - If digit exceeds `9`, it resets to `0`
- Display update handled using a dedicated function:
  - `counter(int digit_count)`
- Previous digit is cleared before displaying the new one to avoid segment overlap
- Button 2 Press ==
On valid button press:
  - Digit decrements by `1`
  - If digit less than `0`, it resets to `9`
- Display update handled using a dedicated function:
  - `counter(int digit_count)`
- Previous digit is cleared before displaying the new one to avoid segment overlap

---

## Observations
- Without clearing all segments first, the display eventually showed `8` (all segments ON)
- Button press must be detected as an **event**, not as a continuous level
- GPIO inputs must have a **defined reference** (pull-up or pull-down) to avoid floating behavior

---

## Issues Faced
- Logic missed on setting things up

---

## Lessons Learned
- Always verify **hardware connections** before assuming software bugs
- GPIO inputs must never be left floating
- Button handling requires:
  - Proper pull-up / pull-down
  - Debounce logic
  - Clear distinction between press and hold
- Embedded systems debugging involves **both hardware and software**

---

## Improvements / Next Steps
- Implement non-blocking debounce logic (without `HAL_Delay`)
- Add long-press detection to reset digit to `0`
- Refactor digit logic using lookup tables
- Extend project to:
  - ADC-controlled digit display
  - Multi-digit 7-segment multiplexing

---
