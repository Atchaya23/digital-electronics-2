# PROJECT 1
## TEAM MEMBERS
- Maëlle SORIANO
- Atchaya TIROUGNANAME
- 
## HARDWARE DESCRIPTION

![Image of all hardware](https://github.com/NestorGorrotxategi/digitalelectronics2/blob/main/lab-project1/Schematic.png)

As we see in the picture above, we have used the following hardware for our project:
- Arduino Uno with AtmelMega328P MCU.
- Joystick .
- Digilent PmodCLP LCD module.

We have carried out some research on every piece of hardware that we have been asked to implement for the project:

### Arduino Uno ATmega328P

Arduino Uno is a microcontroller board based on ATmega328P MCU. It offers 14 digital input/output pins and 6 analog inputs, and a 16MHZ clock signal among others.

Using AVR microcontroller, pins are associated into so-called ports, which are marked with the letters A,B,C,... Each of the pins is controlled independently and can either work as input or output point of the MCU. Control is only possible ussing control registers.

Our hardware has been connected to these pins, and we have used different registers and commands for the software implementation.

### Joystick

![Image of all hardware](https://github.com/NestorGorrotxategi/digitalelectronics2/blob/main/lab-project1/joystick%20image.jpg)

The basic principle of the analog joystick is a set of two interconnected potentiometers which provide information about vertical (Y-axis) and horizontal (X-axis) movement. In addition, the joystick also comes with a Select switch.

![Image of all hardware](https://github.com/NestorGorrotxategi/digitalelectronics2/blob/main/lab-project1/joystick%20axis.avif)

Apart from the VCC and GND pins for the Joystick which are connected to their corresponding pins in the breadboard, it has 3 other connections: 2 analog signals (Vrx for X and Vry for Y axis information) and a digital signal (switch). 

The first signals have to be processed by ADC channels. This is why **Vrx** and **Vry** have been connected respectively to **A0** and **A1 ADC channels** on the Arduino board as we see on the scheme.

As far as the **switch** connection is concerned, as it is a digital signal, it has been connected to **digital pin 13 (PB5)** as an input.

### Digilent PmodCLP LCD module

![Image of all hardware](https://github.com/NestorGorrotxategi/digitalelectronics2/blob/main/lab-project1/Digilent_PmodCLP_30044294-01.jpg)

The Digilent PmodCLP is a 16x2 character LCD used to display up to 32 different characters at a time. It uses a 8-bit parallel data interface for communication.




### IMPLEMENTATION


We decided to do a simple implementation for our project using the joystick. We wanted to do a little game where the user have to move the character "I" and when he finish the x axis, the user "wins". And at the same time, we display the movements of the joystick.

To implement our idea, we read the value of our joystick and display it on our LCD screen and momve the character "I" according to the movements of the joystick. 


## SOFTWARE DESCRIPTION

Our project's library and source has the following structure:
```
├── lib
|   ├── Joystick
|   |   └── joystick_definitions.h
│   ├── gpio
│   │   ├── gpio.c
│   │   └── gpio.h
│   └── lcd
│       ├── lcd.c
│       ├── lcd.h
│       └── lcd_definitions.h
└── src
    └── main.c

```

### GPIO

Some control registers from AVR MCU are defined in this library in order to make coding easier. This library is divided into two types of files: header files and source files.

The first type usually contains definitions of data types, function prototypes, includes, definitions and C preprocessor commands. As it is indicated by its name, the extension of header file is **.h**. 

Source file **.c** is used to implement the code.

To implement this library in our code, we use ```#include``` directive. Then, whenever a function from this library is called, the control of the program is transferred to the function.

Our GPIO library consists of:
- [Header file](https://github.com/Atchaya23/digital-electronics-2/blob/main/project-1/lib/gpio/gpio.h) gpio.h.
- [Library source](https://github.com/Atchaya23/digital-electronics-2/blob/main/project-1/lib/gpio/gpio.c) file gpio.c.


### LCD

So as to make LCD registers and commands easier, we are using a LCD library file developped by Peter Fleury which consist of 3 files:

- [Header file](https://github.com/Atchaya23/digital-electronics-2/blob/main/project-1/lib/lcd/lcd.h) lcd.h.
- [Source file](https://github.com/Atchaya23/digital-electronics-2/blob/main/project-1/lib/lcd/lcd.c) lcd.c.
- [Lcd definitions](https://github.com/Atchaya23/digital-electronics-2/blob/main/project-1/lib/lcd/lcd_definitions.h) lcd_definitions.h.

### JOYSTICK

We created a new library to define the ports for the x and y value of the joystick.
#define JOY_X_VALUE PB5
#define JOY_Y_VALUE PB4
We then included this file into our main file by using #include "joystick_definitions.h".

### MAIN

We created a main.c file inside ```src``` folder.In the main code you can find our project with includes, definitions, and functions:

- [Main file](https://github.com/Atchaya23/digital-electronics-2/blob/main/project-1/src/main.c) main.c.

Here are the flowcharts of the main function and ISRs of our project.

### int main()

* Initialize the LCD display.
* Configure the Analog-to-Digital Convertion unit.
* Set the overflow for Timer1.
* Enables interupts (sei()).
* Infinite loop.




### ISR(Timer1)

* Start ADC conversion.



### ISR(ADC_vect)

* Display on the LCD the direction of the joystick(UP, DOWN, RIGHT and LEFT) and move the character "I" according to the movements of I.
* The directions are written on the up left side so the character "I" can't move there.
* When the character finish the x axis, there is a message displayed, saying "WIN"



## VIDEO

Here is the link to the video for our project:

https://youtube.com/shorts/Z7tvvirNyhg?feature=share


## REFERENCES
