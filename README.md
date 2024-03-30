# Advanced-Calculator
Advanced Multi-Operation Calculator
This repository contains the source code for an Advanced Multi-Operation Calculator project.

#Project Description
This calculator performs various arithmetic operations on real numbers, including addition, subtraction, multiplication, and division, all within a single equation. It ensures accurate results by following the standard order of operations. The user interacts with the calculator through a user-friendly interface consisting of a 4x4 keypad for input and a 16x2 LCD display for clear visualization.

#Features
-Supports basic arithmetic operations: addition, subtraction, multiplication, and division.
-Ensures accurate calculations by following the order of operations (PEMDAS).
-User-friendly interface with a 4x4 keypad for input and a 16x2 LCD display for output.

#Hardware
-Microcontroller: ATmega32
-Keypad: 4x4 Matrix
-LCD display: 16x2 Characters

#Software Architecture
The project utilizes a layered architecture for better code organization and maintainability:

-Application: Handles the core functionalities of the calculator, including user input processing, mathematical operations, and display control.
-HAL (Hardware Abstraction Layer): Provides a layer of abstraction for interacting with hardware components like the keypad and LCD display.
-MCAL (Microcontroller Abstraction Layer): Provides low-level functionalities specific to the ATmega32 microcontroller, such as GPIO control.
