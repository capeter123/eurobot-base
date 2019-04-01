/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/damien/prog/rcocobot/ausbee-packages/libcocobot/dsdl/uavcan/protocol/enumeration/15.Begin.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_ENUMERATION_BEGIN
#define __UAVCAN_PROTOCOL_ENUMERATION_BEGIN

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# This service instructs the node to begin the process of automated enumeration.
#

#
# The node will automatically leave enumeration mode upon expiration of this timeout.
#
uint16 TIMEOUT_CANCEL   = 0     # Stop enumeration immediately
uint16 TIMEOUT_INFINITE = 65535 # Do not stop until explicitly requested
uint16 timeout_sec              # [Seconds]

#
# Name of the parameter to enumerate, e.g. ESC index.
# If the name is left empty, the node will infer the parameter name automatically (autodetect).
# It is highly recommended to always use autodetection in order to avoid dependency on hard-coded parameter names,
# and also allow the enumeratee to possibly enumerate multiple different parameters at once.
# The rule of thumb is to always leave this parameter empty unless you really know what you're doing.
#
uint8[<=92] parameter_name

---

uint8 ERROR_OK                  = 0     # Success
uint8 ERROR_INVALID_MODE        = 1     # The node cannot perform enumeration in its current operating mode
uint8 ERROR_INVALID_PARAMETER   = 2     # The node cannot enumerate on the requested parameter, or it doesn't exist
uint8 ERROR_UNSUPPORTED         = 3     # The node cannot perform enumeration in its current configuration
uint8 ERROR_UNKNOWN             = 255   # Generic error
uint8 error
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.enumeration.Begin
saturated uint16 timeout_sec
saturated uint8[<=92] parameter_name
---
saturated uint8 error
******************************************************************************/

#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_ID               15
#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_NAME             "uavcan.protocol.enumeration.Begin"
#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_SIGNATURE        (0x196AE06426A3B5D8ULL)

#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_REQUEST_MAX_SIZE ((759 + 7)/8)

// Constants
#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_REQUEST_TIMEOUT_CANCEL              0 // 0
#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_REQUEST_TIMEOUT_INFINITE        65535 // 65535

#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_REQUEST_PARAMETER_NAME_MAX_LENGTH              92

typedef struct
{
    // FieldTypes
    uint16_t   timeout_sec;                   // bit len 16
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uint8_t*   data;                      // Dynamic Array 8bit[92] max items
    } parameter_name;

} uavcan_protocol_enumeration_BeginRequest;

extern
uint32_t uavcan_protocol_enumeration_BeginRequest_encode(uavcan_protocol_enumeration_BeginRequest* source, void* msg_buf);

extern
int32_t uavcan_protocol_enumeration_BeginRequest_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_enumeration_BeginRequest* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_enumeration_BeginRequest_encode_internal(uavcan_protocol_enumeration_BeginRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_enumeration_BeginRequest_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_enumeration_BeginRequest* dest, uint8_t** dyn_arr_buf, int32_t offset);

#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_RESPONSE_MAX_SIZE ((8 + 7)/8)

// Constants
#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_RESPONSE_ERROR_OK                   0 // 0
#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_RESPONSE_ERROR_INVALID_MODE          1 // 1
#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_RESPONSE_ERROR_INVALID_PARAMETER          2 // 2
#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_RESPONSE_ERROR_UNSUPPORTED          3 // 3
#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_RESPONSE_ERROR_UNKNOWN            255 // 255

typedef struct
{
    // FieldTypes
    uint8_t    error;                         // bit len 8

} uavcan_protocol_enumeration_BeginResponse;

extern
uint32_t uavcan_protocol_enumeration_BeginResponse_encode(uavcan_protocol_enumeration_BeginResponse* source, void* msg_buf);

extern
int32_t uavcan_protocol_enumeration_BeginResponse_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_enumeration_BeginResponse* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_enumeration_BeginResponse_encode_internal(uavcan_protocol_enumeration_BeginResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_enumeration_BeginResponse_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_enumeration_BeginResponse* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_ENUMERATION_BEGIN