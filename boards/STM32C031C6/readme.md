# STM32C031C6 Board – Overview

The **STM32C031C6** is a low-cost, entry-level 32-bit microcontroller from STMicroelectronics based on the **ARM Cortex-M0+** core. It is designed for learning embedded systems, simple control applications, and low-power designs while still providing the flexibility of the STM32 ecosystem.

This board is commonly used with **STM32CubeIDE** and supports rapid development through auto-generated HAL drivers and graphical configuration via `.ioc` files.

---

## Key Features
- **Core:** ARM Cortex-M0+ (up to 48 MHz)
- **Flash Memory:** 32 KB
- **SRAM:** 12 KB
- **Operating Voltage:** 2.0 V – 3.6 V
- **GPIO Pins:** Multiple configurable GPIOs with interrupt capability
- **Timers:** General-purpose timers and basic timers
- **Communication Interfaces:**
  - UART
  - SPI
  - I²C
- **ADC:** 12-bit ADC for analog input
- **Clock Sources:**
  - Internal HSI / HSI48 oscillator
  - External HSE crystal support

---

## Development Environment
- **IDE:** STM32CubeIDE
- **Configuration Tool:** STM32CubeMX (integrated)
- **Programming & Debugging:** ST-LINK (via NUCLEO board)
- **Simulation:** Wokwi (for basic GPIO logic)

---

## Why STM32C031C6?
- Beginner-friendly STM32 microcontroller
- Simple architecture with professional-grade tools
- Ideal for learning:
  - GPIO
  - Timers
  - Interrupts
  - Clock configuration
  - HAL-based embedded development
- Low power and low cost for real-world applications

---

## Typical Use Cases
- LED and push-button projects
- Embedded systems learning
- Sensor interfacing
- Low-power control systems
- IoT edge devices (with external modules)

---

## Notes
- GPIO and peripheral initialization is auto-generated using `.ioc`
- User application code should be written only inside `USER CODE` sections
- Clock configuration directly affects timing, delays, and peripheral behavior

---

## Repository Purpose
This repository documents hands-on learning and experiments with the **STM32C031C6**, including:
- GPIO control
- Button handling
- Polling vs interrupts
- Real hardware testing and simulations

---
