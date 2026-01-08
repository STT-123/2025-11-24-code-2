
#ifndef CANMESSAGE_HEADER_H
#define CANMESSAGE_HEADER_H
#include "rtwtypes.h"

#ifndef INVALID_CAN_ID
#define INVALID_CAN_ID                 0xFFFFFFFFU
#endif

typedef struct
{

	/* Is Extended frame */
	uint8_T Extended;

	/* Length */
	uint8_T Length;

	/* RTR */
	uint8_T Remote;

	/* Error */
	uint8_T Error;

	/* CAN ID */
	uint32_T ID;

	/*
	  TIMESTAMP_NOT_REQUIRED is a macro that will be defined by Target teams
	  PIL, C166, FM5, xPC if they do not require the timestamp field during code
	  generation. By default, timestamp is defined. If the targets do not require
	  the timestamp field, they should define the macro TIMESTAMP_NOT_REQUIRED before
	  including this header file for code generation.
	*/
#ifndef TIMESTAMP_NOT_REQUIRED
	/* Timestamp */
	double Timestamp;
#endif

	/* Data field */
	uint8_T Data[8];

} CAN_MESSAGE;
typedef CAN_MESSAGE CAN_MESSAGE_BUS ;

#endif