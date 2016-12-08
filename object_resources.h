/*
 * object_resources.h
 *
 * Created: 02/09/16 10:23:43
 *  Author: PvR
 */ 


#ifndef OBJECT_RESOURCES_H_
#define OBJECT_RESOURCES_H_

#include "clocks.h"

#define SWAP_UINT16(x) (((x) >> 8) | ((x) << 8))
#define SWAP_UINT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))

#define UINT16_TO_BYTE_ARRAY(x) {(uint8_t)((x) >> 8), (uint8_t)((x) & 0xff)}
#define UINT32_TO_BYTE_ARRAY(x) {(uint8_t)((x) >> 24), (uint8_t)((x) >> 16), (uint8_t)((x) >> 8), (uint8_t)((x) & 0xff)}

#define MAX_GRP_OBJECTS						128

#define FLAG_COMMUNICATE					(1<<2)
#define FLAG_READ							(1<<3)
#define FLAG_WRITE							(1<<4)
#define FLAG_READ_ON_INIT					(1<<5)
#define FLAG_TRANSMIT						(1<<6)
#define FLAG_UPDATE							(1<<7)

#define GRP_OBJ_COMMUNICATION_FLAG_bp		2
#define GRP_OBJ_READABLE_FLAG_bp			3
#define GRP_OBJ_WRITEABLE_FLAG_bp			4
#define GRP_OBJ_INITIALIZE_FLAG_bp			5
#define GRP_OBJ_TRANSMIT_FLAG_bp			6
#define GRP_OBJ_UPDATE_FLAG_bp				7

#define COMM_FLAG_OK						(1<<0)
#define COMM_FLAG_READ_REQUEST				(1<<1)
#define COMM_FLAG_WRITE_REQUEST				(1<<2)
#define COMM_FLAG_TRANSMITTING				(1<<3)
#define COMM_FLAG_UPDATE					(1<<4)
#define COMM_FLAG_ERROR						(1<<5)
#define COMM_FLAG_READ_RESPONSE				(1<<6)

typedef enum {
	GRP_OBJ_SZ_1_BIT = 0x00,
	GRP_OBJ_SZ_2_BITS = 0x01,
	GRP_OBJ_SZ_3_BITS = 0x02,
	GRP_OBJ_SZ_4_BITS = 0x03,
	GRP_OBJ_SZ_5_BITS = 0x04,
	GRP_OBJ_SZ_6_BITS = 0x05,
	GRP_OBJ_SZ_7_BITS = 0x06,
	GRP_OBJ_SZ_1_BYTE = 0x07,
	GRP_OBJ_SZ_2_BYTES = 0x08,
	GRP_OBJ_SZ_3_BYTES = 0x09,
	GRP_OBJ_SZ_4_BYTES = 0x0A,
	GRP_OBJ_SZ_6_BYTES = 0x0B,
	GRP_OBJ_SZ_8_BYTES = 0x0C,
	GRP_OBJ_SZ_10_BYTES = 0x0D,
	GRP_OBJ_SZ_14_BYTES = 0x0E,
	GRP_OBJ_SZ_5_BYTES = 0x0F,
	GRP_OBJ_SZ_7_BYTES = 0x10,
	GRP_OBJ_SZ_9_BYTES = 0x11,
	GRP_OBJ_SZ_11_BYTES = 0x12,
	GRP_OBJ_SZ_12_BYTES = 0x13,
	GRP_OBJ_SZ_13_BYTES = 0x14,
	GRP_OBJ_SZ_15_BYTES = 0x15
} grpObjSz_e;


typedef enum {
	DEVICE_OBJECT = 0x0,
	ADDRESS_TABLE_OBJECT = 0x1,
	ASSOCIATION_TABLE_OBJECT = 0x2,
	APPLICATION_OBJECT_1 = 0x3,
	APPLICATION_OBJECT_2 = 0x4,
	ROUTER_OBJECT = 0x06,
	LTE_ADDRESS_ROUTING_TABLE_OBJECT = 0x07,
	CEMI_SERVER_OBJECT = 0x08,
	GROUP_OBJECT_TABLE_OBJECT = 0x9,
	POLLING_MASTER_OBJECT = 0x0a,
	KNXNET_IP_PARAMETER_OBJECT = 0x0b,
	FILESERVER_OBJECT = 0x0d,
	E_MODE_CHANNEL_OBJECT = 0x0e,
	ADJUSTED_E_MODE_CHANNEL_OBJECT = 0x0f,
	TEXT_CATALOGUE_OBJECT = 0x10,
	E_MODE_DEVICE_OBJECT = 0x12,
	RF_MEDIUM_OBJECT = 0x13
}	interfaceObjectType_e;

