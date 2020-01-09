/*
 * Mixed.c
 *
 * Created: 1/10/2020 12:14:30 AM
 * Author : sinku
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = (1<<7);
	DDRB = 0xFF;
	DDRD = 0xFF;
	while (1)
	{
		PORTB = 0xF0;
		_delay_ms(1000);
		PORTB = 0x0F;
		_delay_ms(1000);
		PORTA = (1<<7);
		_delay_ms(500);
		PORTA = (0<<7);
		_delay_ms(200);
		PORTD = 0xF0;
		_delay_ms(1000);
		PORTD = 0x0F;
	}
}

