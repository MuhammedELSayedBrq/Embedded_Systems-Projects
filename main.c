#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO_INT.h"
#include "HAL/SEG_INT.h"
#include "LIB/DELAY_INT.h"

#define sec_digit_0 5
#define sec_digit_1 4
#define min_digit_0 3
#define min_digit_1 2
#define	hou_digit_0 1
#define	hou_digit_1 0

u8 Start = 0,i;

u8 Ho_1 = 2, Ho_0 = 3, Min_1 = 5,	Min_0 = 9, Sec_1 = 5, Sec_0 = 5;
u8 Digits[6] = {0x20, 0x10, 0x08, 0x04, 0x02, 0x01};	
u8 start_Button, set_Button,next_Button,inc_Button;



void set_clock(){
	u8 index = 0;
	while(!Start){
		start_Button = DIO_GetPinValue(PORT1,PIN0);
		set_Button   = DIO_GetPinValue(PORT1,PIN1);
		next_Button  = DIO_GetPinValue(PORT1,PIN2);
		inc_Button   = DIO_GetPinValue(PORT1,PIN3);
		
		switch(index){
			case 0:
				DIO_SetPortValue(PORT3,Digits[hou_digit_1]);
				SEG_DisplayNumber(PORT2,Ho_1);
				break;
			case 1:
				DIO_SetPortValue(PORT3,Digits[hou_digit_0]);
				SEG_DisplayNumber(PORT2,Ho_0);
				break;
			case 2:
				DIO_SetPortValue(PORT3,Digits[min_digit_1]);
				SEG_DisplayNumber(PORT2,Min_1);
				break;
			case 3:
				DIO_SetPortValue(PORT3,Digits[min_digit_0]);
				SEG_DisplayNumber(PORT2,Min_0);
				break;
			case 4:
				DIO_SetPortValue(PORT3,Digits[sec_digit_1]);
				SEG_DisplayNumber(PORT2,Sec_1);
				break;
			default :
				DIO_SetPortValue(PORT3,Digits[sec_digit_0]);
				SEG_DisplayNumber(PORT2,Sec_0);
				//delay(5);
		}
		if(!start_Button){
			Delay_ms(20);
			if(!start_Button){
				Start = 1;
				while(!start_Button) start_Button = DIO_GetPinValue(PORT1,PIN0);
			}
		}
		
		if(!next_Button){
			Delay_ms(20);
			if(!next_Button){
				index = (index + 1)%6;
				while(!next_Button) next_Button  = DIO_GetPinValue(PORT1,PIN2);
			}
		}
		if(!inc_Button){
			Delay_ms(20);
			if(!inc_Button){
				switch(index){
					case 0:
						if(Ho_0 > 3) Ho_1 = (Ho_1 + 1)%2;
						else Ho_1 = (Ho_1 + 1)%3;
						break;
					case 1:
						if(Ho_1 == 2)Ho_0 = (Ho_0 + 1)%4;
						else Ho_0 = (Ho_0 + 1)%10;
						break;
					case 2:
						Min_1 = (Min_1 + 1)%6;
						break;
					case 3:
						Min_0 = (Min_0 + 1)%10;
						break;
					case 4:
						Sec_1 = (Sec_1 + 1)%6;
						break;
					default :
						Sec_0 = (Sec_0 + 1)%10;
				}
				while(!inc_Button) inc_Button = DIO_GetPinValue(PORT1,PIN3);
			}
		}
	}	
}

void main (void)
{
	SEG_Init(PORT2);
  DIO_SetPortDirection(PORT3,OUTPUT);
	start_Button = 1;
	set_Button = 1;
	next_Button = 1;
	inc_Button = 1;

while (1)
	{
	start_Button = DIO_GetPinValue(PORT1,PIN0);
	set_Button   = DIO_GetPinValue(PORT1,PIN1);
	next_Button  = DIO_GetPinValue(PORT1,PIN2);
  inc_Button   = DIO_GetPinValue(PORT1,PIN3);
		// Check if start_Button is pressed
		if(!start_Button){
			Delay_ms(20);
			if(!start_Button){
				Start = 1;
				while(!start_Button) start_Button = DIO_GetPinValue(PORT1,PIN0);
			}
		}
		if(Start){
			for(i=0; i<33; i++){
				DIO_SetPortValue(PORT3,Digits[sec_digit_0]);
				SEG_DisplayNumber(PORT2,Sec_0);
				Delay_ms(5);
		
				DIO_SetPortValue(PORT3,Digits[sec_digit_1]);
				SEG_DisplayNumber(PORT2,Sec_1);
				Delay_ms(5);
				
				DIO_SetPortValue(PORT3,Digits[min_digit_0]);
				SEG_DisplayNumber(PORT2,Min_0);
				Delay_ms(5);
				
				DIO_SetPortValue(PORT3,Digits[min_digit_1]);
				SEG_DisplayNumber(PORT2,Min_1);
				Delay_ms(5);
				
				DIO_SetPortValue(PORT3,Digits[hou_digit_0]);
				SEG_DisplayNumber(PORT2,Ho_0);
				Delay_ms(5);
				
				DIO_SetPortValue(PORT3,Digits[hou_digit_1]);
				SEG_DisplayNumber(PORT2,Ho_1);
				Delay_ms(5);
	
				/*
				//Check if set_Button is pressed
				if(!set_Button){
					Delay_ms(20);
					if(!set_Button){
						Start = 0;
						while(!set_Button);
						set_clock();
					}
				}
				*/
				if(!set_Button){
					Start = 0;
					set_clock();
						}	
			}

			Sec_0 = (Sec_0 + 1)%10;
			if(Sec_0 == 0)Sec_1 = (Sec_1 + 1)%6;
			if((Sec_1 == 0)&&(Sec_0 == 0))Min_0 = (Min_0 + 1)%10;
			if((Min_0 == 0)&&(Sec_1 == 0)&&(Sec_0 == 0))Min_1 = (Min_1 + 1)%6;
			if((Min_1 == 0)&&(Min_0 == 0)&&(Sec_1 == 0)&&(Sec_0 == 0)){
				if((Ho_1 == 2)&&(Ho_0 == 3))Ho_0 = 0;
				else Ho_0 = (Ho_0 + 1)%10;
			}
			if((Ho_0 == 0)&&(Min_1 == 0)&&(Min_0 == 0)&&(Sec_1 == 0)&&(Sec_0 == 0))Ho_1 = (Ho_1 + 1)%3;
		}	
	}		  	
}
	


