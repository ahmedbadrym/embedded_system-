#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>
#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_

void US_SET_distance(int d);
void DC_SET_Motor(int s);
STATE_define(US_busy);

#endif /* STATE_H_ */
