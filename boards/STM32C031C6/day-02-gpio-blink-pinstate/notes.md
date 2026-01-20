# Day 02 – GPIO Pin State Control Notes

- https://wokwi.com/projects/453639341552472065
## Key Learnings
- GPIO output can be controlled explicitly using `HAL_GPIO_WritePin()`
- `GPIO_PinState` has two valid states:
  - `GPIO_PIN_SET`
  - `GPIO_PIN_RESET`
- Explicit pin control improves readability compared to toggling blindly

## HAL APIs Used
- `HAL_GPIO_WritePin()`
- `HAL_Delay()`

## Difference from Day 01
- Day 01 used basic toggling
- Day 02 focuses on **explicit pin state control**
- Clear ON/OFF logic instead of implicit state change

## Observations
- `HAL_Delay()` is blocking and halts the CPU
- Increasing delay slows LED blink rate
- Very small delays make blinking appear constant

## Simulation vs Firmware
- Wokwi uses a simplified environment
- STM32CubeIDE project includes full HAL, startup, and linker setup
- Logic remains conceptually identical

## Issues Faced
- Understanding when to use SET/RESET vs TOGGLE
- Realizing delay affects CPU execution flow

## Improvements / Ideas
- Use hardware timer instead of `HAL_Delay()`
- Toggle pin based on a state variable
- Implement button-controlled pin state
## Youtube Tutorial Link I followed:
- https://www.youtube.com/watch?v=3vHNdgwgCWE&list=PLjRK6WMJhWom_IswjovnIhhi4rJcDYBgU&index=7
- https://wokwi.com/projects/453639341552472065