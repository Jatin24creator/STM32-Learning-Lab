# Mini Project 01 – Push Button Based 7-Segment Digit Counter

- Wokwi Project Link: https://wokwi.com/projects/454149214076572673

---

## General
- **Board:** STM32C031C6  
- **Components Used:**
  - Push Button
  - STM32 Dev Board
  - Single Digit 7-Segment Display (Common Anode)
  - 10kΩ Resistor

---

## Objective
- Implement a **push button–based digit counter (0–9)**
- Increment digit on every button press
- Wrap around from `9 → 0`
- **Bonus:** Hold button to reset digit to `0`

---

## Pin Configuration

### Input
| Pin | Mode | Purpose |
|---|---|---|
| GPIOA Pin 6 | GPIO Input (Pull-up) | Push Button |

### Output
| Pin | Mode | Purpose |
|---|---|---|
| GPIOA Pin 7 | GPIO Output | Status LED |
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
- On valid button press:
  - Digit increments by `1`
  - If digit exceeds `9`, it resets to `0`
- Display update handled using a dedicated function:
  - `display_digit(int current_digit)`
- Previous digit is cleared before displaying the new one to avoid segment overlap

---

## Observations
- Without clearing all segments first, the display eventually showed `8` (all segments ON)
- Button press must be detected as an **event**, not as a continuous level
- GPIO inputs must have a **defined reference** (pull-up or pull-down) to avoid floating behavior

---

## Issues Faced
- Display getting stuck at certain digits (`0`, `8`, `1`)
- Button not behaving as expected even though code logic was correct

---

## Root Cause
- **Incorrect push button wiring** caused the GPIO pin to stay in a constant state
- Floating input led to unpredictable behavior
- Software logic was correct; the issue was purely **hardware-related**

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
