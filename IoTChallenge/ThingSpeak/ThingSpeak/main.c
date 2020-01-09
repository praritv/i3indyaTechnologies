/*
 * ThingSpeak.c
 *
 * Created: 1/10/2020 12:34:48 AM
 * Author : sinku
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "adc.h"


int main(void)
{
	/* Replace with your application code */
	DDRB=0b11111111;
	unsigned char digital;
	uart_init();
	adc_init();
	uart_string("AT+RST\r\n");
	_delay_ms(5000);
	PORTB=0b11111111;
	uart_string("ATE0\r\n");
	PORTB=0b1111111;
	uart_string("AT+CWMODE=3\r\n");
	_delay_ms(100);
	PORTB=0b111111;
	uart_string("AT+CWJAP=\"asdf\",\"1234567890\"\r\n");
	_delay_ms(5000);
	while(1){
		digital=getdata(0);
		PORTB=0b11111;
		uart_string("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n");
		_delay_ms(2000);
		uart_string("AT+CIPSEND=51\r\n");
		_delay_ms(100);
		PORTB=0b1111;
		uart_string("GET /update?api_key=OLEO7WDA3HTNJKZ9&field1=");
		uart_num(digital);
		uart_string("\r\n");
		PORTB=0b111;
		_delay_ms(100);
		uart_string("AT+CIPCLOSE\r\n");
		PORTB=0b11;
		_delay_ms(100);
		PORTB=0b1;
		_delay_ms(15000);
	}
}

