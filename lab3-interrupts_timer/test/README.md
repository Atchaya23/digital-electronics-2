# Lab 3: ATCHAYA TIROUGNANAME

### Overflow times

1. Complete table with overflow times.

   | **Module** | **Number of bits** | **1** | **8** | **32** | **64** | **128** | **256** | **1024** |
   | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
   | Timer/Counter0 | 8  | 16u | 128u | -- | 1ms | -- | 4.1ms | 16.4ms |
   | Timer/Counter1 | 16 |   4ms  | 33ms   | -- | 262ms | -- | 1s | 4.2 s|
   | Timer/Counter2 | 8  |   16u  |  128u  |  512u   | 1ms |  2ms  | 4.1ms | 16.4ms |

### Interrupts

2. In `timer.h` header file, define macros also for Timer/Counter2. Listing of part of the header file with settings for Timer/Counter2. Always use syntax highlighting, meaningful comments, and follow C guidelines:

   ```c
   /**
    * @name  Definitions for 8-bit Timer/Counter2
    * @note  t_OVF = 1/F_CPU * prescaler * 2^n where n = 8, F_CPU = 16 MHz
    */
   // WRITE YOUR CODE HERE
   ```