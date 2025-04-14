# Zalmotek RA4M1 Feather USB Serial

A USB-Serial communication example for the Zalmotek RA4M1 Feather board powered by Renesas RA4M1 microcontroller.

## Overview

This project demonstrates how to implement USB CDC (Communications Device Class) Serial communication on the Zalmotek RA4M1 Feather board. It allows bidirectional communication between the board and a computer through a virtual COM port, utilizing the Renesas RA4M1 USB peripheral.

## Hardware Requirements

- Zalmotek RA4M1 Feather board 
- USB-C cable for connection to computer
- Computer with USB port

## Software Requirements

- e² studio IDE
- Renesas FSP (Flexible Software Package)
- USB CDC driver (automatically installed on most operating systems)
- Terminal application (e.g., PuTTY, TeraTerm, or Serial Monitor)

## Features

- USB CDC Serial communication implementation
- Simple command parsing and response
- Automatic board detection as a virtual COM port
- Low-latency data transmission and reception

## Code Functionality

The main application:
- Initializes the USB peripheral for CDC operation
- Sets up internal buffers for data transmission and reception
- Implements handlers for USB events and data processing
- Operates in a continuous loop monitoring for incoming data
- Processes received commands and sends appropriate responses

## Getting Started

### Setup

1. Connect the Zalmotek RA4M1 Feather board to your computer using a USB-C cable
2. Open the project in e² studio IDE
3. Build and flash the firmware to the board
4. The board will enumerate as a virtual COM port on your computer
5. Open a terminal application and connect to the assigned COM port

### Configuration

Terminal configuration parameters:

- Baud rate: 115200 (note: virtual COM ports don't actually require specific baud rates)
- Data bits: 8
- Parity: None
- Stop bits: 1
- Flow control: None

## Project Structure

- `src/`: Contains all source code files
- `src/hal_entry.c`: Main application entry point and USB handling logic
- `.settings/`: Project settings for e² studio
- `script/`: Build and configuration scripts
- `configuration.xml`: Renesas FSP configuration file

## License

Proprietary - Zalmotek, all rights reserved

## Additional Resources

- [Zalmotek Website](https://zalmotek.com)
- [Zalmotek RA4M1 Website](https://zalmotek.com/products/RA4M1-Feather-SoM/)
- [SEGGER RTT Documentation](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/) 