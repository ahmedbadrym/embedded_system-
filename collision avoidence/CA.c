#include "CA.h"


int CA_distance = 0;
int CA_threshold = 50;

void (*ca_state)() = NULL;

void Us_distance_set(int i) {
    CA_distance = i;
    printf("Us_sensor ---distance = %d---> CA_algorithm \n", CA_distance);
    (CA_distance <= CA_threshold) ? (ca_state = STATE(CA_waiting)) : (ca_state = STATE(CA_driving));
}

int CA_speed = 0;

STATE_define(CA_waiting) {
    CA_State_id = CA_waiting;
    printf("CA_waiting_state: distance = %d speed = %d\n", CA_distance, CA_speed);
    DC_motor(CA_speed);
}

STATE_define(CA_driving) {
    CA_State_id = CA_driving;
    printf("CA_driving_state: distance = %d speed = %d\n", CA_distance, CA_speed);
    DC_motor(CA_speed);
}
