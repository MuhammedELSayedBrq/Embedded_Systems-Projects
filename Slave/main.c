#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO_INT.h"
#include "MCAL/DIO_REG.h"
#include "HAL/SEG_INT.h"
#include "MCAL/interrupt.h"

typedef enum {RED, RED_AND_AMBER, GREEN, AMBER} Light_State;
Light_State Current_State;
void initizalition();
	
int main(void){
	
	initizalition();
	while(1){
		
	}
return 0;
}

void initizalition(){
	DIO_SetPinDirection(PORT2,PIN0,OUTPUT);
	DIO_SetPinDirection(PORT2,PIN1,OUTPUT);
	DIO_SetPinDirection(PORT2,PIN2,INPUT);
	DIO_SetPinDirection(PORT3,PIN3,INPUT);    //INTR PIN
	interrupt_init();
	Current_State = GREEN;
}

void external0_isr() interrupt 0 { 
	
	Current_State = (Current_State +1) % 4;
	switch(Current_State){
		case RED:
		{
			DIO_SetPinDirection(PORT2,PIN0,INPUT);
			DIO_SetPinDirection(PORT2,PIN1,OUTPUT);
			DIO_SetPinDirection(PORT2,PIN2,OUTPUT);
		break;
		}
		case RED_AND_AMBER:
		{
			DIO_SetPinDirection(PORT2,PIN0,INPUT);
			DIO_SetPinDirection(PORT2,PIN1,INPUT);
			DIO_SetPinDirection(PORT2,PIN2,OUTPUT);
		break;
		}						
		case GREEN:
		{
			DIO_SetPinDirection(PORT2,PIN0,OUTPUT);
			DIO_SetPinDirection(PORT2,PIN1,OUTPUT);
			DIO_SetPinDirection(PORT2,PIN2,INPUT);
		break;
		}
		case AMBER:
		{
			DIO_SetPinDirection(PORT2,PIN0,OUTPUT);
			DIO_SetPinDirection(PORT2,PIN1,INPUT);
			DIO_SetPinDirection(PORT2,PIN2,OUTPUT);
		break;
		}
		default:{
			DIO_SetPinDirection(PORT2,PIN0,INPUT);
			DIO_SetPinDirection(PORT2,PIN1,INPUT);
			DIO_SetPinDirection(PORT2,PIN2,INPUT);
			break;
		}
     }
	 }