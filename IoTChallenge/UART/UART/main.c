/*
 * UART.c
 *
 * Created: 1/9/2020 11:43:46 PM
 * Author : sinku
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "IoT.h"

int main(void)
{
    uartInit();
    while (1) 
    {
		putCh('Z');
		_delay_ms(1000);
		putCh('\n');
		putStr("Hello from UART");
		_delay_ms(1000);
		putStr("\r");
		
    }
}

