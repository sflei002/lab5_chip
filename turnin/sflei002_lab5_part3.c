/*	Author: sflei002
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *DEMO: https://drive.google.com/open?id=1OUl4dX-_IsgeV6h09MdcMBy8v7fQd_ic
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif



enum SM1_States { SM1_Start, SM1_off, SM1_1, SM1_1wait, SM1_2, SM1_2wait, SM1_3, SM1_3wait, SM1_4, SM1_4wait} SM1_State;

void Tick();



int main(void){

	DDRA = 0x00;

	PORTA = 0xFF;

	DDRB = 0xFF; 

	PORTB = 0x00;

	SM1_State = SM1_Start;



	while(1){

		Tick();

}

}



void Tick(){

  switch(SM1_State) {   // Transitions



	case SM1_Start:

        SM1_State = SM1_off;

        break;

	case SM1_off:

        if ((~PINA & 0x0F) == 0x00) {

                SM1_State = SM1_off;

        }

        if ((~PINA & 0x01) == 0x01) {

                SM1_State = SM1_1;

        }
        break;

	case SM1_1:

        if ((~PINA & 0x0F) == 0x00) {

                SM1_State = SM1_1wait;

        }

        if ((~PINA & 0x01) == 0x01) {

                SM1_State = SM1_1;

        }
        break;

	case SM1_1wait:

        if ((~PINA & 0x0F) == 0x00) {

                SM1_State = SM1_1wait;

        }

        if ((~PINA & 0x01) == 0x01) {

                SM1_State = SM1_2;

        }
        break;

	case SM1_2:

        if ((~PINA & 0x0F) == 0x00) {

                SM1_State = SM1_2wait;

        }

        if ((~PINA & 0x01) == 0x01) {

                SM1_State = SM1_2;

        }
        break;

	case SM1_2wait:

        if ((~PINA & 0x0F) == 0x00) {

                SM1_State = SM1_2wait;

        }

        if ((~PINA & 0x01) == 0x01) {

                SM1_State = SM1_3;

        }
        break;

	case SM1_3:

        if ((~PINA & 0x0F) == 0x00) {

                SM1_State = SM1_3wait;

        }

        if ((~PINA & 0x01) == 0x01) {

                SM1_State = SM1_3;

        }
        break;

	case SM1_3wait:

        if ((~PINA & 0x0F) == 0x00) {

                SM1_State = SM1_3wait;

        }

        if ((~PINA & 0x01) == 0x01) {

                SM1_State = SM1_4;

        }
        break;

	case SM1_4:

        if ((~PINA & 0x0F) == 0x00) {

                SM1_State = SM1_4;

        }

        if ((~PINA & 0x01) == 0x01) {

                SM1_State = SM1_4wait;

        }
        break;

	case SM1_4wait:

        if ((~PINA & 0x0F) == 0x00) {

                SM1_State = SM1_off;

        }

        if ((~PINA & 0x01) == 0x01) {

                SM1_State = SM1_4wait;

        }
	break;

     default:

        SM1_State = SM1_Start;

        break;

  } // Transitions



  switch(SM1_State) {   // State actions

     case SM1_Start:

        PORTB = 0;

        break;



     case SM1_off:

	PORTB = 0x00;

        break;



     case SM1_1:
	PORTB = 0x1F;
        break;



     case SM1_1wait:

        break;



     case SM1_2:
	PORTB = 0x05;
        break;



     case SM1_2wait:

	break;

     case SM1_3:
	PORTB = 0x03;
        break;

     case SM1_3wait:

        break;

     case SM1_4:
	PORTB = 0x0C;
        break;

     case SM1_4wait:

        break;



     default:

        break;

   } // State actions


