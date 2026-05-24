# PIC-Embedded-Drivers

Embedded Systems Drivers Library developed in Embedded C for PIC Microcontrollers using a layered architecture consisting of MCAL, HAL, Services, and Application layers.

![Language](https://img.shields.io/badge/Language-C-blue)
![Platform](https://img.shields.io/badge/Platform-PIC_Microcontroller-green)
![Architecture](https://img.shields.io/badge/Architecture-Layered-orange)

---

## Overview

ES-Drivers is a collection of reusable embedded drivers implemented for PIC microcontrollers. The project follows a modular layered architecture that separates hardware-specific drivers from application logic, improving portability, scalability, and maintainability.

---

## Architecture

```text
APP
│
├── SERVICES
│
├── HAL
│
└── MCAL
```

### MCAL (Microcontroller Abstraction Layer)

Low-level drivers directly interacting with PIC registers.

Implemented drivers:

- GPIO
- Interrupt
- Timer0
- Timer1
- Timer2
- CCP/PWM
- ADC
- UART
- SPI
- I2C

### HAL (Hardware Abstraction Layer)

Hardware peripherals built on top of MCAL drivers.

Examples:

- LED
- Push Button
- LCD
- Seven Segment Display
- Keypad
- Buzzer

### Services Layer

Reusable middleware and utility modules.

Examples:

- Scheduler
- Delay Services
- Communication Services

### Application Layer

Example applications demonstrating usage of drivers and modules.

---

## Project Structure

```text
ES-Drivers
│
├── APP/
├── SERVICES/
├── HAL/
├── MCAL/
└── README.md
```

---

## Development Environment

- Microcontroller: PIC16F877A / PIC18FXXXX
- Language: Embedded C
- Compiler: XC8
- IDE: MPLAB X IDE

---

## Features

- Layered architecture
- Modular design
- Reusable drivers
- Easy integration into embedded projects
- Hardware abstraction
- Scalable structure

---

## Author

Abdelhady Mostafa

Communication and Information Engineering
Zewail City of Science and Technology
