/*
 * ADC.c
 *
 * Created: 1/9/2020 11:46:22 PM
 * Author : sinku
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "IoT.h"

int main(void)
{
	uartInit();
	adcInit();
	int senVal;
	char charVal[5];
	while (1)
	{
		senVal = adcRead(0);	//Connect Analog Sensor to Pin A0
		_delay_ms(1000);
		putCh('\n');
		putStr("Sensor Value is:");
		_delay_ms(1000);
		itoa(senVal, charVal, 10); //Convert integer to String
		putStr("senVal");
		
	}
}