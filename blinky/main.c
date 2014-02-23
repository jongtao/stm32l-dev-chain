//#define USE_STDPERIPH_DRIVER
#include "stm32l1xx.h"
//#include "stm32l1xx_conf.h"

 
//Quick hack, approximately 1ms delay
void ms_delay(int ms)
{
   while (ms-- > 0) {
      volatile int x=500;
      while (x-- > 0)
         __asm("nop");
   }
}


//Alternates blue and green LEDs quickly
int main(void)
{
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN; 		 // enable the clock to GPIOB
    GPIOB->MODER |= (1 << 12);             // set pin 6 to be general purpose output
    GPIOB->MODER |= (1 << 14);             // set pin 7 to be general purpose output

    GPIOB->ODR |= (1 << 7);           			// Set the pin 7 high

    for (;;) {
       ms_delay(100);
       GPIOB->ODR ^= (1 << 6);           // Toggle the pin 
       GPIOB->ODR ^= (1 << 7);           // Toggle the pin 
    }
}
