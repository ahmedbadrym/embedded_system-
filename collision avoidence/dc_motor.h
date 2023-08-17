#ifndef _DC_MOTOR_H_
#define _DC_MOTOR_H_

#include "state.h"

enum {
    DC_idle,
    DC_busy
} DC_State_id;

void DC_motor_init();
STATE_define(DC_idle);
STATE_define(DC_busy);

extern void (*DC_motor_state)();

#endif /* _DC_MOTOR_H_ */
