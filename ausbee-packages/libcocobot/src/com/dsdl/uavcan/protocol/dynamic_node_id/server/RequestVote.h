/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/vfaure/Eurobot2019/ausbee-packages/libcocobot/dsdl/uavcan/protocol/dynamic_node_id/server/31.RequestVote.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_REQUESTVOTE
#define __UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_REQUESTVOTE

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# THIS DEFINITION IS SUBJECT TO CHANGE.
#
# This type is a part of the Raft consensus algorithm.
# Please refer to the specification for details.
#

#
# Refer to the Raft paper for explanation.
#
uint32 term
uint32 last_log_term
uint8 last_log_index

---

#
# Refer to the Raft paper for explanation.
#
uint32 term
bool vote_granted
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.dynamic_node_id.server.RequestVote
saturated uint32 term
saturated uint32 last_log_term
saturated uint8 last_log_index
---
saturated uint32 term
saturated bool vote_granted
******************************************************************************/

#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_REQUESTVOTE_ID 31
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_REQUESTVOTE_NAME "uavcan.protocol.dynamic_node_id.server.RequestVote"
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_REQUESTVOTE_SIGNATURE (0xCDDE07BB89A56356ULL)

#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_REQUESTVOTE_REQUEST_MAX_SIZE ((72 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    uint32_t   term;                          // bit len 32
    uint32_t   last_log_term;                 // bit len 32
    uint8_t    last_log_index;                // bit len 8

} uavcan_protocol_dynamic_node_id_server_RequestVoteRequest;

extern
uint32_t uavcan_protocol_dynamic_node_id_server_RequestVoteRequest_encode(uavcan_protocol_dynamic_node_id_server_RequestVoteRequest* source, void* msg_buf);

extern
int32_t uavcan_protocol_dynamic_node_id_server_RequestVoteRequest_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_dynamic_node_id_server_RequestVoteRequest* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_dynamic_node_id_server_RequestVoteRequest_encode_internal(uavcan_protocol_dynamic_node_id_server_RequestVoteRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_dynamic_node_id_server_RequestVoteRequest_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_dynamic_node_id_server_RequestVoteRequest* dest, uint8_t** dyn_arr_buf, int32_t offset);

#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_REQUESTVOTE_RESPONSE_MAX_SIZE ((33 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    uint32_t   term;                          // bit len 32
    bool       vote_granted;                  // bit len 1

} uavcan_protocol_dynamic_node_id_server_RequestVoteResponse;

extern
uint32_t uavcan_protocol_dynamic_node_id_server_RequestVoteResponse_encode(uavcan_protocol_dynamic_node_id_server_RequestVoteResponse* source, void* msg_buf);

extern
int32_t uavcan_protocol_dynamic_node_id_server_RequestVoteResponse_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_dynamic_node_id_server_RequestVoteResponse* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_dynamic_node_id_server_RequestVoteResponse_encode_internal(uavcan_protocol_dynamic_node_id_server_RequestVoteResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_dynamic_node_id_server_RequestVoteResponse_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_dynamic_node_id_server_RequestVoteResponse* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_SERVER_REQUESTVOTE