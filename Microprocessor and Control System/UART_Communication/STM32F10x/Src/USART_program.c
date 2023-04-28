
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"


void MUSART1_voidInit(void)
{
	
	
	/*	baud rate*/
	#if baud_rate_value==4800
	UART->BRR=0X683;
	#elif baud_rate_value==9600
	UART->BRR=0X341;
	#elif baud_rate_value==115200
	UART->BRR=0X45;
	#endif

	UART->CR1=0X0200;
	UART->CR1=0X200C;
}

void MUSART1_voidTransmit(u8 copy_u8senddata)
{
	UART->DR=copy_u8senddata;
	
}
/*
void 	MUSART1_voidSendString(u8 array[])
{
  u8 i = 0 ;
  while(array[i] != '\0')
  {
    UART -> DR = array[i] ;
    while(GET_BIT (UART -> SR , 6) == 0);
    i++;
  }
}
*/



u8 MUSART1_u8Receive(void)
{
//u16 timeout=0;
//u8 loc_u8recived=0;
//while ((GET_BIT((UART->SR),5)) == 0){
//	timeout++;
//	if(timeout == 10000){
//		loc_u8recived=255;
//		break;
//	}
//}
//	if(loc_u8recived == 0){
//
//		loc_u8recived= UART->DR;
//
//	}
//	return(loc_u8recived);

	u8 local_uartrecived=0;
	while((GET_BIT((UART -> SR), 5)) == 0);
	local_uartrecived=UART->DR;
	return (local_uartrecived);
}




















