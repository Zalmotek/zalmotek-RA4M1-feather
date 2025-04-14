# Zalmotek RA4M1 Feather ADC

A demonstration project showcasing analog-to-digital conversion capabilities on the Zalmotek RA4M1 Feather board, powered by Renesas RA4M1 microcontroller.

## Overview

This project demonstrates the analog-to-digital conversion capabilities of the Zalmotek RA4M1 Feather board, featuring Renesas RA4M1 microcontroller. It provides a simple example of reading analog values from the onboard ADC pins and processing the digital output. The project uses the RA4M1's built-in 12-bit ADC with configurable sampling rates and reference voltages.

## Hardware Requirements

- Zalmotek RA4M1 Feather board
- USB Type-C cable for programming and power
- Optional: Analog input source (e.g., potentiometer, sensor)

## Software Requirements

- e2 Studio IDE
- Renesas FSP (Flexible Software Package)
- GCC ARM Embedded Toolchain
- RA4M1 BSP (Board Support Package)

## Features

- 12-bit ADC resolution
- Configurable sampling rates
- Multiple analog input channels
- Digital value processing and conversion
- Real-time analog value monitoring

## Code Functionality

The main application:
- Initializes the ADC peripheral with default configuration
- Sets up the analog input pins
- Configures the sampling rate and reference voltage
- Continuously reads analog values from the selected channel
- Converts and processes the digital output
- Provides debug output through serial communication

## Getting Started

### Setup

1. Connect the Zalmotek RA4M1 Feather board to your computer using a USB Type-C cable
2. Open the project in e2 Studio IDE
3. Import the necessary FSP and BSP packages
4. Build the project
5. Flash the firmware to the board

### Configuration

```c
// Example ADC configuration
adc_cfg_t adc_cfg = {
    .resolution = ADC_RESOLUTION_12_BIT,
    .alignment = ADC_ALIGN_RIGHT,
    .scan_end = ADC_SCAN_END_SINGLE_SCAN,
    .trigger = ADC_TRIGGER_SOFTWARE,
    .p_callback = adc_callback,
    .p_context = NULL,
    .p_extend = NULL
};
```

## Project Structure

- `src/`: Contains the main application source files
- `ra/`: Renesas FSP configuration files
- `ra_gen/`: Generated FSP code
- `script/`: Build and configuration scripts

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Additional Resources

- [Zalmotek Website](https://zalmotek.com)
- [Zalmotek RA4M1 Website](https://zalmotek.com/products/RA4M1-Feather-SoM/)
- [SEGGER RTT Documentation](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/) 