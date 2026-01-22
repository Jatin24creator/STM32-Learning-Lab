# Day 04 – ADC Based LED Control (Polling)

- https://wokwi.com/projects/453736605841302529

## What I Learned
- Basics of ADC (Analog-to-Digital Converter) in STM32
- Understanding 12-bit ADC resolution (0–4095 digital range)
- Starting and stopping ADC using HAL APIs
- Using `HAL_ADC_PollForConversion()` to wait for ADC conversion
- Controlling an LED based on analog input threshold

## Observations
- ADC conversion returns a digital value proportional to input voltage
- Mid-scale value (~2048) represents half of the reference voltage
- LED turns ON or OFF based on comparison with threshold
- ADC polling is a blocking operation inside the main loop

## Differences Between Wokwi & CubeIDE
- Wokwi provides virtual potentiometer for easy analog input testing
- CubeIDE requires proper ADC pin configuration and channel selection
- ADC initialization and clock configuration are auto-generated in CubeIDE
- Real hardware requires stable reference voltage and proper wiring

## Issues Faced
- Understanding ADC resolution and digital value range
- Knowing when to start and stop ADC conversion
- Selecting the correct ADC channel for the input pin

## Improvements / Next Steps
- Replace polling with ADC interrupt or DMA
- Map ADC value to LED brightness using PWM
- Print ADC values over UART for debugging
- Test ADC behavior on physical hardware

## Youtube Tutorial Link I followed:
- https://www.youtube.com/watch?v=xS4kvsU7ajw&list=PLjRK6WMJhWom_IswjovnIhhi4rJcDYBgU&index=6