typedef enum {
	APP_INTF_OBJ_START = 50000, // dummy object to mark start of application object range
	TOUCHPAD_CFG_OBJECT = 50001,
	ACTION_CFG_OBJECT = 50002,
	RGB_LED_CFG_OBJECT = 50003,
	AMBIENT_SENSOR_CFG_OBJECT = 50004
} application_interface_object_type_e;

typedef enum {
	PID_APP_START = 200, // dummy  property to mark start of application property range
	PID_TOUCHPAD_CFG = 201,
	PID_TOUCH_ACTION_CFG = 202,
	PID_RGBLEG_CFG = 203,
	PID_AMBIENT_SENSORS_CFG = 204,
	PID_AMBIENT_SENSORS_INTERVAL = 205,
	PID_AMBIENT_TEMPERATURE = 206,
	PID_AMBIENT_HUMIDITY = 207,
	PID_AMBIENT_TEMPERATURE_OFFSET = 208,
	PID_AMBIENT_HUMIDITY_OFFSET = 209
} application_property_id_e;

typedef enum {
	PDT_CONTROL = 0x00,					// length read = 1 / write = 10
	PDT_CHAR = 0x01,					// length = 1
	PDT_UNSIGNED_CHAR = 0x02,			// length = 1
	PDT_INT = 0x03,						// length = 2
	PDT_UNSIGNED_INT = 0x04,			// length = 2
	PDT_EIB_FLOAT = 0x05,				// length = 2
	PDT_DATE = 0x06,					// length = 3
	PDT_TIME = 0x07,					// length = 3
	PDT_LONG = 0x08,					// length = 4
	PDT_UNSIGNED_LONG = 0x09,			// length = 4
	PDT_FLOAT = 0x0a,					// length = 4
	PDT_DOUBLE = 0x0b,					// length = 4
	PDT_CHAR_BLOCK = 0x0c,				// length = 10
	PDT_POLL_GROUP_SETTING = 0x0d,		// length = 3
	PDT_SHORT_CHAR_BLOCK = 0x0e,		// length = 5
	PDT_DATE_TIME = 0x0f,				// length = 8
	PDT_VARIABLE_LENGTH = 0x10,			// PDT_VARIABLE_LENGTH, PDT = 0x10, format DPT_VarString_8859_1.
	PDT_GENERIC01 = 0x11,				// length = 1
	PDT_GENERIC02 = 0x12,				// length = 2
	PDT_GENERIC03 = 0x13,				// length = 3
	PDT_GENERIC04 = 0x14,				// length = 4
	PDT_GENERIC05 = 0x15,				// length = 5
	PDT_GENERIC06 = 0x16,				// length = 6
	PDT_GENERIC07 = 0x17,				// length = 7
	PDT_GENERIC08 = 0x18,				// length = 8
	PDT_GENERIC09 = 0x19,				// length = 9
	PDT_GENERIC10 = 0x1a,				// length = 10
	PDT_GENERIC11 = 0x1b,
	PDT_GENERIC12 = 0x1c,
	PDT_GENERIC13 = 0x1d,
	PDT_GENERIC14 = 0x1e,
	PDT_GENERIC15 = 0x1f,
	PDT_GENERIC16 = 0x20,
	PDT_GENERIC17 = 0x21,
	PDT_GENERIC18 = 0x22,
	PDT_GENERIC19 = 0x23,
	PDT_GENERIC20 = 0x24,
	PDT_UTF8 = 0x2f,					// length variable
	PDT_VERSION = 0x30,					// length = 2
	PDT_ALARM_INFO = 0x31,				// length = 3
	PDT_BINARY_INFORMATION = 0x32,		// length = 1
	PDT_BITSET8 = 0x33,					// length = 1
	PDT_BITSET16 = 0x34,				// length =2
	PDT_ENUM8 = 0x35,					// length = 1
	PDT_SCALING = 0x36,					// length = 1
	PDT_NE_VL = 0x3C,					// length undefined
	PDT_NE_FL = 0x3D,					// length undefined
	PDT_FUNCTION = 0x3E	,				// length usage dependent
	PDT_UNKNOWN = 0xFF
} PDT_e;



