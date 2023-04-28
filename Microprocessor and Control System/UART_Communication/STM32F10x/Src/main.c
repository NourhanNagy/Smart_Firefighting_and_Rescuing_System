#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "USART_interface.h"
#include "USART_private.h"

int main(void)
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);   
	RCC_voidEnableClock(RCC_APB2,14);


	/* Setting A9:TX pin as Output alternate function push pull w max speed 50 MHz */
	MGPIO_VidSetPinDirection(GPIOA,9,OUTPUT_SPEED_50MHZ_AFPP);
	/* Setting A10:RX pin as input floating */
	MGPIO_VidSetPinDirection(GPIOA,10,INPUT_FLOATING);

	MGPIO_VidSetPinDirection(GPIOA,0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA,5,OUTPUT_SPEED_2MHZ_PP);

	MUSART1_voidInit();
	while(1)
	{	
		if(MUSART1_u8Receive() == "Q1")
		{
			#Write down from the Servo motor's functions what you see fit
		}
		else if(MUSART1_u8Receive() == "Q2")
		{
			#Write down from the Servo motor's functions what you see fit
		}
		else if(MUSART1_u8Receive() == "Q3")
		{
			#Write down from the Servo motor's functions what you see fit
		}
		else if(MUSART1_u8Receive() == "Q4")
		{
			#Write down from the Servo motor's functions what you see fit
		}
		else if(MUSART1_u8Receive() == "NF")
		{
			//Shut system Down 
		}
		else 
		{
			//DO NOTHINHG
			
		}
		
	}
}

