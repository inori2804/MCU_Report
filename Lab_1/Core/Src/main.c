/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
	void display7SEG(int num) {
		switch (num) {
//		using output data register to set value for port B
		case 0: {
//			using operator & with 0xFF00 to reset 8bits low
			GPIOB->ODR &= 0xFF00;
//			set value to 8bits low by using operator & to retain 8bits high
			GPIOB->ODR |= 0x0040;
			break;
		}
		case 1: {
			GPIOB->ODR &= 0xFF00;
			GPIOB->ODR |= 0x0079;
			break;
		}
		case 2: {
			GPIOB->ODR &= 0xFF00;
			GPIOB->ODR |= 0x0024;
			break;
		}
		case 3: {
			GPIOB->ODR &= 0xFF00;
			GPIOB->ODR |= 0x0030;
			break;
		}
		case 4: {
			GPIOB->ODR &= 0xFF00;
			GPIOB->ODR |= 0x0019;
			break;
		}
		case 5: {
			GPIOB->ODR &= 0xFF00;
			GPIOB->ODR |= 0x0012;
			break;
		}
		case 6: {
			GPIOB->ODR &= 0xFF00;
			GPIOB->ODR |= 0x0002;
			break;
		}
		case 7: {
			GPIOB->ODR &= 0xFF00;
			GPIOB->ODR |= 0x0078;
			break;
		}
		case 8: {
			GPIOB->ODR &= 0xFF00;
			GPIOB->ODR |= 0x0000;
			break;
		}
		case 9: {
			GPIOB->ODR &= 0xFF00;
			GPIOB->ODR |= 0x0010;
			break;
		}
		default:
			break;
		}
	}
//	similar with function display7SEG but using 8bits high
	void display7SEG_1(int num) {
		switch (num) {
		case 0: {
			GPIOB->ODR &= 0x00FF;
			GPIOB->ODR |= 0x4000;
			break;
		}
		case 1: {
			GPIOB->ODR &= 0x00FF;
			GPIOB->ODR |= 0x7900;
			break;
		}
		case 2: {
			GPIOB->ODR &= 0x00FF;
			GPIOB->ODR |= 0x2400;
			break;
		}
		case 3: {
			GPIOB->ODR &= 0x00FF;
			GPIOB->ODR |= 0x3000;
			break;
		}
		case 4: {
			GPIOB->ODR &= 0x00FF;
			GPIOB->ODR |= 0x1900;
			break;
		}
		case 5: {
			GPIOB->ODR &= 0x00FF;
			GPIOB->ODR |= 0x1200;
			break;
		}
		case 6: {
			GPIOB->ODR &= 0x00FF;
			GPIOB->ODR |= 0x0200;
			break;
		}
		case 7: {
			GPIOB->ODR &= 0x00FF;
			GPIOB->ODR |= 0x7800;
			break;
		}
		case 8: {
			GPIOB->ODR &= 0x00FF;
			GPIOB->ODR |= 0x0000;
			break;
		}
		case 9: {
			GPIOB->ODR &= 0x00FF;
			GPIOB->ODR |= 0x1000;
			break;
		}
		default:
			break;
		}
	}
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
	// set init state for each led
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);

	// set time for each led
	int time_red = 5;
	int time_yellow = 2;
	int time_green = 3;

	int count = -1;

	// calculate time for each led to switch state
	int count_red = count + time_red; // = 4
	int count_green1 = count_red + time_green; // = 7
	int count_green2 = count + time_green; // = 2
	int count_yellow = count_green1 + time_yellow; // = 9
//	set count down time for led7seg and lef7seg1
	int count_down_7seg = time_red - 1;
	int count_down_7seg1 = time_green - 1;

/* USER CODE END 2 */

/* Infinite loop */
/* USER CODE BEGIN WHILE */
	while (1) {
//		divide one cycle 10 unit time to 3 phase for each traffic light (TL) 1 and 2

//		phase 1 - TL 2: 1->3 is green on, red and yellow off
		if (count == count_green2) {
			HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);

			count_down_7seg1 = time_yellow - 1;
		}
//		phase 1 - TL 1: 1->5 is red on, green and yellow off
		if (count == count_red) {
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
//		phase 2 - TL 2: 3->5 is yellow on, red and green off
			HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
			HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);

			count_down_7seg = time_green - 1;
			count_down_7seg1 = time_red - 1;
		}
//		phase 2 - TL 1: 5->8 is green on, yellow and red off
		if (count == count_green1) {
			HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);

			count_down_7seg = time_yellow - 1;
		}
//		phase 3 - TL 1: 8->10 is yellow on, red and green off
		if (count == count_yellow) {
			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//		phase 3 - TL 2: 5->10 is red on, green and yellow off
			HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
			HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);

			count_down_7seg = time_red - 1;
			count_down_7seg1 = time_green - 1;
		}

		count++;
//		check if it finish one cycle, if yes then reset variable count
		if (count > time_red + time_yellow + time_green - 1)
			count = 0;
		if (count_down_7seg >= 0)
			display7SEG(count_down_7seg);
		count_down_7seg--;

		if (count_down_7seg1 >= 0)
			display7SEG_1(count_down_7seg1);
		count_down_7seg1--;

		HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|LED_GREEN1_Pin
                          |LED_YELLOW1_Pin|LED_RED1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_Pin LED_YELLOW_Pin LED_GREEN_Pin LED_GREEN1_Pin
                           LED_YELLOW1_Pin LED_RED1_Pin */
  GPIO_InitStruct.Pin = LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|LED_GREEN1_Pin
                          |LED_YELLOW1_Pin|LED_RED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB10
                           PB11 PB12 PB13 PB14
                           PB3 PB4 PB5 PB6
                           PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
