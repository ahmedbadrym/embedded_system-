#ifndef _CA_H_
#define _CA_H_

#include "state.h"

enum {
    CA_waiting,
    CA_driving
} CA_State_id;

STATE_define(CA_waiting);
STATE_define(CA_driving);

void CA_Set_State(void (*state)()); // Add this function declaration

extern void (*ca_state)();

#endif /* CA_H_ */
