/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/vfaure/Eurobot2019/ausbee-packages/libcocobot/dsdl/uavcan/protocol/file/45.GetInfo.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_FILE_GETINFO
#define __UAVCAN_PROTOCOL_FILE_GETINFO

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <uavcan/protocol/file/EntryType.h>
#include <uavcan/protocol/file/Error.h>
#include <uavcan/protocol/file/Path.h>

/******************************* Source text **********************************
#
# Request info about a remote file system entry (file, directory, etc).
#

Path path

---

#
# File size in bytes.
# Should be set to zero for directories.
#
uint40 size

Error error

EntryType entry_type
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.file.GetInfo
uavcan.protocol.file.Path path
---
saturated uint40 size
uavcan.protocol.file.Error error
uavcan.protocol.file.EntryType entry_type
******************************************************************************/

#define UAVCAN_PROTOCOL_FILE_GETINFO_ID                    45
#define UAVCAN_PROTOCOL_FILE_GETINFO_NAME                  "uavcan.protocol.file.GetInfo"
#define UAVCAN_PROTOCOL_FILE_GETINFO_SIGNATURE             (0x5004891EE8A27531ULL)

#define UAVCAN_PROTOCOL_FILE_GETINFO_REQUEST_MAX_SIZE      ((1608 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    uavcan_protocol_file_Path path;                          //

} uavcan_protocol_file_GetInfoRequest;

extern
uint32_t uavcan_protocol_file_GetInfoRequest_encode(uavcan_protocol_file_GetInfoRequest* source, void* msg_buf);

extern
int32_t uavcan_protocol_file_GetInfoRequest_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_GetInfoRequest* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_file_GetInfoRequest_encode_internal(uavcan_protocol_file_GetInfoRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_file_GetInfoRequest_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_GetInfoRequest* dest, uint8_t** dyn_arr_buf, int32_t offset);

#define UAVCAN_PROTOCOL_FILE_GETINFO_RESPONSE_MAX_SIZE     ((64 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    uint64_t   size;                          // bit len 40
    uavcan_protocol_file_Error error;                         //
    uavcan_protocol_file_EntryType entry_type;                    //

} uavcan_protocol_file_GetInfoResponse;

extern
uint32_t uavcan_protocol_file_GetInfoResponse_encode(uavcan_protocol_file_GetInfoResponse* source, void* msg_buf);

extern
int32_t uavcan_protocol_file_GetInfoResponse_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_GetInfoResponse* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_file_GetInfoResponse_encode_internal(uavcan_protocol_file_GetInfoResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_file_GetInfoResponse_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_GetInfoResponse* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_FILE_GETINFO