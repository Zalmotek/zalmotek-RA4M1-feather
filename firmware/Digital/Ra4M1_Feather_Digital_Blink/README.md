# Zalmotek RA4M1 Feather Digital Blink

A digital pin blink demonstration for the Zalmotek RA4M1 Feather board powered by Renesas RA4M1 microcontroller.

## Overview

This project implements a multi-pin LED blinking application for the Zalmotek RA4M1 Feather board featuring Renesas RA4M1 microcontroller. It demonstrates how to control multiple digital pins (D5, D6, D9, D10, D11, D12, and D13) using timer-based interrupts to create a blinking pattern.

## Hardware Requirements

- Zalmotek RA4M1 Feather board 
- LEDs connected to pins D5, D6, D9, D10, D11, D12, and D13 (or use on-board LED)
- USB cable for programming and power

## Software Requirements

- Renesas e² studio IDE
- Renesas FSP (Flexible Software Package)
- J-Link debugger software
- Git (optional, for version control)

## Features

- Timer-based interrupt-driven pin toggling
- Multiple pin control from a single timer
- Debug output via SEGGER RTT
- Low power consumption using efficient timer interrupts

## Code Functionality

The main application:
- Initializes the AGT timer for interrupt generation
- Controls pins D5, D6, D9, D10, D11, D12, and D13 (BSP_IO_PORT_01_PIN_03, BSP_IO_PORT_01_PIN_04, BSP_IO_PORT_01_PIN_05, BSP_IO_PORT_01_PIN_02, BSP_IO_PORT_01_PIN_06, BSP_IO_PORT_01_PIN_07, BSP_IO_PORT_01_PIN_12)
- Toggles pin states on each timer interrupt
- Outputs pin state changes via SEGGER RTT for debugging
- Uses a timer interrupt callback to handle all pin state changes

## Getting Started

### Setup

1. Clone or download this repository
2. Import the project into e² studio
3. Connect the Zalmotek RA4M1 Feather board to your computer
4. Build the project
5. Flash the program to your board using the J-Link debugger

### Configuration

The pin definitions and timer configuration can be modified in the source code:

```c
// Array of pins to toggle
const bsp_io_port_pin_t pins[] = {
    BSP_IO_PORT_01_PIN_03, // D5
    BSP_IO_PORT_01_PIN_04, // D6
    BSP_IO_PORT_01_PIN_05, // D9
    BSP_IO_PORT_01_PIN_02, // D10
    BSP_IO_PORT_01_PIN_06, // D11
    BSP_IO_PORT_01_PIN_07, // D12
    BSP_IO_PORT_01_PIN_12  // D13
};
```

## Project Structure

- `src/hal_entry.cpp`: Main application code containing pin definitions and timer callback
- `src/common_utils.h`: Utility functions for debugging and common operations
- `src/SEGGER_RTT/`: SEGGER RTT implementation for debugging output
- `configuration.xml`: FSP configuration file for the project

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Additional Resources

- [Zalmotek Website](https://zalmotek.com)
- [Zalmotek RA4M1 Website](https://zalmotek.com/products/RA4M1-Feather-SoM/)
- [SEGGER RTT Documentation](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/) 
