#include "leds.h"
#include "stm32f4xx_hal.h"

void YellowOn(void){HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);}
void YellowOff(void){HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);}
iLed YellowLED = {YellowOn, YellowOff};

void RedOn(void){HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);}
void RedOff(void){HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);}
iLed RedLED = {RedOn, RedOff};

void GreenOn(void){HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);}
void GreenOff(void){HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);}
iLed GreenLED = {GreenOn, GreenOff};
