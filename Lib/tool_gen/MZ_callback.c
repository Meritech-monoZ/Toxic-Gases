/*
 * MZ_callback.c
 *
 *  Created on: Apr 2, 2021
 *      Author: MZ_click
 *  This is a tool generated file. Do not edit manually
 *  Just use it as a template to create user specific event check
 */

#include "MZ_error_handler.h"
#include "MZ_tool_gen.h"

#define AWS_MQTT_ENABLE 		0

#if(MZ_LWM2M_ENABLE == 1)
#endif

#if(MZ_MQTT_ENABLE == 1)
#endif


/* NOTE : This function can be modified, when the callback is needed,
          the mz_default_callback can be implemented in the user file also.
*/
__attribute__((weak)) void mz_default_callback(void * evnt)
{
	mz_error_t e = *((mz_error_t *)evnt);

	switch(e)
	{
		case MZ_FAIL:
			/* Do something */
			;
		break;
		default:
		break;
	}
}

/* NOTE : This function can be modified, when the callback is needed,
          the mz_hw_default_callback can be implemented in the user file also.
*/
__attribute__((weak)) void mz_hw_default_callback(void * evnt)
{
	mz_error_t e = *((mz_error_t *)evnt);

	switch(e)
	{
		case MZ_FAIL:
			/* Do something */
			;
		break;
		default:
		break;
	}
}

/* NOTE : This function can be modified, when the callback is needed,
          the mz_mod_default_callback can be implemented in the user file also.
*/
__attribute__((weak)) void mz_mod_default_callback(void * evnt)
{
	mz_error_t e = *((mz_error_t *)evnt);

	switch(e)
	{
		case MZ_FAIL:
			/* Do something */
			;
		break;
		default:
		break;
	}
}

/* NOTE : This function can be modified, when the callback is needed,
          the mz_device_info_default_callback can be implemented in the user file also.
*/
__attribute__((weak)) void mz_device_info_default_callback(void * evnt)
{
	mz_error_t e = *((mz_error_t *)evnt);

	switch(e)
	{
		case MZ_FAIL:
			/* Do something */
			;
		break;
		default:
		break;
	}
}

/* NOTE : This function can be modified, when the callback is needed,
          the mz_pro_default_callback can be implemented in the user file also.
*/
__attribute__((weak)) void mz_pro_default_callback(void * evnt)
{
#if(MZ_LWM2M_ENABLE == MZ_ENABLE)
	lwm2m_event_process(evnt);
#endif
#if(MZ_MQTT_ENABLE == MZ_ENABLE)
	#if AWS_MQTT_ENABLE
		aws_mqtt_event_process(evnt);
	#else
		//mqtt_event_process(evnt);
		//(void)mqtt_sensor_event_process(evnt);
	#endif
#endif
}
