/*	Author: sflei002
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *    DEMO:https://drive.google.com/open?id=1OUI4dX

 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {init, wait, inc, dec, inc_2, dec_2, reset, reset_2} state;
unsigned char A_0 = 0x00;
unsigned char A_1 = 0x00;

void Tick(){
	A_0 = ~PINA & 0x01;
	A_1 = ~PINA & 0x02;

	switch(state){
		case init:
			state = init;
			break;
		case wait:
			if(!A_1 && !A_0){
				state = wait;
				break;
			}
			else if(A_1 && !A_0){
				state = dec;
				break;
			}
			else if(!A_1 && A_0){
                                state = inc;
                                break;
                        }
			else if(A_1 && A_0){
                                state = reset;
                                break;
                        }
		case inc:
			if(PORTC >= 9){
				state = wait;
				break;
			}
			if(!A_1 && A_0){
                                state = inc;
                                break;
                        }
			else if(!A_1 && !A_0){
                                state = inc_2;
                                break;
                        }
                        else if(A_1 && A_0){
                                state = reset;
                                break;
                        }
		case dec:
                        if(PORTC <= 0){
                                state = wait;
                                break;
                        }
                        if(A_1 && !A_0){
                                state = dec;
                                break;
                        }
                        else if(!A_1 && !A_0){
                                state = dec_2;
                                break;
                        }
                        else if(A_1 && A_0){
                                state = reset;
                                break;
                        }
		case inc_2:
			break;

		case dec_2:
			break;

		case reset:
			if(A_1 && A_0){
				state = reset;
				break;
			}
			if(!A_1 && !A_0){
                                state = reset_2;
                                break;
                        }

		case reset_2:
			break;

		default:
			state = init;
			break;

	}

	switch(state){
		case init:
			PORTC = 0x01;
			state = wait;
			break;

		case wait:
			break;
		
		case inc:
                        break;

		case dec:
                        break;

		case inc_2:
			PORTC = PORTC + 0x01;
			state = wait;
                        break;

		case dec_2:
			PORTC = PORTC - 0x01;
			state = wait;
			break;

		case reset:
			break;

		case reset_2:
			PORTC = 0x00;
			state = wait;
			break;
	}
}

int main(void){
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRC = 0xFF;
	PORTC = 0x00;
	state = init;

	while(1){
		Tick();
	}
	return 1;
}