typedef enum {
	// Global object types
	PID_OBJECT_TYPE = 0x01,
	PID_OBJECT_NAME = 0x02,
	PID_SEMAPHOR = 0x03,
	PID_GROUP_OBJECT_REFERENCE = 0x04,
	PID_LOAD_STATE_CONTROL = 0x05,
	PID_RUN_STATE_CONTROL = 0x06,
	PID_TABLE_REFERENCE = 0x07,
	PID_SERVICE_CONTROL = 0x08,
	PID_FIRMWARE_REVISION = 0x09,
	PID_SERVICES_SUPPORTED = 0x0a,
	PID_SERIAL_NUMBER = 0x0b,
	PID_MANUFACTURER_ID = 0x0c,
	PID_PROGRAM_VERSION = 0x0d,
	PID_DEVICE_CONTROL = 0x0e,
	PID_ORDER_INFO = 0x0f,
	PID_PEI_TYPE = 0x10,
	PID_PORT_CONFIGURATION = 0x11,
	PID_POLL_GROUP_SETTINGS = 0x12,
	PID_MANUFACTURER_DATA = 0x13,
	PID_ENABLE = 0x14,
	PID_DESCRIPTION = 0x15,
	PID_FILE = 0x16,
	PID_TABLE = 0x17,
	PID_ENROL = 0x18,
	PID_VERSION = 0x19,
	PID_GROUP_OBJECT_LINK = 0x1a,
	PID_MCB_TABLE = 0x1b,
	PID_ERROR_CODE = 0x1c,
	PID_OBJECT_INDEX = 0x1d,
	PID_DOWNLOAD_COUNTER = 30,
	// Type 0 object types
	PID_ROUTING_COUNT = 51,
	PID_MAX_RETRY_COUNT = 52,
	PID_ERROR_FLAGS = 53,
	PID_PROGMODE = 54,
	PID_PRODUCT_ID = 55,
	PID_MAX_APDULENGTH = 56,
	PID_SUBNET_ADDR = 57,
	PID_DEVICE_ADDR = 58,
	PID_PB_CONFIG = 59,
	PID_ADDR_REPORT = 60,
	PID_ADDR_CHECK = 61,
	PID_OBJECT_VALUE = 62,
	PID_OBJECTLINK = 63,
	PID_APPLICATION = 64,
	PID_PARAMETER = 65,
	PID_OBJECTADDRESS = 66,
	PID_PSU_TYPE = 67,
	PID_PSU_STATUS = 68,
	PID_PSU_ENABLE = 69,
	PID_DOMAIN_ADDRESS = 70,
	PID_IO_LIST = 71,
	PID_MGT_DESCRIPTOR_01 = 72,
	PID_PL110_PARAM = 73,
	PID_RF_REPEAT_COUNTER = 74,
	PID_RECEIVE_BLOCK_TABLE = 75,
	PID_RANDOM_PAUSE_TABLE = 76,
	PID_RECEIVE_BLOCK_NR = 77,
	PID_HARDWARE_TYPE = 78,
	PID_RETRANSMITTER_NUMBER = 79,
	PID_SERIAL_NR_TABLE = 80,
	PID_BIBATMASTER_ADDRESS = 81,
	PID_RF_DOMAIN_ADDRESS = 82,
	PID_DEVICE_DESCRIPTOR = 83,
	PID_METERING_FILTER_TABLE = 84,
	PID_GROUP_TELEGR_RATE_LIMIT_TIME_BASE = 85,
	PID_GROUP_TELEGR_RATE_LIMIT_NO_OF_TELEGR = 86,
/*
	PID_EXT_FRAMEFORMAT = 0x100 + 51, // object type 1
	PID_ADDRTAB1 = 0x100 + 52,
	PID_GROUP_RESPONSER_TABLE = 0x100 + 53,
	PID_TABLE_OBJ_TYPE_2 = 0x200 + 52, // object type 2
	PID_PARAM_REFERENCE = 0x300 + 51, // object type 3
	PID_LINE_STATUS = 0x600 + 51, // object type 6
	PID_MAIN_LCCONFIG_PRIMARY = 0x600 + 52, // primary
	PID_MAIN_LCCONFIG_SECONDARY = 0x600 + 53, // secondary
	PID_MAIN_LCGRPCONFIG = 0x600 + 54,
	PID_SUB_LCGRPCONFIG = 0x600 + 55,
	PID_ROUTETABLE_CONTROL = 0x600 + 56,
	PID_COUPL_SERV_CONTROL = 0x600 + 57,
	PID_MAX_APDU_LENGTH = 0x600 + 58,
	PID_LTE_ROUTESELECT = 0x700 + 51, // object type 7
	PID_LTE_ROUTETABLE = 0x700 + 52,
	PID_MEDIUM_TYPE = 0x800 + 51, //object type 8
	PID_COMM_MODE = 0x800 + 52,
	PID_MEDIUM_AVAILABILITY = 0x800 + 53,
	PID_ADD_INFO_TYPES = 0x800 + 54,
	PID_TIME_BASE = 0x800 + 55,
	PID_TRANSP_ENABLE = 0x800 + 56,
	PID_CLIENT_SNA = 0x800 + 57,
	PID_CLIENT_DEVICE_ADDRESS = 0x800 + 58,
	PID_BIBAT_NEXTBLOCK = 0x800 + 59,
	PID_RF_MODE_SELECT = 0x800 + 60,
	PID_RF_MODE_SUPPORT = 0x800 + 61,
	PID_RF_FILTERING_MODE_SELECT = 0x800 + 62,
	PID_RF_FILTERING_MODE_SUPPORT = 0x800 + 63,
	PID_GRPOBJTABLE = 0x900 + 51, // object type 9
	PID_EXT_GRPOBJREFERENCE = 0x900 + 52,
	PID_POLLING_STATE = 0xa00 + 51, // object type 10
	PID_POLLING_SLAVE_ADDR = 0xa00 + 52,
	PID_POLL_CYCLE = 0xa00 + 53*/
} PropertyId_e;


