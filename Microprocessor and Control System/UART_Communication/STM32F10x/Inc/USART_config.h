#ifndef USART_CONFIG_H
#define USART_CONFIG_H

/* 
	Baud rate to be implemented 
	
	For 8MHz:-
	9600-> 52.083 :-
	F=1
	M=34
	
	115200-> 4.34 :-
	F=5
	M=4
*/


/*
4800
9600
115200
*/

#define baud_rate_value 15200

#define USART_STATUS                    USART_ENABLE
#define USART_TRANSMITTER_STATUS        TRANSMITTER_ENABLE
#define USART_RECIEVER_STATUS           RECIEVER_ENABLE

#define PARITY_CONTROL                  PARITY_Disable
#define INTERRUPT_STATUS                INTERRUPT_DISABLE

#define USART_WORD_SIZE                 8_BITS_WORD_SIZE

#define USART_STOP_BITS                 ONE_STOP_BIT
#endif
