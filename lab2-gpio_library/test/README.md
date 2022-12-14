# Lab 2: ATCHAYA TIROUGNANAME

### GPIO control registers

1. Complete the table for DDRB and PORTB control register values.

   | **DDRB** | **PORTB** | **Direction** | **Internal pull-up resistor** | **Description** |
   | :-: | :-: | :-: | :-: | :-- |
   | 0 | 0 | input | no | Tri-state, high-impedance |
   | 0 | 1 | input | yes | pull-up activated|
   | 1 | 0 | output | no | low level |
   | 1 | 1 | output | yes | high level|

### GPIO library

2. Complete the table with code sizes from three versions of the blink application.

   | **Version** | **Size [B]** |
   | :-- | :-: |
   | Arduino-style     | 2048 |
   | Registers         | 32256 |
   | Library functions |  |

### Traffic light

3. Scheme of traffic light application with one red/yellow/green light for cars, one red/green light for pedestrians, and one push button. Connect AVR device, LEDs, resistors, push button (for pedestrians), and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

  ![Capture](https://user-images.githubusercontent.com/114863539/195104486-5562349c-6518-4a6b-bc53-b5da60b5cfc5.PNG)
