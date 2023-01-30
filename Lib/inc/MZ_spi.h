/*
 * MZ_spi.h
 *
 *  Created on: Jul 19, 2021
 *      Author: Mahendra & Kafeel
 */

#ifndef INC_MZ_SPI_H_
#define INC_MZ_SPI_H_

#include "MZ_public.h"
#include "MZ_common.h"
#include "MZ_error_handler.h"
#include "stm32l4xx_hal_spi.h"


typedef enum
{
#if(MZ_SPI1 == 1)
	_SPI1,
#endif
#if(MZ_SPI2 == 1)
	_SPI2,
#endif
#if(MZ_SPI3 == 1)
	_SPI3,
#endif
	SPI_MAX_COUNT
}en_spi_no;

#define SPI_MAX_COUNT_SIZE SPI_MAX_COUNT

typedef _mz_fp _spi_api;

typedef struct
{
	mzReg					_reg_status;										/*!< SPI registration status */
	SPI_HandleTypeDef 		_handler;											/*!< SPI low level handler */
	mzUint8 				_enable;											/*!< SPI enable flag */
	mzUint8 				*_rx_buffer;										/*!< SPI RX buffer address */
	mzUint32				_rx_buffer_size;									/*!< SPI RX buffer size */
	mzUint8 				*_tx_buffer;										/*!< SPI TX buffer address */
	mzUint32				_tx_buffer_size;									/*!< SPI TX buffer size */
	mzUint8 				_rx_intr;											/*!< SPI RX interrupt enable flag */
	mzUint8 				_tx_intr;											/*!< SPI TX interrupt enable flag */
	_spi_api 				read;												/*!< SPI Read API */
	_spi_api 				write;												/*!< SPI Write API */
	_spi_api 				rx_intr_api;										/*!< SPI RX interrupt handler API */
	_spi_api 				tx_intr_api;										/*!< SPI TX interrupt handler API */
	_spi_api 				SPI_ev_call_back;									/*!< SPI event callback API */
}MZ_SPIX;

typedef struct
{
	SPI_HandleTypeDef	*spi_ptr;
	enum
	{
		SPI_FULL_COMPLETE,
		SPI_HALF_COMPLETE,
	}event;
}st_spi_intr;

typedef	MZ_SPIX MZ_SPI_BTYPE;													/*!< SPI Base Type */
typedef	MZ_SPIX * MZ_SPI_BTYPE_PTR;												/*!< SPI Base Type pointer */

MZ_SPI_BTYPE_PTR MZ_SPI_get_base_address(void);									/*!< Get the base address of the SPI internal context */
MZ_SPI_BTYPE_PTR MZ_SPI_reference(en_spi_no spi_no);
mz_error_t MZ_SPI_init(MZ_SPI_INIT_PTR _cfg);									/*!< Register a SPI. Need to call from Upper layer */
mz_error_t MZ_SPI_register_callback(uint8_t spi_no, _spi_api cb);
mz_error_t MZ_SPI_register_intr_cb_tx(uint8_t spi_no, _spi_api cb);
mz_error_t MZ_SPI_register_intr_cb_rx(uint8_t spi_no, _spi_api cb);
void MZ_HAL_SPI_IRQHandler(uint8_t spi_no);										/*!< Global Interrupt handler function */
mz_error_t MZ_SPI_Transmit(uint8_t spi_no, uint8_t *pData, uint16_t Size, uint32_t Timeout);
mz_error_t MZ_SPI_Receive(uint8_t spi_no, uint8_t *pData, uint16_t Size, uint32_t Timeout);
mz_error_t MZ_SPI_TransmitReceive(uint8_t spi_no, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size,
                                          uint32_t Timeout);
mz_error_t MZ_SPI_Transmit_IT(uint8_t spi_no, uint8_t *pData, uint16_t Size);
mz_error_t MZ_SPI_Receive_IT(uint8_t spi_no, uint8_t *pData, uint16_t Size);
mz_error_t MZ_SPI_TransmitReceive_IT(uint8_t spi_no, uint8_t *pTxData, uint8_t *pRxData,
                                             uint16_t Size);



#endif /* INC_MZ_SPI_H_ */
