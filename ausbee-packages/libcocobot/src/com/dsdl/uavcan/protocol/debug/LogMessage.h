/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/damien/prog/rcocobot/ausbee-packages/libcocobot/dsdl/uavcan/protocol/debug/16383.LogMessage.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_DEBUG_LOGMESSAGE
#define __UAVCAN_PROTOCOL_DEBUG_LOGMESSAGE

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <uavcan/protocol/debug/LogLevel.h>

/******************************* Source text **********************************
#
# Generic log message.
# All items are byte aligned.
#

LogLevel level
uint8[<=31] source
uint8[<=90] text
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.debug.LogMessage
uavcan.protocol.debug.LogLevel level
saturated uint8[<=31] source
saturated uint8[<=90] text
******************************************************************************/

#define UAVCAN_PROTOCOL_DEBUG_LOGMESSAGE_ID                16383
#define UAVCAN_PROTOCOL_DEBUG_LOGMESSAGE_NAME              "uavcan.protocol.debug.LogMessage"
#define UAVCAN_PROTOCOL_DEBUG_LOGMESSAGE_SIGNATURE         (0xD654A48E0C049D75ULL)

#define UAVCAN_PROTOCOL_DEBUG_LOGMESSAGE_MAX_SIZE          ((983 + 7)/8)

// Constants

#define UAVCAN_PROTOCOL_DEBUG_LOGMESSAGE_SOURCE_MAX_LENGTH                               31
#define UAVCAN_PROTOCOL_DEBUG_LOGMESSAGE_TEXT_MAX_LENGTH                                 90

typedef struct
{
    // FieldTypes
    uavcan_protocol_debug_LogLevel level;                         //
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uint8_t*   data;                      // Dynamic Array 8bit[31] max items
    } source;
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uint8_t*   data;                      // Dynamic Array 8bit[90] max items
    } text;

} uavcan_protocol_debug_LogMessage;

extern
uint32_t uavcan_protocol_debug_LogMessage_encode(uavcan_protocol_debug_LogMessage* source, void* msg_buf);

extern
int32_t uavcan_protocol_debug_LogMessage_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_debug_LogMessage* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_debug_LogMessage_encode_internal(uavcan_protocol_debug_LogMessage* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_debug_LogMessage_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_debug_LogMessage* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_DEBUG_LOGMESSAGE