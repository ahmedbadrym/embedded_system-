#include "dc_motor.h"

int speed = 0;
void (*DC_motor_state)();
void DC_motor_init()
{

    printf("DC_init\n");
}
void DC_motor(int s)
{
    speed = s;
    DC_motor_state = STATE(DC_busy);
    printf("CA_speed = %d---->DC_motor \n", speed);
}
STATE_define(DC_idle)
{
    DC_State_id = DC_idle;
    printf("DC_Idle State: Speed = %d\n", speed);
}
STATE_define(DC_busy)
{
    DC_State_id = DC_busy;
    DC_motor_state = STATE(DC_idle);
    printf("DC_busy speed = %d \n", speed);

}
