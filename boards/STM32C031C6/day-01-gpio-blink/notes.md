# Day 01 – LED Blink Notes
- https://wokwi.com/projects/453574163047148545
## What I Learned
- GPIO output configuration using STM32CubeMX
- HAL GPIO APIs
- Blocking delay using `HAL_Delay()`

## Observations
- `HAL_Delay()` blocks the main loop
- GPIO configuration is auto-generated via `.ioc`

## Differences Between Wokwi & CubeIDE
- Wokwi uses simplified `main.c`
- CubeIDE project includes startup code, linker script, and HAL drivers

## Issues Faced
- Initial confusion between simulation and real project structure

## Improvements / Next Steps
- Use timer interrupt instead of blocking delay
- Test on physical hardware

## Youtube Tutorial Link I followed:
- https://www.youtube.com/watch?v=8RNwh1qW1Qg&list=PLjRK6WMJhWom_IswjovnIhhi4rJcDYBgU&index=8
