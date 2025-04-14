# Zalmotek RA4M1 Feather SoM 

Welcome to the <a href="https://zalmotek.com/products/RA4M1-Feather-SoM/">Zalmotek RA4M1 Feather SoM</a> GitHub repository!

Here you'll find all the resources you need to get up and running quickly.

## 🪶 What is the RA4M1 Feather SoM?

The <a href="https://www.renesas.com/us/en/products/microcontrollers-microprocessors/ra-cortex-m-mcus/ra4m1-100mhz-arm-cortex-m4-general-purpose-microcontroller">Renesas RA4M1</a> is designed for high-performance applications with low power requirements, featuring the Arm® Cortex®-M4 CPU core with a maximum operating frequency of 48 MHz. It's ideal for IoT devices and industrial applications requiring efficient operation and advanced peripherals.

The Feather SoM incorporates the classic Feather features: GPIOs (analog and digital), I2C and SPI communication pins, UART pins, a LiPo battery power plug, and the USB programming port. The SoM also features a USB Type-C for powering the board and for USB debug upload, making it perfect for high-performance IoT and industrial projects.

<p align="center">
  <img src="images/Feather-RA4M1-pinout.png" height="500">
  <img src="images/Feather-RA4M1-BD.png" height="500">
</p>

## 🐣🏁 Quick Start Guide

### 🔌 Hardware Requirements
- USB-C cable
- JTAG Debugger, such as the <a href="https://www.segger.com/products/debug-probes/j-link/">SEGGER J-Link</a>

### 💻 Development Environment Setup

#### Installing Renesas e² studio IDE

The e² studio IDE from Renesas is a comprehensive, user-friendly platform designed to streamline embedded application development. It supports Renesas microcontrollers and combines powerful features with an intuitive interface for coding, debugging, and project management.

First of all, download the latest release of the Flexible Software Package with the e²studio platform installer from the following <a href="https://www.renesas.com/us/en/software-tool/e2studio-information-ra-family">link</a>, according to your OS.

The installer will guide you through the necessary steps. After the installation is finished, launch Renesas e² studio and set up your workspace. This will be the directory where all your projects will be stored.

You will also need to install the J-Link Software pack from <a href="https://www.segger.com/products/debug-probes/j-link/technology/flash-download/">here</a>.

#### Running your first project

Once you have all the tools installed, follow <a href="https://github.com/Zalmotek/zalmotek-RA4M1-feather/tree/main/firmware/Blink">this</a> guide to learn how to import, build, and run a project in the e² studio IDE. 

---
Thank you for choosing the Zalmotek RA4M1 Feather SoM! 

We can't wait to see what amazing projects you'll create with it! 💻✨