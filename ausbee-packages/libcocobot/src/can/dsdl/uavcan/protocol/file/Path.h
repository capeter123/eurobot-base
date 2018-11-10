/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/damien/prog/cocobot/ausbee-packages/libcocobot/dsdl/uavcan/protocol/file/Path.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_FILE_PATH
#define __UAVCAN_PROTOCOL_FILE_PATH

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Nested type.
#
# File system path in UTF8.
#
# The only valid separator is forward slash.
#

uint8 SEPARATOR = '/'

uint8[<=200] path
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.file.Path
saturated uint8[<=200] path
******************************************************************************/

#define UAVCAN_PROTOCOL_FILE_PATH_NAME                     "uavcan.protocol.file.Path"
#define UAVCAN_PROTOCOL_FILE_PATH_SIGNATURE                (0x12AEFC50878A43E2ULL)

#define UAVCAN_PROTOCOL_FILE_PATH_MAX_SIZE                 ((1608 + 7)/8)

// Constants
#define UAVCAN_PROTOCOL_FILE_PATH_SEPARATOR                                 '/' // '/'

#define UAVCAN_PROTOCOL_FILE_PATH_PATH_MAX_LENGTH                                        200

typedef struct
{
    // FieldTypes
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uint8_t*   data;                      // Dynamic Array 8bit[200] max items
    } path;

} uavcan_protocol_file_Path;

extern
uint32_t uavcan_protocol_file_Path_encode(uavcan_protocol_file_Path* source, void* msg_buf);

extern
int32_t uavcan_protocol_file_Path_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_Path* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_file_Path_encode_internal(uavcan_protocol_file_Path* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_file_Path_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_Path* dest, uint8_t** dyn_arr_buf, int32_t offset, uint8_t tao);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_FILE_PATH