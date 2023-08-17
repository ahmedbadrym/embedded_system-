#include "us_sensor.h"
#include <stdlib.h>

int US_distance = 0;
void (*US_state)();
void US_init() {
    printf("US_init \n");
}

void US_SET_distance(int d) {
    US_distance = d;
}

STATE_define(US_busy) {
    US_state_id = US_busy;

    US_distance = US_Get_distance_random(45, 55, 1);

    printf("US_busy State: distance = %d\n", US_distance);

    US_SET_distance(US_distance);

    US_state = STATE(US_busy);
}

int US_Get_distance_random(int l, int r, int count) {
    int i;
    for (i = 0; i < count; i++) {
        int rand_num = (rand() % (r - l + 1)) + l;
        return rand_num;
    }
    return 0;
}
