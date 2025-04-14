# Zalmotek RA4M1 Feather IIC MASTER ADXL345

A Zalmotek accelerometer sensor interface project powered by Renesas RA4M1 microcontroller using I2C communication.

## Overview

This project demonstrates I2C communication between a Renesas RA4M1 microcontroller and an ADXL345 accelerometer sensor. It initializes the I2C master interface, communicates with the sensor to read X, Y, and Z-axis acceleration data, and outputs the readings over USB serial.

## Hardware Requirements

- Zalmotek RA4M1 Feather board 
- ADXL345 accelerometer sensor
- USB cable for power and communication

## Software Requirements

- Renesas e² studio IDE
- FSP (Flexible Software Package)
- USB serial terminal program

## Features

- I2C master implementation for sensor communication
- ADXL345 accelerometer data acquisition
- USB CDC serial interface for data output
- Real-time X, Y, Z axis acceleration monitoring

## Code Functionality

The main application:
- Initializes the I2C master interface for communication with ADXL345
- Configures the ADXL345 accelerometer by enabling measurement mode
- Periodically reads X, Y, Z acceleration data via I2C
- Processes and formats the raw sensor data
- Transmits formatted data through USB serial interface
- Performs error checking to ensure reliable I2C communication

## Getting Started

### Setup

1. Connect the ADXL345 sensor to the I2C pins on the RA4M1 Feather board
2. Connect the RA4M1 Feather board to your computer via USB
3. Open the project in e² studio IDE
4. Build and flash the project to the RA4M1 Feather board
5. Open a serial terminal to view the acceleration data

### Configuration

```c
// Example configuration for ADXL345 sensor
#define POWER_CTL_REG           (0x2D)  // Power control register
#define ENABLE_BIT              (0x08)  // Measurement mode enable bit
#define AXIS_DATA               (0x32)  // Starting register for axis data
```

## Project Structure

- `src/i2c_sensor.c/h`: ADXL345 sensor communication implementation
- `src/hal_entry.c`: Main application entry point and logic
- `src/usb_uart.h`: USB CDC serial communication interface
- `src/common_utils.h`: Utility functions and macros

## License

This software is owned by Renesas Electronics Corporation and is protected under applicable copyright laws.

## Additional Resources

- [Zalmotek Website](https://zalmotek.com)
- [Zalmotek RA4M1 Website](https://zalmotek.com/products/RA4M1-Feather-SoM/)
- [SEGGER RTT Documentation](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/) 
