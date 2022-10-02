/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LABEL_A_Pin GPIO_PIN_4
#define LABEL_A_GPIO_Port GPIOA
#define LABEL_B_Pin GPIO_PIN_5
#define LABEL_B_GPIO_Port GPIOA
#define LABEL_C_Pin GPIO_PIN_6
#define LABEL_C_GPIO_Port GPIOA
#define LABEL_D_Pin GPIO_PIN_7
#define LABEL_D_GPIO_Port GPIOA
#define LABEL_E_Pin GPIO_PIN_8
#define LABEL_E_GPIO_Port GPIOA
#define LABEL_F_Pin GPIO_PIN_9
#define LABEL_F_GPIO_Port GPIOA
#define LABEL_G_Pin GPIO_PIN_10
#define LABEL_G_GPIO_Port GPIOA
#define LABEL_H_Pin GPIO_PIN_11
#define LABEL_H_GPIO_Port GPIOA
#define LABEL_I_Pin GPIO_PIN_12
#define LABEL_I_GPIO_Port GPIOA
#define LABEL_J_Pin GPIO_PIN_13
#define LABEL_J_GPIO_Port GPIOA
#define LABEL_K_Pin GPIO_PIN_14
#define LABEL_K_GPIO_Port GPIOA
#define LABEL_L_Pin GPIO_PIN_15
#define LABEL_L_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
