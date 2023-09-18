/*
 * int.h
 *
 * Created: 9/18/2023 8:20:41 PM
 *  Author: THE GHOST
 */ 


#ifndef INT_H_
#define INT_H_
#include "avr/io.h"
#define KEYPAD_DIR DDRB
#define KEYPAD_PORT	PORTB
#define KEYPAD_PIN	PINB
#define ROW_N 4
#define COL_N 4
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

unsigned char Get_Pressed_KEY(void);
void KEYPAD_init();
#endif /* INT_H_ */