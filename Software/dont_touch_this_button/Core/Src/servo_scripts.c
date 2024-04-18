#include "stm32f1xx_hal.h"
#include "main.h"
#include "servo_scripts.h"
#include "systick_timer.h"

/* Private variables ---------------------------------------------------------*/

extern TIM_HandleTypeDef htim1;

/* Private function prototypes -----------------------------------------------*/

uint8_t script(uint8_t action) {

    if (action == 1)
    {
    	HAL_GPIO_WritePin(GPIOB, LED2_Pin, GPIO_PIN_SET);
    	clear_wait_ms_ch(channelLED2);
    	while (!wait_ms_ch(channelLED2, 2500)) {}

    	for (int i = 620; i >= 450; i--)
    	{
    		htim1.Instance->CCR1 = i;
    		HAL_Delay(13);
    	}
    	for (int i = 650; i >= 270; i--)
    	{
    		htim1.Instance->CCR2 = i;
    		HAL_Delay(20);
    	}
    	HAL_Delay(1000);
    	htim1.Instance->CCR2 = 250;
    	HAL_Delay(200);
    	for (int i = 270; i <= 650; i++)
    	{
    		htim1.Instance->CCR2 = i;
    		HAL_Delay(20);
    	}
    	for (int i = 450; i <= 620; i++)
    	{
    		htim1.Instance->CCR1 = i;
    		HAL_Delay(20);
    	}
    	HAL_GPIO_WritePin(GPIOB, LED2_Pin, GPIO_PIN_RESET);
    	clear_wait_ms_ch(channelLED2);
    	while (!wait_ms_ch(channelLED2, 1000)) {}
	}

    return (0);
}


/************************ (C) COPYRIGHT Don't Touch this Button *****END OF FILE****/
