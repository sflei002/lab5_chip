/*	Author: sflei002
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *	DEMO:https://drive.google.com/drive/u/1/folders/1OUI4dX-_lsgeV6h09MdcMBy8v7fQd_ic
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00;
PORTA = 0xFF;
DDRC = 0xFF;
PORTC = 0x00;
unsigned char fuel = 0x00;
    /* Insert your solution below */
    while (1) {
	fuel = ~PINA & 0x0F;
	switch (fuel){
		case 1:
		case 2:
		PORTC = 0x60;
		break;
		case 3:
                case 4:
                PORTC = 0x70;
                break;
		case 5:
                case 6:
                PORTC = 0x38;
                break;
		case 7:
                case 8:
		case 9:
                PORTC = 0x3C;
                break;
		case 10:
                case 11:
                case 12:
                PORTC = 0x3E;
                break;
		case 13:
                case 14:
                case 15:
                PORTC = 0x3F;
                break;
		default:
		PORTC = 0x40;
		break;
	}
}
}
