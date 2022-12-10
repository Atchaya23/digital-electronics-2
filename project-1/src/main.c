/***********************************************************************
 * 
 *
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
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
#include "joystick_definitions.h" 

static int var_x = 0;
static int var_y = 1; 





/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Update stopwatch value on LCD screen when 8-bit 
 *           Timer/Counter2 overflows.
 * Returns:  none
 **********************************************************************/
int main(void)
{   

    // Initialize display
    lcd_init(LCD_DISP_ON);

    
    lcd_gotoxy(var_x, var_y); lcd_puts("I");


    lcd_command(1<<LCD_CGRAM);       // Set addressing to CGRAM (Character Generator RAM)
    lcd_command(1<<LCD_DDRAM);       // Set addressing back to DDRAM (Display Data RAM)
    
   

    
    lcd_putc(0x00);

    GPIO_mode_output(&DDRB, PB2);
    GPIO_write_high(&PORTB,PB2);

    // Configure Analog-to-Digital Convertion unit
    // Select ADC voltage reference to "AVcc with external capacitor at AREF pin"
    ADMUX = ADMUX | (1<<REFS0);
    // Select input channel ADC0 (voltage divider pin)
    ADMUX = ADMUX & ~(1<<MUX3 | 1<<MUX2 | 1<<MUX1 | 1<<MUX0); //here we are clearing the four bits
    // Enable ADC module
    ADCSRA = ADCSRA | (1<<ADEN);
    // Enable conversion complete interrupt
    ADCSRA = ADCSRA | (1<<ADIE);
    // Set clock prescaler to 128
    ADCSRA = ADCSRA | (1<<ADPS2 | 1<<ADPS1 | 1<<ADPS0);
    
    // Configuration of Timer/Counter1 
    // Set the overflow prescaler to 33 ms and enable interrupt
    TIM1_overflow_33ms();
    TIM1_overflow_interrupt_enable();

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines, ISRs */
    }

    // Will never reach this
    return 0;
}


/* Interrupt service routines ----------------------------------------*/

/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Use single conversion mode and start conversion every 100 ms.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    // Start ADC conversion
    ADCSRA = ADCSRA | (1<<ADSC);
}


/**********************************************************************
 * Function: ADC complete interrupt
 * Purpose:  Display converted value on LCD screen.
 **********************************************************************/
ISR(ADC_vect)
{
    uint16_t value;
    
  


    char string[4];  // String for converted numbers by itoa()
    static int channel = 0;
    value = ADC;

  if (channel==1){
    channel =0;
  }else{
    channel=1;
  }

    switch (channel)
    {
    case 1:
      ADMUX = ADMUX | 1<<MUX0;

      itoa(value, string, 10);
      lcd_gotoxy(3,0);

        if( value > 530){
        lcd_clrscr();
        lcd_gotoxy(1, 0);
        lcd_puts("DOWN");
        lcd_gotoxy(var_x, 1);
        lcd_puts("I");
        }

    
        if( value < 500){
        lcd_clrscr();
        lcd_gotoxy(1, 0);
        lcd_puts("UP");
        if(var_x>4){
          lcd_gotoxy(var_x, 0);
          lcd_puts("I");
        }else{
          lcd_gotoxy(var_x, var_y);
          lcd_puts("I");
        }
        }
      break;
            
    case 0:
      ADMUX = ADMUX & ~(1<<MUX3 | 1<<MUX2 | 1<<MUX1 | 1<<MUX0);

      itoa(value, string, 10);
      lcd_gotoxy(3,1);
            
        if( value > 505){
        lcd_clrscr();
        lcd_gotoxy(1, 0);
        lcd_puts("LEFT");
        lcd_gotoxy(var_x-1, var_y);
        lcd_puts("I");
        var_x=var_x-1;
        }
            
        if( value < 480){
        lcd_clrscr();
        lcd_gotoxy(1, 0);
        lcd_puts("RIGHT");
        lcd_gotoxy(var_x+1, var_y);
        lcd_puts("I");
        var_x+=1;
        }

        if(var_x>15){
          lcd_clrscr();
          lcd_gotoxy(1, 0);
          lcd_puts("WIN");
        }

    }

}

