#ifndef _US_SENSOR_H_
#define _US_SENSOR_H_
#include "state.h"

enum {
    US_busy
} US_state_id;

void US_init();
void US_SET_distance(int d);
STATE_define(US_busy);

extern void (*US_state)();

#endif /* _US_SENSOR_H_ */
