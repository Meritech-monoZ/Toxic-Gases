/*
 * MZ_Mqtt_public.h
 *
 *  Created on: Oct 6, 2021
 *      Author: SKM
 */

#ifndef MZ_MQTT_PUBLIC_H_
#define MZ_MQTT_PUBLIC_H_
#ifdef __cplusplus
extern "C" {
#endif
#include "MZ_common.h"
#include "MZ_error_handler.h"
#if(MZ_MQTT_ENABLE == MZ_ENABLE)

typedef enum
{
	MZ_MQTT_NW_EV_NULL = 0, 													/*!< No network Event */
	MZ_MQTT_NW_EV_OPEN_FAIL = 1, 												/*!< Failed to open network */
	MZ_MQTT_NW_EV_OPEN_OK = 2,  												/*!< Network opened successfully */
	MZ_MQTT_NW_EV_WRONG_PARAMETER = 3,  										/*!< Wrong parameter */
	MZ_MQTT_NW_EV_BUSY = 4,  													/*!< MQTT identifier is occupied */
	MZ_MQTT_NW_EV_PDP_FAIL = 5,  												/*!< Failed to activate PDP */
	MZ_MQTT_NW_EV_DOMAIN_ERROR = 6,  											/*!< Failed to parse domain name */
	MZ_MQTT_NW_EV_DISCONNECT = 7,  												/*!< Network disconnection error */
	MZ_MQTT_NW_EV_CLOSE_FAIL = 8, 												/*!< Failed to close network */
	MZ_MQTT_NW_EV_CLOSE_OK = 9,  												/*!< Network closed successfully */

}en_mqtt_network_state;

typedef enum
{
	MZ_MQTT_CON_EV_NULL = 0, 													/*!< No network Event */
	MZ_MQTT_CON_EV_OPEN_OK = 1, 												/*!< Connection Accepted */
	MZ_MQTT_CON_EV_VERSION_ERROR = 2, 											/*!< Connection Refused: Unacceptable Protocol Version */
	MZ_MQTT_CON_EV_CLIENT_ID_ERROR = 3, 										/*!< Connection Refused: Identifier Rejected */
	MZ_MQTT_CON_EV_SERVER_NOT_AVAILABLE = 4, 									/*!< Connection Refused: Server Unavailable */
	MZ_MQTT_CON_EV_USER_PASS_ERROR = 5, 										/*!< Connection Refused: Bad User Name or Password */
	MZ_MQTT_CON_EV_AUTH_ERROR = 6, 												/*!< Connection Refused: Not Authorized */
	MZ_MQTT_CON_EV_CLOSE_FAIL = 7, 												/*!< Failed to close connection */
	MZ_MQTT_CON_EV_CLOSE_OK = 8, 												/*!< Connection closed successfully */
}en_mqtt_connection_state;

typedef enum
{
	MZ_MQTT_CLIENT_EV_NULL = 0, 												/*!< No network Event */
	MZ_MQTT_CLIENT_EV_CON_CLOSE_PEER = 1, 										/*!< Connection reset or Closed by peer */
	MZ_MQTT_CLIENT_EV_PING_FAIL = 2, 											/*!< Ping time out or fail */
	MZ_MQTT_CLIENT_EV_SEND_FAIL = 3, 											/*!< Sending time out or fail */
	MZ_MQTT_CLIENT_EV_CONNAC_FAIL = 4, 											/*!< CONNAC time out or fail */
	MZ_MQTT_CLIENT_EV_DISCON_BY_CLIENT = 5, 									/*!< Disconnect packet send by client */
	MZ_MQTT_CLIENT_EV_CON_CLOSE_CLIENT = 6, 									/*!< Connection Closed by client */
	MZ_MQTT_CLIENT_EV_LINK_NOT_ALIVE = 7, 										/*!< The link is not alive or the server is unavailable */

	MZ_MQTT_CLIENT_EV_PUB_OK = 10, 												/*!< Mqtt Publish OK */
	MZ_MQTT_CLIENT_EV_PUB_RETRANSMIT = 11, 										/*!< Mqtt Publish retransmit */
	MZ_MQTT_CLIENT_EV_PUB_FAIL = 12, 											/*!< Mqtt Publish FAIL */

	MZ_MQTT_CLIENT_EV_SUB_OK = 20, 												/*!< Mqtt Subscribe OK */
	MZ_MQTT_CLIENT_EV_SUB_RETRANSMIT = 21, 										/*!< Mqtt Subscribe retransmit */
	MZ_MQTT_CLIENT_EV_SUB_FAIL = 22, 											/*!< Mqtt Subscribe FAIL */

	MZ_MQTT_CLIENT_EV_UNSUB_OK = 30, 											/*!< Mqtt Un-Subscribe OK */
	MZ_MQTT_CLIENT_EV_UNSUB_RETRANSMIT = 31, 									/*!< Mqtt Un-Subscribe retransmit */
	MZ_MQTT_CLIENT_EV_UNSUB_FAIL = 32 											/*!< Mqtt Un-Subscribe FAIL */
}en_mqtt_client_stat;


typedef struct
{
	enum
	{
		MZ_MQTT_NW,
		MZ_MQTT_CON,
		MZ_MQTT_STAT,
		MZ_MQTT_SUB_RECV,
	}_type;
	union
	{
		en_mqtt_network_state		_nw;
		en_mqtt_connection_state 	_con;
		en_mqtt_client_stat			_stat;
	}_status;
}st_mqtt_status;

typedef enum
{
	MQTT_PUB_NORMAL = 0,														/*!< PUB data format is normal */
	MQTT_PUB_HEX = 1,															/*!< PUB data format is hex */
}en_mqtt_pubhex;

typedef enum
{
	MQTT_SESSION_OLD = 0,														/*!< Resume communication based on persent session */
	MQTT_SESSION_NEW = 1,														/*!< Resume communication with a new session */
}en_mqtt_cleanss;

typedef enum
{
	MQTT_QOS0 = 0,																/*!< At most once */
	MQTT_QOS1 = 1,																/*!< At lease once */
	MQTT_QOS2 = 2,																/*!< Only once */
}en_mqtt_qos;

typedef enum
{
	MQTT_RETAIN_OFF = 0,														/*!< Message will not be saved or removed or replaced */
	MQTT_RETAIN_ON = 1,															/*!< Message and its <qos> will be saved */
}en_mqtt_retain;

typedef enum
{
	MQTT_SUB_NORMAL = 0,														/*!< SUB data format is normal */
	MQTT_SUB_HEX = 1,															/*!< SUB data format is hex */
}en_mqtt_subhex;

typedef enum
{
	MQTT_SYNCMODE = 0,															/*!< The MQTT connection uses synchronous mode */
	MQTT_ASYNCMODE = 1,															/*!< The MQTT connection uses asynchronous mode */
}en_mqtt_conn_mode;

typedef struct __attribute__((packed))
{
	mzUint8				config_id;												/*!< MQTT configuration id */
	char 				*client_id;												/*!< MQTT client id */
	char				*server_url;											/*!< MQTT server URL / IP */
	mzUint16			server_port;											/*!< MQTT server port, Range: 0-65565 */
	mzUint16			keep_alive_time;										/*!< MQTT client server connection keep alive time, Range: 0-65565 */
	en_mqtt_cleanss		session_cleanss;										/*!< MQTT session cleanss */
	char 				*username;												/*!< MQTT server username */
	char				*password;												/*!< MQTT server password */
	en_mqtt_subhex		subhex;													/*!< MQTT SUB data format */
	en_mqtt_conn_mode	connect_mode;											/*!< MQTT Connection Mode */
}st_mqtt_client_config;

typedef struct __attribute__((packed))
{
	en_mqtt_qos			qos;													/*!< MQTT QOS */
	char				*topic;													/*!< MQTT TOPIC */
	char				*message;												/*!< MQTT MESSAGE */
	en_mqtt_retain		retain;													/*!< MQTT Retain Identification */
}st_mqtt_message;

typedef struct __attribute__((packed))
{
	st_mqtt_status 			event;												/*!< MQTT state event */
	st_mqtt_message			msg;												/*!< Message associated by the even */
}st_mqtt_event;

typedef	enum
{
	MQTT_RESET,
	MQTT_SET
}en_mqtt;

mz_error_t mz_mqtt_client_create(st_mqtt_client_config * config);

mz_error_t mz_mqtt_client_configure(mzUint8 config_id);

mz_error_t mz_mqtt_client_close(mzUint8 config_id);

mz_error_t mz_mqtt_client_connect(mzUint8 config_id);

mz_error_t mz_mqtt_client_disconnect(mzUint8 config_id);

mz_error_t mz_mqtt_client_reset(mzUint8 config_id);

mz_error_t mz_mqtt_client_remove(mzUint8 config_id);

mz_error_t mz_mqtt_pub(st_mqtt_message * msg);

mz_error_t mz_mqtt_sub(st_mqtt_message * msg);

mz_error_t mz_mqtt_unsub(st_mqtt_message * msg);

mz_error_t mz_mqtt_create_pub_msg_string(st_mqtt_message * msg, char * key, char * val);

mz_error_t mz_mqtt_create_pub_msg_int(st_mqtt_message * msg, char * key, int val);

#endif // (MZ_MQTT_ENABLE == MZ_ENABLE)
#ifdef __cplusplus
}
#endif
#endif /* MZ_MQTT_PUBLIC_H_ */
