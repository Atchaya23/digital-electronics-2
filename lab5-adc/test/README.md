# Lab 5: Atchaya TIROUGNANAME

### Analog-to-Digital Conversion

1. Complete table with voltage divider, calculated, and measured ADC values for all five push buttons.

   | **Push button** | **PC0[A0] voltage** | **ADC value (calculated)** | **ADC value (measured)** | **ADC value (measured, hex)** |
   | :-: | :-: | :-: | :-: | :-: |
   | Right  | 0&nbsp;V | 0   | 0 | 0 |
   | Up     | 0.495&nbsp;V | 101 | 99 | 0x65  |
   | Down   | 1.203&nbsp;V | 246 | 257 | 0xF6 |
   | Left   | 1.9697&nbsp;V | 403 | 410 | 0x193  |
   | Select | 3.1818&nbsp;V | 650 | 640 | 0x28A |
   | none   | 5&nbsp;V | 1023 |  | 0x3FF |

### Temperature meter

Consider an application for temperature measurement. Use analog temperature sensor [TC1046](http://ww1.microchip.com/downloads/en/DeviceDoc/21496C.pdf), LCD, and a LED. Every 30 seconds, the temperature is measured and the value is displayed on LCD screen. When the temperature is too high, the LED will turn on.

2. Draw a schematic of temperature meter. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![20221101_183906-_1_](https://user-images.githubusercontent.com/114863539/199302461-911277c1-c9d0-4ad6-b44b-5c90984fbd4d.png)

3. Draw two flowcharts for interrupt handler `TIMER1_OVF_vect` (which overflows every 1&nbsp;sec) and `ADC_vect`. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![20221101_183848-_1_](https://user-images.githubusercontent.com/114863539/199302504-77635c80-26d4-49ce-b1bb-d33600652c75.png)
