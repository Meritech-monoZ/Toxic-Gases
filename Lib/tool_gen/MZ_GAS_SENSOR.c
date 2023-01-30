/*
 * MZ_GAS_SENSOR.c
 *
 *  Created on: 31-Oct-2022
 *      Author: Piyush
 */

#include "cmsis_os.h"
#include "MZ_sys_cmsis_os2.h"
#include "MZ_timer.h"
#include "MZ_print.h"
#include "MZ_error_handler.h"
#include "MZ_Mqtt_public.h"
#include "MZ_Modem_public.h"
#include "MZ_main.h"
#include "main.h"
#include <stdlib.h>
#include "stdio.h"
#include "string.h"

#include <math.h>
#include <MZ_GAS_SENSOR.h>

/* Application related MACRO - START */
#define GAS_SENSOR_APP_STACK_SIZE			(1024)									/*!< Stack size for the thread */
#define GAS_SENSOR_TX_TIME					(pdMS_TO_TICKS(60000))					/*!< Timer expire time  */
/* Application related MACRO - END */

/* Application related variables - START */
static mz_thread_t 		gas_sensor_thread_id = NULL;								/*!< Thread id handler */
static StaticTask_t 	gas_sensor_cb_mem;											/*!< Thread control block */
static StackType_t 		gas_sensor_stack[GAS_SENSOR_APP_STACK_SIZE];						/*!< Thread stack */
static mz_semaphore_t	adc_sema_id = NULL;									/*!< Semaphore handler */
/* Application related variables - END */

extern uint32_t adcValBuf[ADC_VALUE_BUF_SIZE];
extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

/* Define some common use MACRO - START */
#define GAS_SENSOR_READ_TIMER_EXPIRE_SET	(1)							//< Set the Timer Expire for load cell read
#define GAS_SENSOR_READ_TIMER_EXPIRE_CLEAR	(0)							//< Clear the Timer Expire for load cell read
#define TIME_180SEC							(pdMS_TO_TICKS(180000))		//< Timer is set for 180 seconds
#define TIME_90SEC							(pdMS_TO_TICKS(90000))		//< Timer is set for 90 seconds
#define GAS_SENSOR_DATA_SEND_TIME			(pdMS_TO_TICKS(120000))		//< Timer is set for 10 seconds
#define TIMER_ID_CLEAR						(0)							//< Clear the timer id
/* Define some common use MACRO - END */

/* GAS_SENSORS MACRO - START */
#define PAYLOAD_STRING_SIZE 			250
#define SENSOR_PPM_SIZE					10

#define CO_RATIO_AIR					11.8		//From graph
#define CO_LNE_SLOPE					-0.683		//Calculated Slope
#define CO_Y_INTERCEPT					1.43		//Calculated intercept
#define CO_RL_LOAD_RESISTANCE			10          //The value of resistor RL is 10K
#define CO_R0_RESISTANCE				20          //Calculate value at fresh air is 20K through datasheet graph using formula

#define CH4_RATIO_AIR					4.4			//From graph
#define CH4_LNE_SLOPE					-0.354		//Calculated Slope
#define CH4_Y_INTERCEPT					1.03		//Calculated intercept
#define CH4_RL_LOAD_RESISTANCE			10          //The value of resistor RL is 10K
#define CH4_R0_RESISTANCE				20          //Calculate value at fresh air is 20K through datasheet graph using formula

#define CO2_ZERO_POINT_VOLTAGE 			0.039 		//Define the output of the sensor in volts when the concentration of CO2 is 400PPM
#define CO2_REACTION_VOLTGAE 			0.030 		//Define the voltage drop of the sensor when move the sensor from air into 1000ppm CO2
#define CO2_LOG400_VALUE				2.602       //Value of log(400)
#define CO2_LOG1000_VALUE				3			//Value of log(1000)
#define CO2_DC_GAIN 					8.5			//Define the DC gain of amplifier

