/*	Author: smesd001
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: Illuminate garage door light if grage door is open at night
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00; 
	
	unsigned char tmpB = 0x00;
	unsigned char tmpA = 0x00;
    while (1) {

	tmpA = PINA & 0x01;

	if (tmpA == 0x01) {
		tmpB = (tmpB & 0xFC) | 0x01;
	} else {
		tmpB = (tmpB & 0xFC) | 0x02;
	}
	PORTB = tmpB;
    }
    return 0;
}
