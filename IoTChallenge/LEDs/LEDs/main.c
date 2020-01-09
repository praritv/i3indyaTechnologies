/*
 * LEDs.c
 *
 * Created: 1/9/2020 11:34:29 PM
 * Author : sinku
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0b11111111;
	//DDRB = 0xFF;
	//DDRB = 255;
	//DDRB = 0377;
    while (1) 	
    {
		PORTB = 0b11111111;
		//PORTB = 0xFF;
		//PORTB = 255;
		//PORTB = 0377;
		_delay_ms(1000);
		PORTB = 0b00000000;
		_delay_ms(1000);
    }
}

