/*
 * Buzzer.c
 *
 * Created: 1/9/2020 11:39:31 PM
 * Author : sinku
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRA = 0b10000000;
	//DDRA = (1<<7);
    while (1) 
    {
		PORTA = 0b10000000;
		_delay_ms(1000);
		PORTA = 0b00000000;
		_delay_ms(1000);
    }
}

