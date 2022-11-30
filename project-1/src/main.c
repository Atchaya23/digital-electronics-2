/***********************************************************************
 * 
 * Stopwatch by Timer/Counter2 on the Liquid Crystal Display (LCD)
 *
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2017 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 * Components:
 *   16x2 character LCD with parallel interface
 *     VSS  - GND (Power supply ground)
 *     VDD  - +5V (Positive power supply)
 *     Vo   - (Contrast)
 *     RS   - PB0 (Register Select: High for Data transfer, Low for Instruction transfer)
 *     RW   - GND (Read/Write signal: High for Read mode, Low for Write mode)
 *     E    - PB1 (Read/Write Enable: High for Read, falling edge writes data to LCD)
 *     D3:0 - NC (Data bits 3..0, Not Connected)
 *     D4   - PD4 (Data bit 4)
 *     D5   - PD5 (Data bit 5)
 *     D6   - PD6 (Data bit 3)
 *     D7   - PD7 (Data bit 2)
 *     A+K  - Back-light enabled/disabled by PB2
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <lcd.h>            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for number conversions




/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Update stopwatch value on LCD screen when 8-bit 
 *           Timer/Counter2 overflows.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    /*
    lcd_init(LCD_DISP_ON);
    lcd_gotoxy(0,0);
    lcd_puts("HI");

    lcd_gotoxy(0,0);
    if(analogRead(X_pin) == 513){
    lcd_puts("STOPPED");
    } 
    else if(analogRead(X_pin) < 513) {
    lcd_puts("REVERSE");
    } 
    else if(analogRead(X_pin) > 513) {
    lcd_puts("FORWARD");
    }
    
    lcd_gotoxy(0, 1);
    if(analogRead(X_PIN) == 512){
    lcd_puts("STOPPED");
    } 
    else if(analogRead(X_PIN) < 512) {
    lcd_puts("LEFT ");
    } 
    else if(analogRead(X_PIN) > 512) {
    lcd_puts("RIGHT");
    }
    

    int var = analogRead(X_PIN);
    printf(var);
    */
    uint16_t value;
    char string[4];
    value = ADC;

    itoa(value, string, 10);
    lcd_gotoxy(8,0);
    lcd_puts("  ");
    lcd_gotoxy(8,0);
    lcd_puts(string);

}