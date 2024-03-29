# I2C Communication between ESP32 and Arduino Uno



## Overview

This project aims to explore and utilize the I2C communication protocol between two microcontroller boards. In this setup, an ESP32 board serves as the master, while an Arduino Uno acts as the slave. The master board communicates button presses to the slave via I2C, and the slave board responds by lighting up an LED corresponding to the pressed button.

## Functionality

- Utilizes I2C communication to transmit button press information from the master to the slave board.
- Slave board responds to received data by illuminating an LED associated with the pressed button.

## Implementation

When a button is pressed on the master board (ESP32), the corresponding button press information is sent via I2C to the slave board (Arduino Uno). Upon receiving this data, the slave board lights up the LED corresponding to the pressed button.

## Components Used

- ESP32 board (Master)
- Arduino Uno (Slave)
- Buttons
- LEDs
- Resistors
- Breadboards and jumper wires

## Circuit Diagram

<img width="536" alt="Project Diagram" src="https://github.com/Z313PH/I2C-Communication/assets/119972119/a5e64259-c1e0-4252-9518-58d9804c20a9">

## Setup Instructions

1. Connect buttons and LEDs to both the master and slave boards.
2. Establish I2C communication lines between the ESP32 and Arduino Uno.
3. Upload the respective Arduino sketches provided in the repository to the master and slave boards.
4. Power on the system and press buttons on the master board to observe LED illumination on the slave board.

## Repository Contents

- **Arduino Sketches**: Contains the code necessary to implement I2C communication between the master (ESP32) and slave (Arduino Uno) boards.
- **Project Image**: Illustration or image depicting the setup of the project.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgements

- This project was undertaken to explore and demonstrate the practical application of I2C communication between different microcontroller boards.

Feel free to contribute, report issues, or suggest improvements! Happy experimenting with I2C communication! 🛰️🔌
