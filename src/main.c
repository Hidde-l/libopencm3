/**
 * Student name: Hidde van Luenen
 * Student number: 5734223
 * 
 */

#include "utils.hpp"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <stdbool.h>
// #include "stm32f401xc.h"
// #include "stm32f4xx.h"

int main(void) {
    // Setup
    rcc_periph_clock_enable(RCC_GPIOC);
    rcc_periph_clock_enable(RCC_GPIOB);
    gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);
    gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO0);

    // Main loop
    while (true) {
      gpio_toggle(GPIOC, GPIO13);
      gpio_toggle(GPIOB, GPIO0);
      ms_delay(500U);
    }

    return 0;
}

// #define LEDPIN 13
// #define MASK(x) (1L << (x))
// void setup(void);
// void loop(void);


// void setup (void) {
//   RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
//   GPIOC->MODER |= 0b01 << 26;
//   GPIOC->OTYPER |= GPIO_OTYPER_OT13;
// }

// void loop (void) {
//   // put your main code here , to run repeatedly :
//   GPIOC->ODR ^= MASK(LEDPIN);
//   ms_delay(300);
// }


// int main(void) {
//   setup();
//   while (1) {
//     loop();
//   }
//   return 0;
// }
