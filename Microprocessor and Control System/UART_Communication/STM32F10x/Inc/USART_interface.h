#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H


#define Word_Length_8_Data_Bits         0
#define Word_Length_9_Data_Bits         1 

#define Parity_Control_Enable           1
#define Parity_Control_Disable          0

#define Parity_Selection_Even           0
#define Parity_Selection_Odd            1


#define PE_Interrupt_Enable             1
#define PE_Interrupt_Disable            0

#define TXE_Interrupt_Enable            1
#define TXE_Interrupt_Disable           0

#define TCIE_Interrupt_Enable           1
#define TCIE_Interrupt_Disable          0

#define RXNE_Interrupt_Enable           1
#define RXNE_Interrupt_Disable          0

#define IDLE_Interrupt_Enable           1
#define IDLE_Interrupt_Disable          0

#define Transmitter_Enbaled             1
#define Transmitter_Disabled            0

#define Reciever_Enbaled                1
#define Reciever_Disabled               0

#define USART_Enable                    1
#define USART_Disable                   0

#define One_Stop_Bit                    0
#define One_And_Half_Stop Bit           1
#define Two_Stop_Bits                   2
#define Two_And_Half_Stop_Bits          3


void MUSART1_voidInit(void);

void MUSART1_voidTransmit(u8 copy_u8senddata);

u8 MUSART1_u8Receive(void);

#endif