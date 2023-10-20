#include "LIB\STD_TYPES.h"
#include "LIB\BIT_MATH.h"
#include "MCAL\DIO_INT.h"
#include "HAL\SEG_INT.h"
#include "LIB\DELAY_INT.h"

//{0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}
const u8 SEG_Num[10]={0x03, 0x9F, 0x25, 0x0D, 0x99, 0x49, 0x41, 0x1F, 0x01, 0x09};	

void SEG_Init(u8 SEG_PORT)
{

	DIO_SetPortDirection(SEG_PORT,OUTPUT);
}


void SEG_DisplayNumber(u8 SEG_PORT, u8 Number)
{
	if((Number <=9) &&(Number >=0))
	{
		#if SSD_Type==1
		DIO_SetPortValue(SEG_PORT, SEG_Num[Number]);
		#elif SSD_Type==2
		DIO_SetPortValue(SEG_PORT, ~SEG_Num[Number]);
		#endif
	}
}


void SEG_CountUp(u8 SEG_PORT ,u8 Number)
{
	u8 counter_1;
	for(counter_1 = Number ; counter_1 <= 9; counter_1++)
	{
		SEG_DisplayNumber(SEG_PORT,counter_1);
		  Delay_ms(1000);		
      //_delay_ms(20);
	}

}

void SEG_Countdown(u8 SEG_PORT,u8 Number)
{
	u8 counter_2;
	for(counter_2= Number ; counter_2>= 0 ; counter_2--)
	{
		SEG_DisplayNumber(SEG_PORT,counter_2);
		  Delay_ms(1000);		
      //_delay_ms(20);
	}
}