# Zalmotek RA4M1 Feather Blink

A simple LED blinking example for the Zalmotek RA4M1 Feather board, demonstrating basic GPIO control using Renesas RA4M1 microcontroller.

## Overview

This project demonstrates basic LED control on the Zalmotek RA4M1 Feather board, featuring the Renesas RA4M1 microcontroller. The example blinks the onboard LED connected to pin P400 (LED_BUILTIN) at a regular interval, showcasing fundamental GPIO configuration and timing control.

## Hardware Requirements

- Zalmotek RA4M1 Feather board
- USB Type-C cable for programming and power

## Software Requirements

- Renesas e² studio IDE
- RA4M1 FSP (Flexible Software Package)
- GCC ARM Embedded Toolchain

## Features

- Simple LED blinking demonstration
- Configurable blink interval
- Uses onboard LED (P400)
- Demonstrates basic GPIO configuration

## Code Functionality

The main application:
- Initializes the system clock and GPIO pins
- Configures P400 (LED_BUILTIN) as an output
- Implements a simple delay-based blinking pattern
- Toggles the LED state at regular intervals

## Getting Started

### Setup

1. Install Renesas e² studio IDE
2. Install RA4M1 FSP package
3. Clone this repository
4. Open the project in e² studio
5. Build and flash the project to your RA4M1 Feather board

### Configuration

```c
// LED configuration
#define LED_PIN    BSP_IO_PORT_04_PIN_00  // P400
#define LED_ON     BSP_IO_LEVEL_HIGH
#define LED_OFF    BSP_IO_LEVEL_LOW

// Blink timing configuration
#define BLINK_DELAY_MS 500
```

## Project Structure

- `src/`: Contains the main application source files
- `ra/`: Contains Renesas FSP configuration files
- `ra_gen/`: Contains generated FSP code
- `script/`: Contains build and flash scripts

## License

This project is licensed under the MIT License.

## Additional Resources

- [Zalmotek Website](https://zalmotek.com)
- [Zalmotek RA4M1 Website](https://zalmotek.com/products/RA4M1-Feather-SoM/)
- [SEGGER RTT Documentation](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/) 