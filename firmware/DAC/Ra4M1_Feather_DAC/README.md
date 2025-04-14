# Zalmotek Ra4M1 Feather DAC

Digital-to-Analog Converter (DAC) demonstration for the Zalmotek Ra4M1 Feather board powered by Renesas RA4M1.

## Overview

This project demonstrates the DAC module functionality on the Zalmotek Ra4M1 Feather board using Renesas RA4M1 microcontroller. Users can enter DAC values within the range of 1-4095, and the converted analog output is fed back to an ADC channel for verification. Results are displayed via SEGGER RTT Viewer.

## Hardware Requirements

- Zalmotek Ra4M1 Feather
- J-Link debugger/programmer
- USB cable
- Computer with J-Link software installed

## Software Requirements

- Renesas e² studio IDE
- SEGGER J-Link software
- SEGGER RTT Viewer
- FSP (Flexible Software Package)

## Features

- DAC output generation with 12-bit resolution (1-4095)
- ADC input reading for verification
- Real-time feedback via SEGGER RTT Viewer
- User-controlled value input via console

## Code Functionality

The main application:
- Initializes DAC and ADC modules
- Configures analog pins for DAC output and ADC input
- Handles user input from SEGGER RTT Viewer
- Validates input within permitted range (1-4095)
- Performs DAC conversion and subsequent ADC reading
- Displays the ADC read value for verification

## Getting Started

### Setup

1. Connect your Zalmotek Ra4M1 Feather board to your computer via USB
2. Open e² studio and import the project
3. Build the project
4. Flash the binary to the Ra4M1 Feather board
5. Open SEGGER RTT Viewer to interact with the application

### Configuration

User can input DAC values through SEGGER RTT Viewer:

```c
// Enter values for DAC conversion between 1 and 4095
// Example: entering 2048 will set DAC output to approximately mid-range voltage
```

## Project Structure

- `src/hal_entry.c`: Main application code with DAC and ADC functionality
- `src/dac_ep.h`: DAC endpoint declarations and configuration macros
- `src/common_utils.h`: Utility functions and RTT interface
- `src/SEGGER_RTT/`: SEGGER RTT implementation files

## License

BSD-3-Clause

## Additional Resources

- [Zalmotek Website](https://zalmotek.com)
- [Zalmotek RA4M1 Website](https://zalmotek.com/products/RA4M1-Feather-SoM/)
- [SEGGER RTT Documentation](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/) 
