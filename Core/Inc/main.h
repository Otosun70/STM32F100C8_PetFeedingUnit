/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define NSLEEP_Pin GPIO_PIN_5
#define NSLEEP_GPIO_Port GPIOA
#define MOTOR1_1_Pin GPIO_PIN_6
#define MOTOR1_1_GPIO_Port GPIOA
#define MOTOR1_2_Pin GPIO_PIN_7
#define MOTOR1_2_GPIO_Port GPIOA
#define MOTOR2_2_Pin GPIO_PIN_0
#define MOTOR2_2_GPIO_Port GPIOB
#define MOTOR2_1_Pin GPIO_PIN_1
#define MOTOR2_1_GPIO_Port GPIOB
#define NFAULT_Pin GPIO_PIN_2
#define NFAULT_GPIO_Port GPIOB
#define LED_ALARM_Pin GPIO_PIN_10
#define LED_ALARM_GPIO_Port GPIOB
#define SERVO_2_Pin GPIO_PIN_14
#define SERVO_2_GPIO_Port GPIOB
#define AKIS_SENS_Pin GPIO_PIN_15
#define AKIS_SENS_GPIO_Port GPIOB
#define AKIS_SENS_EXTI_IRQn EXTI15_10_IRQn
#define SERVO_POWER_Pin GPIO_PIN_15
#define SERVO_POWER_GPIO_Port GPIOA
#define KEY_1_Pin GPIO_PIN_3
#define KEY_1_GPIO_Port GPIOB
#define KEY_2_Pin GPIO_PIN_4
#define KEY_2_GPIO_Port GPIOB
#define KEY_3_Pin GPIO_PIN_5
#define KEY_3_GPIO_Port GPIOB
#define KEY_4_Pin GPIO_PIN_6
#define KEY_4_GPIO_Port GPIOB
#define KEY_5_Pin GPIO_PIN_7
#define KEY_5_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
