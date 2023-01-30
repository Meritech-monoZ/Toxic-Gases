/** @file MZ_BoardCfg.h
 * @date Apr 13, 2021
 * @author SKM
 * @brief Configaration of Monoz Board
 * This file defines the Hardware and Software features enabled in Monoz Library for the specific board.
 */


#ifndef MZ_BOARDCFG_H_
#define MZ_BOARDCFG_H_                                                          ///< Defines Monoz Board Config
#ifdef __cplusplus
extern "C" {
#endif

#define MZ_ENABLE						(1)                         ///< Enables the monoz
#define	MZ_DISABLE						(0)                         ///< Disables the monoz

/*
 * This file defines the Hardware and Software features enabled in Monoz Library for the specific board
 */

// Hardware Interfaces configured in library for this board
#define MZ_UART1						(MZ_ENABLE)             ///< Enables the UART1
#define MZ_UART2						(MZ_ENABLE)             ///< Enables the UART2
#define MZ_UART3						(MZ_DISABLE)             ///< Enables the UART3
#define MZ_UART4						(MZ_DISABLE)             ///< Enables the UART
#define MZ_LPUART1						(MZ_DISABLE)             ///< Enables the LPUART1
#define MZ_I2C1							(MZ_DISABLE)             ///< Enables the I2C1
#define MZ_I2C2							(MZ_DISABLE)             ///< Enables the I2C2
#define MZ_I2C4							(MZ_DISABLE)             ///< Enables the I2C4
#define MZ_SPI1							(MZ_DISABLE)             ///< Enables the SPI1
#define MZ_SPI2							(MZ_DISABLE)             ///< Enables the SPI2
#define MZ_SPI3							(MZ_DISABLE)             ///< Enables the SPI4
#define MZ_ADC1						 	(MZ_ENABLE)             ///< Enables the ADC1
#define MZ_ADC2						 	(MZ_ENABLE)             ///< Enables the ADC2
#define MZ_ADC3						 	(MZ_ENABLE)            	///< Enables the ADC3

// Software Modules Configured in library for this board
#define MZ_MODEM						(MZ_ENABLE)				///< UART1 is attached to Modem Interface
#define MZ_CLI							(MZ_ENABLE)				///< UART2 is attached to CLI Interface

// Driver configured in library for this board
#define MZ_LWM2M_ENABLE					(MZ_DISABLE)                ///< Enables the monoz lwm2m
#define MZ_MQTT_ENABLE					(MZ_ENABLE)                 ///< Enables the monoz mqtt
#define MZ_FLASH_DRIVER_ENABLE			(MZ_ENABLE)                 ///< Enables monoz flash driver

// Features configured in library for this board
#define MZ_FLASH_CONFIG_ENABLE			(MZ_ENABLE)                 ///< Enables the flash configuration

#if(MZ_FLASH_CONFIG_ENABLE == 1)
#if (MZ_FLASH_DRIVER_ENABLE != 1)
#error Need to enable MZ_FLASH_DRIVER_ENABLE to use MZ_FLASH_CONFIG_ENABLE
#endif
#endif // MZ_FLASH_CONFIG_ENABLE

#define MZ_ERROR_TO_STRING				(MZ_ENABLE)                 ///< Enables the monoz error to string conversion

// Define Modem type
#define MZ_MODEM_MURATA					(MZ_DISABLE)								///< Defines the Modem Type
#define MZ_MODEM_SIMCOM					(MZ_DISABLE)								///< Defines the Modem Type
#define MZ_MODEM_QUECTEL				(MZ_ENABLE)									///< Defines the Modem Type
#define MZ_SDK_ADVANCE_AT_INJECT		(MZ_DISABLE)                ///< Disables the SDK advanced AT inject
//(MZ_DISABLE MZ_ENABLE)


// MAXIMUM NUMBER OF SW TIMER
#define MZ_MAX_TIMER_COUNT				(5)										///< Defines the Maximum number of SW timer
#define MZ_AT_TIMERS					(1)                         ///< Defines the monoz AT timers


#ifdef __cplusplus
}
#endif
#endif /* MZ_BOARDCFG_H_ */