#define DELAY_100MS						100

#define LOG_POWER10 					10

#define INPUT_VOLTAGE					3.3
#define MAX_ADC_COUNT					4095
#define ANALOG_SAMPLE_COUNT				100

#define ADC_HAL_TIMEOUT					100

#define FLAG_SET						1
#define FLAG_CLEAR						0

#define SET								1
#define CLEAR							0

#define INIT_0    						0
#define FLOAT_0    						0.0
/* GAS_SENSORS MACRO - END */

/* GAS_SENSORS Global Variables and Buffer - START */
static int8_t dataTxReady = INIT_0;  	//data transmit ready flag
static int8_t timerCBFlag = INIT_0;  	//timer callback flag

static char  coPPM[SENSOR_PPM_SIZE] = {0};		/*!< Store Carbon Monoxide PPM value after calculation from raw value and decimal place */
static char  ch4PPM[SENSOR_PPM_SIZE] = {0};		/*!< Store Methane PPM value after calculation from raw value and decimal place */
static char  co2PPM[SENSOR_PPM_SIZE] = {0};		/*!< Store Carbon Dioxide PPM value after calculation from raw value and decimal place */

static char gas_sensor_read_timer_expire_flag = GAS_SENSOR_READ_TIMER_EXPIRE_CLEAR;	/*!< Flag is created and cleared for sensor data read */
static size_t gas_sensor_data_timer_id = TIMER_ID_CLEAR;					/*!< gas_sensor timer id - Initialize it to 0 */
/* GAS_SENSORS Global Variables and Buffer - END */

/* MQTT related MACRO and variables - START */
static char payload_string[PAYLOAD_STRING_SIZE] = "";				/*!< payload string buffer to pass the final payload information to MonoZ_Lib */
static st_mqtt_message pmsg;
/* MQTT related MACRO and variables - END */

static void create_mqtt_payload(st_mqtt_message * pmsg , char * buff);
static void send_payload_to_server(st_mqtt_message * pmsg);

#define MZ_MQTT_PUB_TOPIC 		"\"v1/devices/me/telemetry\""
#define MZ_MQTT_PUB_QOS			MQTT_QOS0
#define MZ_MQTT_SUB_TOPIC		"\"v1/devices/me/attributes\""
#define MZ_MQTT_SUB_QOS			MQTT_QOS2
#define MZ_CO_PPM				"CO_PPM"
#define MZ_CH4_PPM				"CH4_PPM"
#define MZ_CO2_PPM				"CO2_PPM"

/* @fn void timer_cb(TimerHandle_t xTimer)
 * @brief timer callback function notifies when timer expires
 * @param xTimer TimerHandle_t
 * gas sensor transmission timer callback - START
 * This Timer callback will be called after the gas sensor transmission timer is expired.
 */
static void timer_cb(TimerHandle_t xTimer)
{
	gas_sensor_read_timer_expire_flag = GAS_SENSOR_READ_TIMER_EXPIRE_SET;
}
/* gas sensor transmission timer callback - END */

/** @fn static void gas_sensor_data_timer_cb(TimerHandle_t xTimer)
 * @brief gas_sensor_data_timer_cb timer callback - START
 * This Timer callback will be called after the loadcell_data timer is
 * expired.The timer value is set as LOADCELL_DATA_SEND_TIME
 * @param xTimer TimerHandle_t
 * @retval None
 */
static void gas_sensor_data_timer_cb(TimerHandle_t xTimer)
{
	/* Stopping the loadcell data one time timer */
	if(MZ_OK != mz_tm_stop(gas_sensor_data_timer_id))
	{
		/* print of error stopping on CLI */
		mz_puts("gas sensor data timer stopping failed\r\n");
	}
    else {} // Default waiting case.

	HAL_Delay(DELAY_100MS);
	dataTxReady = FLAG_SET;

	/* Print when the application is ready for data transmission */
	mz_puts("Ready for data Transmission\r\n");
}
/* Sensor transmission timer callback - END */

