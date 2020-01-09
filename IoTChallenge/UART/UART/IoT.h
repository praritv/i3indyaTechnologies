#define BAUD_PRESCALE 8									//Change UBRRL Value
#define ref 0x40

void uartInit(){										// UART Initialization
	UCSRB |= (1 << RXEN)|(1 << TXEN);					// Enable Rx and Tx pins from UCSRB
	UCSRC |= (1 << URSEL)| (1 << UCSZ0) | (1 << UCSZ1);	// Enable 8-bit Character Size
	UBRRL = BAUD_PRESCALE;								// UBRRL Value
}

void putCh(char send){									// Character Send
	while(!(UCSRA & (1<<UDRE))){						// Wait While the conversion completes
	}
	UDR=send;											// Character Sent
}

unsigned int getCh(){									// Receiving a Character
	while ((UCSRA & (1 << RXC)) == 0){					// Wait While Receiving Completes
	}
	return UDR;											// Character Received
}

void putStr(char*send){									// String Send
	int i=0;
	while(send[i]!='\0'){								// Initialize String
		while(!(UCSRA & (1<<UDRE)));					// Wait While Sending
		UDR=send[i];
		i++;
	};
}

void adcInit(void){        								// Initialization of ADC
	ADMUX=(1<<REFS0);									//AREF 0
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1); 			//Enable ADC
}

unsigned int adcRead(unsigned char adc_input){			// ADC Read
	ADMUX=adc_input|ref;								// Select ADC Pin
	_delay_us(9);										// Delay needed for the stabilization of the ADC input voltage
	ADCSRA|=0x48;										// Start the AD conversion
	while ((ADCSRA & 0x10)==0);							// Wait for the AD conversion to complete
	return ADCW;
}