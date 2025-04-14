# Zalmotek RA4M1 Feather SPI MAX31723

Temperature measurement project using Zalmotek RA4M1 Feather board with Renesas RA4M1 microcontroller and MAX31723 temperature sensor.

## Overview

This project demonstrates SPI communication between a Zalmotek RA4M1 Feather board and a MAX31723 temperature sensor. The temperature readings are continuously displayed through the USB console interface. It utilizes Zalmotek hardware with Renesas RA4M1 microcontroller technology.

## Hardware Requirements

- Zalmotek RA4M1 Feather board
- MAX31723 temperature sensor
- Connection wires

## Software Requirements

- e² studio IDE
- Renesas FSP
- J-Link debugger

## Features

- SPI communication with MAX31723 temperature sensor
- Temperature readings in Celsius
- USB CDC interface for data output
- 12-bit resolution temperature measurements

## Code Functionality

The main application:
- Initializes SPI communication with the MAX31723 temperature sensor
- Configures the MAX31723 for 12-bit resolution readings
- Sets up USB CDC interface for data output
- Continuously polls temperature values at regular intervals
- Outputs formatted temperature data to the console

## Getting Started

### Setup

1. Connect the MAX31723 temperature sensor to the Zalmotek RA4M1 Feather board (CS pin on P102)
2. Connect the board to your computer via USB
3. Open the project in e² studio
4. Build and flash the project to the board
5. Open a terminal program to view the temperature readings

### Configuration

The MAX31723 sensor is configured with 12-bit resolution:

```c
const uint8_t config_sensor[3] = {0x80, 0x06};
```

## Project Structure

- `src/`: Main source code directory
- `src/hal_entry.c`: Application entry point and main logic
- `src/spi_max31723.h`: SPI communication with MAX31723 sensor
- `src/usb_uart.h`: USB CDC interface for console output

## License

Proprietary - Zalmotek

## Additional Resources

- [Zalmotek Website](https://zalmotek.com)
- [Zalmotek RA4M1 Website](https://zalmotek.com/products/RA4M1-Feather-SoM/)
- [SEGGER RTT Documentation](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/) 