/*

 * prg.c
 *
 *  Created on: Aug 26, 2023
 *      Author: THE GHOST
 */
#include "keypad.h"

int Keypad_Row[] = { R0, R1, R2, R3 }; //rows of the keypad
int Keypad_Col[] = { C0, C1, C2, C3 }; //columns

void Keypad_init() {

	RCC_GPIOB_CLK_EN();
	GPIO_PIN_CONFIG PinCfg;

	PinCfg.GPIO_PIN_NUMBER = R0;
	PinCfg.GPIO_MODE = GPIO_OUTPUT_PUSHPULL;
	PinCfg.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PIN_NUMBER = R1;
	PinCfg.GPIO_MODE = GPIO_OUTPUT_PUSHPULL;
	PinCfg.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PIN_NUMBER = R2;
	PinCfg.GPIO_MODE = GPIO_OUTPUT_PUSHPULL;
	PinCfg.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PIN_NUMBER = R3;
	PinCfg.GPIO_MODE = GPIO_OUTPUT_PUSHPULL;
	PinCfg.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PIN_NUMBER = C0;
	PinCfg.GPIO_MODE = GPIO_OUTPUT_PUSHPULL;
	PinCfg.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PIN_NUMBER = C1;
	PinCfg.GPIO_MODE = GPIO_OUTPUT_PUSHPULL;
	PinCfg.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PIN_NUMBER= C2;
	PinCfg.GPIO_MODE = GPIO_OUTPUT_PUSHPULL;
	PinCfg.GPIO_OUT_SPEED= GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PIN_NUMBER = C3;
	PinCfg.GPIO_MODE = GPIO_OUTPUT_PUSHPULL;
	PinCfg.GPIO_OUT_SPEED = GPIO_OUTPUT_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);
	MCAL_GPIO_WRITE_PORT(KEYPAD_PORT, 0xFF);

}

char Keypad_getkey() {
	int i, j;
	for (i = 0; i < 4; i++) {
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, Keypad_Col[0], GPIO_PIN_ON);
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, Keypad_Col[1], GPIO_PIN_ON);
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, Keypad_Col[2], GPIO_PIN_ON);
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, Keypad_Col[3], GPIO_PIN_ON);
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, Keypad_Col[i], GPIO_PIN_OFF);
		for (j = 0; j < 4; j++) {
			if (MCAL_GPIO_READ_PIN(KEYPAD_PORT, Keypad_Row[j]) == 0) {
				while (MCAL_GPIO_READ_PIN(KEYPAD_PORT, Keypad_Row[j]) == 0)
					;
				switch (i) {
				case (0):
					if (j == 0)
						return '7';
					else if (j == 1)
						return '4';
					else if (j == 2)
						return '1';
					else if (j == 3)
						return '?';
					break;
				case (1):
					if (j == 0)
						return '8';
					else if (j == 1)
						return '5';
					else if (j == 2)
						return '2';
					else if (j == 3)
						return '0';
					break;
				case (2):
					if (j == 0)
						return '9';
					else if (j == 1)
						return '6';
					else if (j == 2)
						return '3';
					else if (j == 3)
						return '=';
					break;
				case (3):
					if (j == 0)
						return '/';
					else if (j == 1)
						return '*';
					else if (j == 2)
						return '-';
					else if (j == 3)
						return '+';
					break;
				}
			}
		}
	}
	return 'A';
}
