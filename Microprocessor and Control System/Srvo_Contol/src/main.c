

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "RCC_interface.h"


void fun1(void){
	u8 servo_flag=0;
	while(servo_flag<25){
	MGPIO_VidSetPinValue(GPIOA,1,HIGH);
	MSTK_voidSetBusyWait(1000);
	MGPIO_VidSetPinValue(GPIOA,1,LOW);
	MSTK_voidSetBusyWait(19000);
	servo_flag++;
	}
	MSTK_voidSetBusyWait(1000000);
}
void fun2(void){
	u8 servo_flag=0;
	while(servo_flag<25){
	MGPIO_VidSetPinValue(GPIOA,1,HIGH);
	MSTK_voidSetBusyWait(2000);
	MGPIO_VidSetPinValue(GPIOA,1,LOW);
	MSTK_voidSetBusyWait(18000);
	servo_flag++;
		}
	MSTK_voidSetBusyWait(100000);
}
void fun3(void){
	u8 servo_flag=0;
		while(servo_flag<25){
	MGPIO_VidSetPinValue(GPIOA,1,HIGH);
	MSTK_voidSetBusyWait(1500);
	MGPIO_VidSetPinValue(GPIOA,1,LOW);
	MSTK_voidSetBusyWait(18500);
	servo_flag++;
			}
		MSTK_voidSetBusyWait(500000);
}
void main(void)
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);   
	RCC_voidEnableClock(RCC_APB2,14);
	//RCC_voidEnableClock(RCC_APB2,12);

	MGPIO_VidSetPinDirection(GPIOA,1,0b0010);

	MGPIO_VidSetPinDirection(GPIOA,8,0b0010);

	MGPIO_VidSetPinDirection(GPIOA,10,0b0010);
	MGPIO_VidSetPinDirection(GPIOA , 7 , INPUT_PULLUP_PULLDOWN);
		MGPIO_VidSetPinValue(GPIOA , 7 , HIGH);
	MGPIO_VidSetPinDirection(GPIOA , 8 , INPUT_PULLUP_PULLDOWN);
		MGPIO_VidSetPinValue(GPIOA , 8 , HIGH);
	MGPIO_VidSetPinDirection(GPIOA , 9 , INPUT_PULLUP_PULLDOWN);
		MGPIO_VidSetPinValue(GPIOA , 9 , HIGH);
	MSTK_voidInit();

	MGPIO_VidSetPinValue(GPIOA,1,LOW);

	while(1){
		if(MGPIO_u8GetPinValue(GPIOA ,7) == 0)
		{
		fun1();
		}
		else if(MGPIO_u8GetPinValue(GPIOA ,8) == 0)
		{
		fun2();
		}
		else if(MGPIO_u8GetPinValue(GPIOA ,9) == 0)
		{
		fun3();
 		}
			}

}

