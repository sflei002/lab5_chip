/*	Author: sflei002
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *DEMO: https://drive.google.com/open?id=1OUl4dX-_IsgeV6h09MdcMBy8v7fQd_ic
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif



enum SM1_States { SM1_Start, SM1_1, SM1_2, SM1_3, SM1_4, SM1_5 } SM1_State;

void Tick();



int main(void){

	DDRA = 0x00;

	PORTA = 0xFF;

	DDRC = 0xFF; 

	PORTC = 0x00;

	SM1_State = SM1_Start;



	while(1){

		Tick();

}

}



void Tick(){

  switch(SM1_State) {   // Transitions



     case SM1_Start:

        SM1_State = SM1_1;

        break;



     case SM1_1:

        if ((~PINA & 0x0F) == 0x00) {

		SM1_State = SM1_1;

        }

	if ((~PINA & 0x01) == 0x01) {

                SM1_State = SM1_2;

		if(PORTC < 0x09){

                PORTC = PORTC + 1;

		}

		else{

			PORTC = 0x09;

		}

	}

        if ((~PINA & 0x02) == 0x02) {

		SM1_State = SM1_3;

		if(PORTC > 0x00){

                PORTC = PORTC - 1;

                }

                else{

                        PORTC = 0x00;

                }

        }

	if ((~PINA & 0x03) == 0x03) {

                SM1_State = SM1_5;

		PORTC = 0x00;

	}

        break;



     case SM1_2:

        if ((~PINA & 0x0F) == 0x00) {

                SM1_State = SM1_4;

        }

        if ((~PINA & 0x01) == 0x01) {

                SM1_State = SM1_2;

        }

        if ((~PINA & 0x03) == 0x03) {

                SM1_State = SM1_5;

		PORTC = 0x00;

        }

        break;



	case SM1_3:

        if ((~PINA & 0x0F) == 0x00) {

                SM1_State = SM1_4;

        }

        if ((~PINA & 0x02) == 0x02) {

                SM1_State = SM1_3;

        }

        if ((~PINA & 0x03) == 0x03) {

                SM1_State = SM1_5;

		PORTC = 0x00;

        }

        break;



	case SM1_4:

        if ((~PINA & 0x0F) == 0x00) {

                SM1_State = SM1_4;

        }

        if ((~PINA & 0x01) == 0x01) {

                SM1_State = SM1_2;

                if(PORTC < 0x09){

                PORTC = PORTC + 1;

                }

                else{

                        PORTC = 0x09;

                }

        }

        if ((~PINA & 0x02) == 0x02) {

                SM1_State = SM1_3;

                if(PORTC > 0x00){

                PORTC = PORTC - 1;

                }

                else{

                        PORTC = 0x00;

                }

        }

        if ((~PINA & 0x03) == 0x03) {

                SM1_State = SM1_5;

		PORTC = 0x00;

        }

        break;



	case SM1_5:

	if ((~PINA & 0x0F) == 0x00) {

                SM1_State = SM1_4;

        }

        if ((~PINA & 0x01) == 0x01) {

                SM1_State = SM1_2;

                if(PORTC < 0x09){

                PORTC = PORTC + 1;

                }

                else{

                        PORTC = 0x09;

                }

        }

        if ((~PINA & 0x02) == 0x02) {

                SM1_State = SM1_3;

                if(PORTC > 0x00){

                PORTC = PORTC - 1;

                }

                else{

                        PORTC = 0x00;

                }

        }

        if ((~PINA & 0x03) == 0x03) {

                SM1_State = SM1_5;

		PORTC = 0x00;

        }

        break;



     default:

        SM1_State = SM1_Start;

        break;

  } // Transitions



  switch(SM1_State) {   // State actions

     case SM1_Start:

        PORTC = 0;

        break;



     case SM1_1:

	PORTC = 0x00;

        break;



     case SM1_2:

        break;



     case SM1_3:

        break;



     case SM1_4:

        break;



     case SM1_5:

	break;



     default:

        break;

   } // State actions

}
