/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/damien/prog/rcocobot/ausbee-packages/libcocobot/dsdl/uavcan/protocol/dynamic_node_id/server/30.AppendEntries.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_APPENDENTRIES
#define __UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_APPENDENTRIES

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <uavcan/protocol/dynamic_node_id/server/Entry.h>

/******************************* Source text **********************************
#
# THIS DEFINITION IS SUBJECT TO CHANGE.
#
# This type is a part of the Raft consensus algorithm.
# Please refer to the specification for details.
#

#
# Given min election timeout and cluster size, the maximum recommended request interval can be derived as follows:
#
#   max recommended request interval = (min election timeout) / 2 requests / (cluster size - 1)
#
# The equation assumes that the Leader requests one Follower at a time, so that there's at most one pending call
# at any moment. Such behavior is optimal as it creates uniform bus load, but it is actually implementation-specific.
# Obviously, request interval can be lower than that if needed, but higher values are not recommended as they may
# cause Followers to initiate premature elections in case of intensive frame losses or delays.
#
# Real timeout is randomized in the range (MIN, MAX], according to the Raft paper.
#
uint16 DEFAULT_MIN_ELECTION_TIMEOUT_MS = 2000
uint16 DEFAULT_MAX_ELECTION_TIMEOUT_MS = 4000

#
# Refer to the Raft paper for explanation.
#
uint32 term
uint32 prev_log_term
uint8 prev_log_index
uint8 leader_commit

#
# Worst-case replication time per Follower can be computed as:
#
#   worst replication time = (127 log entries) * (2 trips of next_index) * (request interval per Follower)
#
Entry[<=1] entries

---

#
# Refer to the Raft paper for explanation.
#
uint32 term
bool success
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.dynamic_node_id.server.AppendEntries
saturated uint32 term
saturated uint32 prev_log_term
saturated uint8 prev_log_index
saturated uint8 leader_commit
uavcan.protocol.dynamic_node_id.server.Entry[<=1] entries
---
saturated uint32 term
saturated bool success
******************************************************************************/

#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_APPENDENTRIES_ID 30
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_APPENDENTRIES_NAME "uavcan.protocol.dynamic_node_id.server.AppendEntries"
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_APPENDENTRIES_SIGNATURE (0x8032C7097B48A3CCULL)

#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_APPENDENTRIES_REQUEST_MAX_SIZE ((249 + 7)/8)

// Constants
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_APPENDENTRIES_REQUEST_DEFAULT_MIN_ELECTION_TIMEOUT_MS       2000 // 2000
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_APPENDENTRIES_REQUEST_DEFAULT_MAX_ELECTION_TIMEOUT_MS       4000 // 4000

#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_APPENDENTRIES_REQUEST_ENTRIES_MAX_LENGTH  1

typedef struct
{
    // FieldTypes
    uint32_t   term;                          // bit len 32
    uint32_t   prev_log_term;                 // bit len 32
    uint8_t    prev_log_index;                // bit len 8
    uint8_t    leader_commit;                 // bit len 8
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uavcan_protocol_dynamic_node_id_server_Entry* data;                      // Dynamic Array 168bit[1] max items
    } entries;

} uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest;

extern
uint32_t uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_encode(uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest* source, void* msg_buf);

extern
int32_t uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_encode_internal(uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest* dest, uint8_t** dyn_arr_buf, int32_t offset);

#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_APPENDENTRIES_RESPONSE_MAX_SIZE ((33 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    uint32_t   term;                          // bit len 32
    bool       success;                       // bit len 1

} uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse;

extern
uint32_t uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse_encode(uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse* source, void* msg_buf);

extern
int32_t uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse_encode_internal(uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_APPENDENTRIES