/** @fn static void create_mqtt_payload(void)
 * @brief MQTT Create payload API - START
 * This API will be used to create the payload string/buffer from load cell final
 * value received after processing of raw value.
 */
static void create_mqtt_payload(st_mqtt_message * pmsg , char * buff)
{
	sprintf(buff,"{\"%s\":%s,\"%s\":%s,\"%s\":%s}%c",MZ_CO_PPM, coPPM, MZ_CH4_PPM, ch4PPM, MZ_CO2_PPM, co2PPM, 26);

	pmsg->topic = MZ_MQTT_PUB_TOPIC;
	pmsg->qos = MZ_MQTT_PUB_QOS;
	pmsg->retain = MQTT_RETAIN_OFF;
	pmsg->message = buff;
}
/* MQTT Create payload API - END */

/** @fn static void send_payload_to_server(void)
 * @brief MQTT send payload API - START
 * This API will be used to send the payload string/buffer to MonoZ_Lib.
 * It will also print if the sending of payload to MonoZ_Lib was successful or
 * any error occurred
 */
static void send_payload_to_server(st_mqtt_message * pmsg)
{
	/* Set the mqtt Data and send to MonoZ_Lib */
	mz_error_t status = MZ_init_cmd_direct("AT+QMTDISC=0\r\n", AT_TIME_15SEC, AT_TIME_15SEC);
	status |= MZ_init_cmd_direct("AT+QMTOPEN=0,\"cloud.monoz.io\",1883\r\n", AT_TIME_15SEC, AT_TIME_15SEC);
	status |= MZ_init_cmd_direct("AT+QMTCONN=0,\"gas_sensor\",\"gas_sensor\",\"Meritech123\"\r\n", AT_TIME_15SEC, AT_TIME_15SEC);
	status |= MZ_init_cmd_direct("AT+QMTPUB=0,0,0,0,\"v1/devices/me/telemetry\"\r\n", AT_TIME_15SEC, 0);
	status |= MZ_init_cmd_direct(payload_string, AT_TIME_15SEC, AT_TIME_15SEC);

	/* Check the status of the request */
	if(MZ_OK == status)
	{
		/* print success on CLI */
		mz_puts("Data send to MonoZ_Lib\r\n");
	}
	else
	{
		/* print of error string on CLI */
		mz_puts("Data send to MonoZ_Lib FAILED\r\n");
	}
}
/* MQTT send_payload_to_server - END */

/* @fn void gas_sensor_adc_app(void * arg)
 * @brief create the timer and start when the starts if main RTOS scheduler started
 * @param arg void
 * gas_sensor_adc_app. - START
 * 1. It Create and start ADC transmission timer
 * 2. Process other actions on the thread loop
 */
