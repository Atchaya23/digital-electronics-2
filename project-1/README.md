# PROJECT 1
## TEAM MEMBERS
- Maëlle SORIANO
- Atchaya TIROUGNANAME

## HARDWARE DESCRIPTION

For our project, we used the next components:

- Arduino Uno with AtmelMega328P MCU.
- Joystick .
- Digilent PmodCLP LCD module.
- Breadboard.


### Arduino Uno ATmega328P

![image](https://user-images.githubusercontent.com/114863539/206877940-41feb3db-5e2c-4d62-a621-a31d320ece04.png)

Arduino UNO is a microcontroller board based on the ATmega328P. It has 14 digital input/output pins (of which 6 can be used as PWM outputs), 6 analog inputs, a 16 MHz ceramic resonator, a USB connection, a power jack, an ICSP header and a reset button. 

Our hardware has been connected to these pins, and we have used different registers and commands for the software implementation.

### Joystick


The Analog Joystick is similar to two potentiometers connected together, one for the vertical movement (Y-axis) and other for the horizontal movement (X-axis). The joystick also comes with a Select switch.

The home position for the stick is at ( x,y:511,511). If the stick is moved on X axis, the X values will change between 0 to 1023 and similarly when the Y axis is moved by the stick.

![image](https://user-images.githubusercontent.com/114863539/206878131-a2a6d708-3ee7-4932-9f09-46751da8e7bc.png)


### Digilent PmodCLP LCD module

![image](https://user-images.githubusercontent.com/114863539/206877926-a9289cf0-c34a-429e-9641-afbe14eca79b.png)

The Digilent Pmod CLP is a 16×2 character LCD module that uses a 8-bit parallel data interface to display up to 32 different characters.


### IMPLEMENTATION


We decided to do a simple implementation for our project using the joystick. We wanted to do a little game where the user have to move the character "I" and when he finish the x axis, the user "wins". And at the same time, we display the movements of the joystick.

To implement our idea, we read the value of our joystick and display it on our LCD screen and momve the character "I" according to the movements of the joystick. 


## SOFTWARE DESCRIPTION

The structure of our project :
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

GPIO library includes a set of routines for easier handling of the General Purpose Input/Output ( GPIO ) pin functions. 

For clarity and efficiency of the code, the individual parts of the application in C are divided into two types of files: header files and source files.

Header file is a file with extension .h and contains definitions of data types, function prototypes and C preprocessor commands. 
Source file has the extension .c and is used to implementation the code. 

To implement this library in our code, we use ```#include``` directive. 

Our GPIO library consists of:
- [Header file](https://github.com/Atchaya23/digital-electronics-2/blob/main/project-1/lib/gpio/gpio.h) gpio.h.
- [Library source](https://github.com/Atchaya23/digital-electronics-2/blob/main/project-1/lib/gpio/gpio.c) file gpio.c.


### LCD

For LCD, we used the library developed by Peter Fleury that we have already used in class.
In this library, thera are 3 files, two header files and one source file.

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


### Flowcharts

Flowchart of the main function

![IMG-9362](https://user-images.githubusercontent.com/114863539/206878569-2c072acf-68c7-4eec-b1e2-1cf9e1f6faef.jpg)


Flowchart of ISR(TIMER1_OVF_vect)

![image](https://user-images.githubusercontent.com/114863539/206878635-8cd0e8ad-0f28-49ee-8460-ba68bf7e19cf.png)


Flowchart of ISR(ADC_vect)

![image](https://user-images.githubusercontent.com/114863539/206879768-af741499-9aaf-45fa-8497-1c0ee84ac8f5.png)



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
https://docs.arduino.cc/hardware/uno-rev3

https://exploreembedded.com/wiki/Analog_JoyStick_with_Arduino

https://digilent.com/reference/pmod/pmodclp/start
