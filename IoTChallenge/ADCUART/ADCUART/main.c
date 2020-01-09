/*
 * ADCUART.c
 *
 * Created: 1/10/2020 12:03:13 AM
 * Author : sinku
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"
#include "ADC.h"

int main(void)
{
	uart_init();
	adc_init();
	unsigned char senVal;
	while (1)
	{
		senVal = getdata(0); //Connect analog sensor to pin A0 
		_delay_ms(100);
		uart_string("Sensor Value is: ");
		uart_num(senVal);
		uart_string("\n");
		_delay_ms(1000);
	}
}


