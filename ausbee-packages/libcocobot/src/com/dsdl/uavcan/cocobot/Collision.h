/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/damien/prog/ausbee-packages/libcocobot/dsdl/uavcan/cocobot/204.Collision.uavcan
 */

#ifndef __UAVCAN_COCOBOT_COLLISION
#define __UAVCAN_COCOBOT_COLLISION

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
float32 x
float32 y
float32 a

---

uint8 left_front
uint8 right_front
uint8 left_back
uint8 right_back
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.cocobot.Collision
saturated float32 x
saturated float32 y
saturated float32 a
---
saturated uint8 left_front
saturated uint8 right_front
saturated uint8 left_back
saturated uint8 right_back
******************************************************************************/

#define UAVCAN_COCOBOT_COLLISION_ID                        204
#define UAVCAN_COCOBOT_COLLISION_NAME                      "uavcan.cocobot.Collision"
#define UAVCAN_COCOBOT_COLLISION_SIGNATURE                 (0x12DFAC8D2D2CC627ULL)

#define UAVCAN_COCOBOT_COLLISION_REQUEST_MAX_SIZE          ((96 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    float      x;                             // float32 Saturate
    float      y;                             // float32 Saturate
    float      a;                             // float32 Saturate

} uavcan_cocobot_CollisionRequest;

extern
uint32_t uavcan_cocobot_CollisionRequest_encode(uavcan_cocobot_CollisionRequest* source, void* msg_buf);

extern
int32_t uavcan_cocobot_CollisionRequest_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_CollisionRequest* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_cocobot_CollisionRequest_encode_internal(uavcan_cocobot_CollisionRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_cocobot_CollisionRequest_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_CollisionRequest* dest, uint8_t** dyn_arr_buf, int32_t offset);

#define UAVCAN_COCOBOT_COLLISION_RESPONSE_MAX_SIZE         ((32 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    uint8_t    left_front;                    // bit len 8
    uint8_t    right_front;                   // bit len 8
    uint8_t    left_back;                     // bit len 8
    uint8_t    right_back;                    // bit len 8

} uavcan_cocobot_CollisionResponse;

extern
uint32_t uavcan_cocobot_CollisionResponse_encode(uavcan_cocobot_CollisionResponse* source, void* msg_buf);

extern
int32_t uavcan_cocobot_CollisionResponse_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_CollisionResponse* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_cocobot_CollisionResponse_encode_internal(uavcan_cocobot_CollisionResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_cocobot_CollisionResponse_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_cocobot_CollisionResponse* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_COCOBOT_COLLISION