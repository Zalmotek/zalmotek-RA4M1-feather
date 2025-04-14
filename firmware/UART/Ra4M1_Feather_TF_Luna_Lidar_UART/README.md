# Zalmotek RA4M1 Feather TF Luna Lidar UART

A UART-based communication solution for the TF Luna Lidar sensor using Zalmotek's RA4M1 Feather board powered by Renesas technology.

## Overview

This project demonstrates UART communication between the Zalmotek RA4M1 Feather board and a TF Luna Lidar distance sensor. It reads distance and signal strength data from the sensor via UART interface and outputs the readings to the debug console.

## Hardware Requirements

- Zalmotek RA4M1 Feather board 
- TF Luna Lidar sensor
- Jumper wires for connections

## Software Requirements

- Renesas e² studio
- FSP (Flexible Software Package)
- J-Link debugger

## Features

- UART communication with TF Luna Lidar sensor
- Distance measurement in centimeters
- Signal strength monitoring
- Serial output for debugging

## Code Functionality

The main application:
- Initializes UART communication with the TF Luna Lidar sensor
- Continuously reads 9-byte data packets from the sensor
- Parses distance and signal strength values
- Outputs readings to the debug console
- Operates in a continuous loop with 10ms delay between readings

## Getting Started

### Setup

1. Connect the TF Luna Lidar sensor to the RA4M1 Feather board's UART pins
2. Open the project in Renesas e² studio
3. Build the project
4. Flash the program to the RA4M1 Feather board
5. Open a terminal to view the debug output

### Configuration

The UART is configured for communication with the TF Luna Lidar sensor:

```c
// Example of reading TF Luna data
err = R_SCI_UART_Read(&g_uart0_ctrl, buf, BUF_SIZE);
if (FSP_SUCCESS == err && buf[0] == 0x59 && buf[1] == 0x59) {
    distance = (uint16_t)(buf[2] + buf[3] * 256);
    strength = (uint16_t)(buf[4] + buf[5] * 256);
}
```

## Project Structure

- `src/hal_entry.cpp`: Main application code with UART communication and sensor data processing
- `src/SerialCompatibility.cpp/.h`: Serial communication utility functions
- `src/common_utils.h`: Common utility functions and definitions
- `src/SEGGER_RTT/`: Debug output functionality

## License

[License information]

## Additional Resources

- [Zalmotek Website](https://zalmotek.com)
- [Zalmotek RA4M1 Website](https://zalmotek.com/products/RA4M1-Feather-SoM/)
- [SEGGER RTT Documentation](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/) 