static void gas_sensor_adc_app(void * arg)
{
	(void)arg;

	/* GAS_SENSORS Local Variables and Buffer - START */

	uint32_t coAdcVal = INIT_0;				//Define variable for sensor adc value
	uint32_t ch4AdcVal = INIT_0;			//Define variable for sensor adc value
	uint32_t co2AdcVal = INIT_0;			//Define variable for sensor adc value

	float coSensorVolt = FLOAT_0; 			//Define variable for sensor voltage
	float co2SensorVolt = FLOAT_0; 			//Define variable for sensor voltage
	float coRsGas = FLOAT_0;				//Define variable for sensor resistance
	float coRatio = FLOAT_0; 				//Define variable for ratio
	float coR0 = CO_R0_RESISTANCE; 	   		//Define variable for R0 calculate

	float ch4SensorVolt = FLOAT_0; 			//Define variable for sensor voltage
	float ch4RsGas = FLOAT_0;				//Define variable for sensor resistance
	float ch4Ratio = FLOAT_0; 				//Define variable for ratio
	float ch4R0 = CH4_R0_RESISTANCE; 	   	//Define variable for R0 calculate

	float coM = CO_LNE_SLOPE; 				//Define variable for Slope
	float coB = CO_Y_INTERCEPT; 			//Define variable for Y-Intercept

	float ch4M = CH4_LNE_SLOPE; 			//Define variable for Slope
	float ch4B = CH4_Y_INTERCEPT; 			//Define variable for Y-Intercept

	float CO2Curve[3] = {CO2_LOG400_VALUE, CO2_ZERO_POINT_VOLTAGE, (CO2_REACTION_VOLTGAE / (CO2_LOG400_VALUE - CO2_LOG1000_VALUE))};

	float coPpmlog = FLOAT_0;				//Define variable for PPM log
	double coPpmVal = FLOAT_0;				//Define variable for PPM value

	float ch4Ppmlog = FLOAT_0;				//Define variable for PPM log
	double ch4PpmVal = FLOAT_0;				//Define variable for PPM value

	double co2PpmVal = FLOAT_0;				//Define variable for PPM value
	/* GAS_SENSORS Local Variables and Buffer - END */

	/* Create the gas sensor data timer.*/
	/* As per requirement, We are creating a One-time timer using */
	gas_sensor_data_timer_id = mz_tm_create_one("gas sensor data timer",
												GAS_SENSOR_DATA_SEND_TIME,
												gas_sensor_data_timer_cb);

	/* create the gas sensor transmission timer.
	 * As per requirement, We are creating a recursive timer using
	 * mz_tm_create_start_recursive() API.
	 * In-case of other type of timer, please refer MZ_timer.h
	 * The expire time for this timer set to GAS_SENSOR_TX_TIME.
	 * "timer_cb" is passed as an argument.
	 * When the timer expires, the "timer_cb" API will be processed.
	 */
	if(MZ_OK == mz_tm_create_start_recursive("ADC transmission timer",
											GAS_SENSOR_TX_TIME,
											timer_cb))
	{
		/* Timer create and start. */
		mz_puts("Gas sensor reading timer started\r\n");
	}
    else {} // Default waiting case.

	/* This is the infinite loop for this thread - the thread will execute this
	 * loop forever and not come outside of this loop
	 */
	while(1)
	{
		/* Send data to MQTT server */
		if(dataTxReady == FLAG_SET)
		{
			/* Need to write the periodic executing logic in this loop block */
			/* Read analog values of sensor */
			/* Start for loop */
			for(int32_t noSample = 0; noSample < ANALOG_SAMPLE_COUNT; noSample++)
			{
				/* Add analog values of sensor ANALOG_SAMPLE_COUNT times */
				coAdcVal = coAdcVal + adcValBuf[0];
				ch4AdcVal = ch4AdcVal + adcValBuf[1];
				co2AdcVal = co2AdcVal + adcValBuf[2];
			}
			/* Take average of readings */
			coAdcVal = coAdcVal / ANALOG_SAMPLE_COUNT;
			ch4AdcVal = ch4AdcVal / ANALOG_SAMPLE_COUNT;
			co2AdcVal = co2AdcVal / ANALOG_SAMPLE_COUNT;

			/* Convert analog values to voltage */
			coSensorVolt = coAdcVal * (INPUT_VOLTAGE / MAX_ADC_COUNT);
			HAL_Delay(DELAY_10MS);
			ch4SensorVolt = ch4AdcVal * (INPUT_VOLTAGE / MAX_ADC_COUNT);
			HAL_Delay(DELAY_10MS);
			co2SensorVolt = co2AdcVal * (INPUT_VOLTAGE / MAX_ADC_COUNT);
			HAL_Delay(DELAY_10MS);

			/* Get value of RS in a gas (RS = [(Vin x RL) / Vout] - RL) */
			coRsGas = ((INPUT_VOLTAGE * CO_RL_LOAD_RESISTANCE) / coSensorVolt) - CO_RL_LOAD_RESISTANCE;
			HAL_Delay(DELAY_10MS);
			ch4RsGas = ((INPUT_VOLTAGE * CH4_RL_LOAD_RESISTANCE) / ch4SensorVolt) - CH4_RL_LOAD_RESISTANCE;

			/* Get ratio RS_gas/RS_air */
			coRatio = coRsGas / coR0;
			HAL_Delay(DELAY_10MS);
			ch4Ratio = ch4RsGas / ch4R0;
			HAL_Delay(DELAY_10MS);

			/* Get ppm value in linear scale according to the the ratio value x = 10 ^ {[log(y) - b] / m} */
			coPpmlog = (log10(coRatio) - coB) / coM;
			HAL_Delay(DELAY_10MS);
			ch4Ppmlog = (log10(ch4Ratio) - ch4B) / ch4M;
			HAL_Delay(DELAY_10MS);

			/* Use formula to calculate ppm pow(10, value) */
			coPpmVal = pow(LOG_POWER10, coPpmlog);
			HAL_Delay(DELAY_10MS);
			ch4PpmVal = pow(LOG_POWER10, ch4Ppmlog);
			HAL_Delay(DELAY_10MS);
			co2PpmVal = pow(LOG_POWER10, ((co2SensorVolt / CO2_DC_GAIN) - CO2Curve[1]) / CO2Curve[2] + CO2Curve[0]);
			HAL_Delay(DELAY_10MS);

			/* Converts a floating-point/double number to a string */
			sprintf(coPPM, "%.2f", coPpmVal);
			sprintf(ch4PPM, "%.2f", ch4PpmVal);
			sprintf(co2PPM, "%.2f", co2PpmVal);

			HAL_Delay(DELAY_10MS);
			/* Create the payload from the received data */
			create_mqtt_payload(&pmsg, payload_string);

			/* send the payload to mqtt server */
			send_payload_to_server(&pmsg);

			dataTxReady = FLAG_CLEAR;
			timerCBFlag = FLAG_CLEAR;
		}
		else {} // Default waiting case.

		if(timerCBFlag == FLAG_CLEAR)
		{
			timerCBFlag = FLAG_SET;
			/* Starting the gas sensor data one time timer */
			if(MZ_OK != mz_tm_start(gas_sensor_data_timer_id))
			{
				/* print of error string on CLI */
				mz_puts("gas sensor data timer creation failed\r\n");
			}
			else {} // Default waiting case.
		}
		else {} // Default waiting case.

		/* Put a delay to avoid blocking on this thread */
		HAL_Delay(DELAY_10MS);
	}//End of while(1) - Do not place any code after this.
}
/* gas_sensor_adc_app - END */

/**
 * @fn mz_error_t gas_sensor_app_init(void)
 * gas_sensor_app initialization . - START
 * It create the main gas sensor application
 * @brief Initialize gas_sensor App and creates the gas sensor application thread
 * @return _ret returns the gas sensor app thread creation status
 * @note creates the semaphore to lock the process when multiple processes are in run status
 */
mz_error_t gas_sensor_app_init(void)
{
	mz_error_t _ret = MZ_OK;
	/* Create the gas sensor application threads */
	if(!mz_thread_create(	&gas_sensor_thread_id,
							"Gas Sensor app Scheduler",
							gas_sensor_adc_app,
							NULL,
							osPriorityNormal,
							gas_sensor_stack,
							GAS_SENSOR_APP_STACK_SIZE,
							&gas_sensor_cb_mem,
							sizeof(gas_sensor_cb_mem)))
	{
		_ret = MZ_THREAD_CREATE_FAIL;
	}
	else {} // Default waiting case.

	/* Create lock with already locked */
	if(!mz_sem_create(&adc_sema_id,1U,1U))
	{
		_ret = MZ_SEMA_CREATE_FAIL;
	}
	else {} // Default waiting case.

	return _ret;
}
/* gas_sensor_app initialization . - END */


