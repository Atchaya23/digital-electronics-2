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
/** @brief Stop timer, prescaler 000 --> STOP */
#define TIM2_stop()           TCCR1B &= ~((1<<CS22) | (1<<CS21) | (1<<CS20));
/** @brief Set overflow 16u, prescaler 001 --> 1 */
#define TIM2_overflow_16u()   TCCR1B &= ~((1<<CS22) | (1<<CS21)); TCCR1B |= (1<<CS20);
/** @brief Set overflow 128u, prescaler 010 --> 8 */
#define TIM2_overflow_128u()  TCCR1B &= ~((1<<CS22) | (1<<CS20)); TCCR1B |= (1<<CS21);
/** @brief Set overflow 512u, prescaler 011 --> 64 */
#define TIM2_overflow_512u() TCCR1B &= ~(1<<CS22); TCCR1B |= (1<<CS21) | (1<<CS20);
/** @brief Set overflow 1ms, prescaler 100 --> 256 */
#define TIM2_overflow_1ms()    TCCR1B &= ~((1<<CS21) | (1<<CS20)); TCCR1B |= (1<<CS22);
/** @brief Set overflow 2ms, prescaler // 101 --> 1024 */
#define TIM2_overflow_2ms()    TCCR1B &= ~(1<<CS21); TCCR1B |= (1<<CS22) | (1<<CS20);
/** @brief Set overflow 4ms, prescaler // 101 --> 1024 */
#define TIM2_overflow_4ms()    TCCR1B &= ~(1<<CS20); TCCR1B |= (1<<CS22) | (1<<CS21);
/** @brief Set overflow 16ms, prescaler // 101 --> 1024 */
#define TIM2_overflow_16ms()   TCCR1B |= (1<<CS22) | (1<<CS21) | (1<<CS20);


/** @brief Enable overflow interrupt, 1 --> enable */
#define TIM2_overflow_interrupt_enable()  TIMSK2 |= (1<<TOIE1);
/** @brief Disable overflow interrupt, 0 --> disable */
#define TIM2_overflow_interrupt_disable() TIMSK2 &= ~(1<<TOIE1);

   ```
