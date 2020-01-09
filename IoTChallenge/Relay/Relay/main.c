/*
 * Relay.c
 *
 * Created: 1/9/2020 11:41:40 PM
 * Author : sinku
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD = 0xFF;	//Connect Relay to any of the Pin
    while (1) 
    {
		PORTD = 0xF0;
		_delay_ms(1000);
		PORTD = 0x0F;
		_delay_ms(1000);
    }
}

