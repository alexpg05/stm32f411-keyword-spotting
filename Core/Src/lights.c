#include "main.h"
#include "lights.h"

#define BLINK_SLOW_VAL (10)
#define BLINK_FAST_VAL (5)

void update_lights(LightState input_state)
{
	switch(input_state)
	{
		case OFF:
			HAL_GPIO_WritePin(Yellow_Led_GPIO_Port, Yellow_Led_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Red_Led_GPIO_Port, Red_Led_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Green_Led_GPIO_Port, Green_Led_Pin, GPIO_PIN_SET);
			break;
		case YELLOW:
			HAL_GPIO_WritePin(Yellow_Led_GPIO_Port, Yellow_Led_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Red_Led_GPIO_Port, Red_Led_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Green_Led_GPIO_Port, Green_Led_Pin, GPIO_PIN_SET);
			break;
		case RED:
			HAL_GPIO_WritePin(Yellow_Led_GPIO_Port, Yellow_Led_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Red_Led_GPIO_Port, Red_Led_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Green_Led_GPIO_Port, Green_Led_Pin, GPIO_PIN_SET);
			break;
		case GREEN:
			HAL_GPIO_WritePin(Yellow_Led_GPIO_Port, Yellow_Led_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Red_Led_GPIO_Port, Red_Led_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Green_Led_GPIO_Port, Green_Led_Pin, GPIO_PIN_RESET);
			break;
		case BLINK_SLOW:
			static int blink_slow_counter = BLINK_SLOW_VAL;
			if (blink_slow_counter >= 0)
			{
				HAL_GPIO_WritePin(Yellow_Led_GPIO_Port, Yellow_Led_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Red_Led_GPIO_Port, Red_Led_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Green_Led_GPIO_Port, Green_Led_Pin, GPIO_PIN_RESET);
			}
			else
			{
				HAL_GPIO_WritePin(Yellow_Led_GPIO_Port, Yellow_Led_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Red_Led_GPIO_Port, Red_Led_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Green_Led_GPIO_Port, Green_Led_Pin, GPIO_PIN_SET);
			}
			blink_slow_counter -= 1;
			if (blink_slow_counter == -BLINK_SLOW_VAL) blink_slow_counter = BLINK_SLOW_VAL;
			break;
		case BLINK_FAST:
			static int blink_fast_counter = BLINK_FAST_VAL;
			if (blink_fast_counter >= 0)
			{
				HAL_GPIO_WritePin(Yellow_Led_GPIO_Port, Yellow_Led_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Red_Led_GPIO_Port, Red_Led_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Green_Led_GPIO_Port, Green_Led_Pin, GPIO_PIN_RESET);
			}
			else
			{
				HAL_GPIO_WritePin(Yellow_Led_GPIO_Port, Yellow_Led_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Red_Led_GPIO_Port, Red_Led_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Green_Led_GPIO_Port, Green_Led_Pin, GPIO_PIN_SET);
			}
			blink_fast_counter -= 1;
			if (blink_fast_counter == -BLINK_FAST_VAL) blink_fast_counter = BLINK_FAST_VAL;
			break;
		case CONTINUOUS:
			HAL_GPIO_WritePin(Yellow_Led_GPIO_Port, Yellow_Led_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Red_Led_GPIO_Port, Red_Led_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Green_Led_GPIO_Port, Green_Led_Pin, GPIO_PIN_RESET);
			break;

	}
}
