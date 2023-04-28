
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct{
	volatile u32	SR;
	volatile u32	DR;
	volatile u32	BRR;
	volatile u32	CR1;
	volatile u32	CR2;
	volatile u32	CR3;
	volatile u32	GTPR;
}UART_TYBES;
#define UART ((volatile UART_TYBES *)0x40013800)

#endif