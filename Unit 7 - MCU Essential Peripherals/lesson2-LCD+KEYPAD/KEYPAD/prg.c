	
#include "int.h"

	int KEYPAD_R[]={R0,R1,R2,R3};
	int KEYPAD_C[]={C0,C1,C2,C3};

	void KEYPAD_init(){
		KEYPAD_DIR =0x0F;
		KEYPAD_PORT =0xFF;
	}

	unsigned char Get_Pressed_KEY(void){
		for(int i=0;i<ROW_N;i++){
			KEYPAD_PORT |=(1<<KEYPAD_R[0]) |(1<<KEYPAD_R[1])|(1<<KEYPAD_R[2])|(1<<KEYPAD_R[3]);
			KEYPAD_PORT &=~(1<<KEYPAD_R[i]);
			for(int j=0;j<COL_N;j++){
				if(!(KEYPAD_PIN &(1<<KEYPAD_C[j]))){
					while(!(KEYPAD_PIN &(1<<KEYPAD_C[j])));
					switch(i){
						case 0:
						if( j==0) return '7';
						else if(j==1) return '8';
						else if(j==2) return '9';
						else if(j==3) return '/';

						break;
						case 1:
						if( j==0) return '4';
						else if(j==1) return '5';
						else if(j==2) return '6';
						else if(j==3) return '*';
						break;
						case 2:
						if( j==0) return '1';
						else if(j==1) return '2';
						else if(j==2) return '3';
						else if(j==3) return '-';
						break;
						case 3:
						if( j==0) return 'D';
						else if(j==1) return '0';
						else if(j==2) return '=';
						else if(j==3) return '+';
						break;
						default :
						break;
					}
				}
			}
		}
		return 'N';
	}