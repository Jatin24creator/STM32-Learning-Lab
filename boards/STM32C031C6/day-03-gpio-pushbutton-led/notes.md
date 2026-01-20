# Day 03 – Push Button Controlled LED (Polling)

- https://wokwi.com/projects/453643324273985537

## What I Learned
- GPIO input configuration for push button using STM32CubeMX
- Reading digital input using `HAL_GPIO_ReadPin()`
- Controlling LED using `HAL_GPIO_WritePin()`
- Using `if–else` logic inside the infinite `while(1)` loop
- Understanding polling-based input handling

## Observations
- LED remains ON only while the push button is pressed
- Button state is checked continuously in the main loop
- No delay is required for this logic
- This method directly reflects real-time pin state

## Differences Between Wokwi & CubeIDE
- Wokwi allows quick visual simulation of button press
- CubeIDE requires proper pin mapping and hardware configuration
- CubeIDE auto-generates GPIO initialization code via `.ioc`
- Real hardware may require pull-up or pull-down resistors

## Issues Faced
- Confusion between `TogglePin` and `WritePin`
- Understanding why the LED does not “toggle” but follows button state
- Correctly identifying input vs output GPIO pins

## Improvements / Next Steps
- Implement LED toggle on button press (edge detection)
- Add debounce logic (software or hardware)
- Use EXTI interrupt instead of polling
- Test behavior on physical NUCLEO board

## Youtube Tutorial Link I followed:
- https://www.youtube.com/watch?v=xS4kvsU7ajw&list=PLjRK6WMJhWom_IswjovnIhhi4rJcDYBgU&index=6
