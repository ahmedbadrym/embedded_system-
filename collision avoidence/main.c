#include "CA.h"
#include "us_sensor.h"
#include "dc_motor.h"

void setup() {
    US_init();
    DC_motor_init();
    ca_state = STATE(CA_waiting);
    US_state = STATE(US_busy);
    DC_motor_state = STATE(DC_idle);
}

int main(void) {
    setup();
    int x = 20;
    while (x--) {
        US_state();
        ca_state();
        DC_motor_state();
    }
    return 0;
}
