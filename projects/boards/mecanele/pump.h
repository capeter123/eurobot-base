#ifndef PUMP_H
#define PUMP_H

#include <stdint.h>

void pump_init(void);
void pump_set_state(uint8_t pump_id, uint8_t action);
uint8_t pump_get_state(uint8_t pump_id);

#endif// SERVO_H

