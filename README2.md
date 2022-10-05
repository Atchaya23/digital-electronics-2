# Lab 1: ATCHAYA_TIROUGNANAME

### Morse code

1. Listing of C code which repeats one "dot" and one "comma" (BTW, in Morse code it is letter `A`) on a LED. Always use syntax highlighting, meaningful comments, and follow C guidelines:

```c
int main(void)
{
    // Set pin where on-board LED is connected as output
    pinMode(LED_GREEN, OUTPUT);

    //defines
    #define SHORT_DELAY 60 // Delay in milliseconds

    // Infinite loop
    while (1)
    {
	
	#letter P
	digitalWrite(LED_GREEN, led_value);
	_delay_ms(SHORT_DELAY);
	_delay_ms(SHORT_DELAY);
	digitalWrite(LED_GREEN, led_value);
	
	#letter A
	digitalWrite(LED_GREEN, led_value);
	_delay_ms(SHORT_DELAY);
	
	#letter R
	digitalWrite(LED_GREEN, led_value);
	_delay_ms(SHORT_DELAY);
	digitalWrite(LED_GREEN, led_value);

	#letter I
	digitalWrite(LED_GREEN, led_value);
	digitalWrite(LED_GREEN, led_value);

	#letter S
	digitalWrite(LED_GREEN, led_value);
	digitalWrite(LED_GREEN, led_value);
	digitalWrite(LED_GREEN, led_value);
	
        // Change LED value
        if (led_value == LOW)
            led_value = HIGH;
        else
            led_value = LOW;

    }

    // Will never reach this
    return 0;
}
```

2. Scheme of Morse code application, i.e. connection of AVR device, LED, resistor, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![image](https://user-images.githubusercontent.com/114863539/194038128-38efffd5-1e9c-4bf4-ba6f-444162e67a7c.png)
