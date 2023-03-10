/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#include "stm32l4xx_hal.h"


/* Define variable to store the adc values */

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
#define ADC_VALUE_BUF_SIZE				3
#define DELAY_10MS						10

#define CLK_32_IN_Pin 					GPIO_PIN_14
#define CLK_32_IN_GPIO_Port 			GPIOC
#define CLK_32_OUT_Pin 					GPIO_PIN_15
#define CLK_32_OUT_GPIO_Port 			GPIOC
#define MODEM_RESET_N_Pin 				GPIO_PIN_0
#define MODEM_RESET_N_GPIO_Port 		GPIOC
#define HOST_WAKEUP_Pin 				GPIO_PIN_1
#define HOST_WAKEUP_GPIO_Port 			GPIOC
#define HOST_WAKEUP_EXTI_IRQn 			EXTI1_IRQn
#define MODEM_POWERKEY_Pin 				GPIO_PIN_2
#define MODEM_POWERKEY_GPIO_Port 		GPIOC
#define MODEM_REST_STATUS_Pin 			GPIO_PIN_3
#define MODEM_REST_STATUS_GPIO_Port 	GPIOC
#define MODEM_REST_STATUS_EXTI_IRQn 	EXTI3_IRQn
#define CLI_USART_TX_Pin 				GPIO_PIN_2
#define CLI_USART_TX_GPIO_Port 			GPIOA
#define CLI_USART_RX_Pin 				GPIO_PIN_3
#define CLI_USART_RX_GPIO_Port			GPIOA
#define MODEM_USART_TX_Pin 				GPIO_PIN_9
#define MODEM_USART_TX_GPIO_Port 		GPIOA
#define MODEM_USART_RX_Pin 				GPIO_PIN_10
#define MODEM_USART_RX_GPIO_Port 		GPIOA
#define LED_BLUE_Pin 					GPIO_PIN_7
#define LED_BLUE_GPIO_Port 				GPIOB
#define LED_GREEN_Pin 					GPIO_PIN_8
#define LED_GREEN_GPIO_Port 			GPIOB
#define LED_RED_Pin 					GPIO_PIN_9
#define LED_RED_GPIO_Port 				GPIOB
#define SPI1_CS_Pin 					GPIO_PIN_12
#define SPI1_CS_GPIO_Port 				GPIOE
#define CAM_FLASH_Pin 					GPIO_PIN_0
#define CAM_FLASH_Pin_GPIO_Port 		GPIOG
//Sensor
#define TPH_SEN_SPI_CS_Pin 				GPIO_PIN_12
#define TPH_SEN_SPI_CS_Pin_GPIO_Port 	GPIOB
#define CS_ACCRL_Pin 					GPIO_PIN_13
#define CS_ACCRL_GPIO_Port 				GPIOF
#define CS_GYRO_Pin 					GPIO_PIN_14
#define CS_GYRO_GPIO_Port 				GPIOF
#define CS_MAGT_Pin 					GPIO_PIN_15
#define CS_MAGT_GPIO_Port 				GPIOF

/* USER CODE BEGIN Private defines */
extern volatile char init_complete;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
