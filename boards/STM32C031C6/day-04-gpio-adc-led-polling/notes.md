# Day 05 – Multi-Channel ADC Debugging & Learning (STM32)

- https://wokwi.com/projects/453851267401373697

## What I Learned
- How to read multiple ADC channels using STM32 HAL
- Difference between **ADC scan mode** and **single conversion mode**
- Proper way to switch ADC channels manually at runtime
- Importance of correct ADC configuration parameters (`Rank`, `SamplingTime`)
- How ADC misconfiguration can lead to silent and confusing bugs

## Observations
- ADC works reliably only when its configuration model is consistent
- STM32 HAL does not throw errors for logical ADC misconfigurations
- Both channels appeared to give incorrect or identical readings when configured incorrectly
- Stopping the ADC before reconfiguring the channel is mandatory

## Mistake That Was Made (Important Lesson)
- **ADC scan sequence mode was enabled** (`ADC_SCAN_SEQ_FIXED`)
- **Number of conversions was set to 1**, which contradicts scan mode behavior
- ADC channels were being **reconfigured dynamically inside the main loop**
- Incorrect ADC rank (`ADC_RANK_CHANNEL_NUMBER`) was used instead of `ADC_REGULAR_RANK_1`
- Sampling time was not explicitly set during channel reconfiguration

➡️ This resulted in undefined ADC behavior and incorrect readings.

## Correct Approach Identified
- Use **single conversion mode** when switching channels manually
- Disable scan sequencing when only one channel is converted at a time
- Configure ADC channels completely each time:
  - Channel
  - Rank
  - Sampling time
- Stop ADC before changing channel configuration

## Differences Between Working & Non-Working Implementation
- Working code used **manual channel switching with single conversion**
- Non-working code mixed **scan mode with dynamic channel reconfiguration**
- Proper rank and sampling time were explicitly set in the working version
- ADC initialization and runtime behavior were aligned in the working code

## Improvements / Next Steps
- Implement proper ADC scan mode with multiple conversions
- Explore ADC + DMA for efficient multi-channel sampling
- Add UART prints for ADC values to improve debugging
- Document ADC usage patterns clearly for future reference

## Youtube Tutorial Link I followed:
- https://www.youtube.com/watch?v=JIhZT1gDP4Q&list=PLjRK6WMJhWom_IswjovnIhhi4rJcDYBgU&index=5