typedef enum {
	OBJECT_LOAD_STATE_UNLOADED = 0X0,
	OBJECT_LOAD_STATE_LOADED = 0X1,
	OBJECT_LOAD_STATE_LOADING = 0X2,
	OBJECT_LOAD_STATE_ERROR = 0X3,
	OBJECT_LOAD_STATE_UNLOADING = 0X4,
	OBJECT_LOAD_STATE_LOAD_COMPLETED = 0X5
} load_state_e;

typedef enum {
	OBJECT_LOAD_ACTION_NO_OPERATION = 0X0,
	OBJECT_LOAD_ACTION_START_LOADING = 0X1,
	OBJECT_LOAD_ACTION_LOAD_COMPLETED = 0X2,
	OBJECT_LOAD_ACTION_ADDITIONAL_LOAD_CONTROLS = 0X3,
	OBJECT_LOAD_ACTION_UNLOAD = 0X4
} load_action_e;

typedef enum {
	PROGRAM_HALTED = 0X0,
	PROGRAM_RUNNING = 0X1,
	PROGRAM_READY = 0X2,
	PROGRAM_TERMINATED = 0X3
} run_state_e;


typedef enum {
	DEVICE_OBJECT_IDX = 0,
	ADDRESS_TABLE_OBJECT_IDX = 1,
	ASSOCIATION_TABLE_OBJECT_IDX = 2,
	GROUP_OBJECT_TABLE_OBJECT_IDX = 3,
	APPLICATION_1_OBJECT_IDX = 4,
	APPLICATION_2_OBJECT_IDX = 5,
	TOUCHPAD_CFG_OBJECT_IDX = 6,
	ACTION_CFG_OBJECT_IDX = 7,
	RGB_LED_CFG_OBJECT_IDX = 8,
	AMBIENT_SENSOR_CFG_OBJECT_IDX = 9	
} prop_obj_e;


uint8_t getPDTsize(PDT_e pdt);

PDT_e getPDTfromPropType(PropertyId_e propId);

#endif /* OBJECT_RESOURCES_H_ */