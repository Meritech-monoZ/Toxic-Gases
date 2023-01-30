/**
 * @file MZ_gpio.h
 * @author Mahendra & Kafeel
 * @date Mar 15 2022
 * @brief This file includes Monoz GPIO Related APIs
 */

#ifndef MZ_GPIO_H_
#define MZ_GPIO_H_														///< Defines Inc Monoz GPIO file
#ifdef __cplusplus
extern "C" {
#endif

//#include "MZ_common.h"
#include "MZ_public.h"
#include "MZ_error_handler.h"

typedef _mz_fp _gpio_api;														/*!< Monoz Function Pointer */

/**
 * @struct MZ_GPIOX
 * @brief Structure for GPIO Handling and API events
 */
typedef struct
{
	GPIO_TypeDef			instruction;								    	/*!< GPIO low level handler */
}MZ_GPIOX;



typedef	MZ_GPIOX MZ_GPIOX_BTYPE;												/*!< GPIO Base Type */
typedef	MZ_GPIOX * MZ_GPIOX_BTYPE_PTR;											/*!< GPIO Base Type pointer */



/**
 * @fn mz_error_t MZ_GPIO_ReadPin(MZ_GPIOX_BTYPE_PTR, GPIO_Pin)
 * @brief Monoz GPIO Read Pin
 * @param MZ_GPIOX_BTYPE_PTR GPIO_Pin
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t MZ_GPIO_ReadPin(MZ_GPIOX_BTYPE_PTR, uint16_t GPIO_Pin);

/**
 * @fn mz_error_t MZ_GPIO_WritePin(MZ_GPIOX_BTYPE_PTR, GPIO_Pin,  GPIO_PinState)
 * @brief Monoz GPIO Write Pin
 * @param MZ_GPIOX_BTYPE_PTR GPIO_Pin
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t MZ_GPIO_WritePin(MZ_GPIOX_BTYPE_PTR GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);

/**
 * @fn mz_error_t MZ_GPIO_TogglePin(MZ_GPIOX_BTYPE_PTR, GPIO_Pin)
 * @brief Monoz GPIO Toggle Pin
 * @param MZ_GPIOX_BTYPE_PTR GPIO_Pin
 * @return MZ_OK/MZ_FAIL
 */

mz_error_t MZ_GPIO_TogglePin(MZ_GPIOX_BTYPE_PTR GPIOx, uint16_t GPIO_Pin);

/**
 * @fn mz_error_t MZ_GPIO_LockPin(MZ_GPIOX_BTYPE_PTR, GPIO_Pin)
 * @brief Monoz GPIO Lock Pin
 * @param MZ_GPIOX_BTYPE_PTR GPIO_Pin
 * @return MZ_OK/MZ_FAIL
 */

mz_error_t MZ_GPIO_LockPin(MZ_GPIOX_BTYPE_PTR, uint16_t GPIO_Pin);

/**
 * @fn mz_error_t MZ_GPIO_EXTI_IRQHandler(GPIO_Pin)
 * @brief Monoz GPIO External Interrupt Handler
 * @param GPIO_Pin
 * @return MZ_OK/MZ_FAIL
 */

mz_error_t MZ_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin);

/**
 * @fn mz_error_t MZ_GPIO_EXTI_Callback(GPIO_Pin)
 * @brief Monoz GPIO External Callback
 * @param GPIO_Pin
 * @return MZ_OK/MZ_FAIL
 */

mz_error_t MZ_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

/**
 * @fn mz_error_t  MZ_GPIO_Init(MZ_GPIOX_BTYPE_PTR  *GPIOx, MZ_GPIOX_BTYPE_PTR *GPIO_Init)
 * @brief Monoz MZ_GPIOX_BTYPE_PTR,GPIO Init
 * @param GPIO_Pin
 * @return MZ_OK/MZ_FAIL
 */

mz_error_t  MZ_GPIO_Init(MZ_GPIOX_BTYPE_PTR  GPIOx, MZ_GPIO_INIT_PTR GPIO_Init);

/**
 * @fn mz_error_t MZ_GPIO_DeInit(MZ_GPIOX_BTYPE_PTR  *GPIOx, MZ_GPIOX_BTYPE_PTR *GPIO_Init)
 * @brief Monoz MZ_GPIOX_BTYPE_PTR,GPIO Pin
 * @param GPIO_Pin
 * @return MZ_OK/MZ_FAIL
 */

mz_error_t  MZ_GPIO_DeInit(MZ_GPIOX_BTYPE_PTR  GPIOx, uint32_t GPIO_Pin);

/** @} */

#ifdef __cplusplus
}
#endif
#endif /* MZ_UART_H_ */
