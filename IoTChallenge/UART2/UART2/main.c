/*
 * UART2.c
 *
 * Created: 1/9/2020 11:58:38 PM
 * Author : sinku
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"

int main(void)
{
    uart_init();
    while (1) 
    {
		uart_char('A');
		_delay_ms(100);
		uart_char('\t');
		uart_string("UART 2.0");
		_delay_ms(1000);
		uart_string("\n");
    }
}

