#include "main.h"

int main(void){  
  
  // PA5 is green led on the board
  // let's enable this led

  // clock settings for GPIOA
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);

  // gpio setting for GPIOA.5
  LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);

  // set to high the pin to enable led
  LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_5);

  for(;;);

}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
