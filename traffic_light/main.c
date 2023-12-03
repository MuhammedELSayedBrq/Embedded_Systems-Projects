#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO_INT.h"
#include "MCAL/DIO_REG.h"
#include "HAL/SEG_INT.h"
#include "MCAL/interrupt.h"
#include "MCAL/timer.h"

#define RED_DURATION 100
#define RED_AND_AMBER_DURATION 100
#define GREEN_DURATION 100
#define AMBER_DURATION 100

#define one_second   23  //for timer 1 

typedef enum {RED, RED_AND_AMBER, GREEN, AMBER} Light_State;


void initizalition();
void send_interrupt();
Light_State Current_State;
u16 Time_in_state;

//sev seg flags
u16 seg_flag;
u16 segg_num;
u8 seg_state;

//flag to turn system on/off
boolean turn_on;	

int main(void){
	
	initizalition();
	while(1){
		
	}
return 0;
}
void initizalition(){
	DIO_SetPinDirection(PORT2,PIN0,INPUT);
	DIO_SetPinDirection(PORT2,PIN1,OUTPUT);
	DIO_SetPinDirection(PORT2,PIN2,OUTPUT);
	DIO_SetPinDirection(PORT2,PIN3,OUTPUT);  //INTR pin
	timer2_interrupt_init();                 //init for timer2 INTR
	timer1_interrupt_init();                 //init for timer1 INTR 
	interrupt_init();                        //init for EX0,EX1 INTR
	Current_State = RED;                     //initial state 
	turn_on = TRUE;                          //system on
	SEG_Init(PORT1);
	Time_in_state = 0;
  segg_num = 3;
	SEG_DisplayNumber(PORT1,segg_num);
  seg_state = 0;
	seg_flag = 0;
}
void timer2_isr() interrupt 5 { 
	TF2 = 0;
	DIO_SetPinDirection(PORT2,PIN3,OUTPUT);
	if(turn_on == TRUE){
	switch(Current_State){
		case RED:
		{
			DIO_SetPinDirection(PORT2,PIN0,INPUT);
			DIO_SetPinDirection(PORT2,PIN1,OUTPUT);
			DIO_SetPinDirection(PORT2,PIN2,OUTPUT);
			if (++Time_in_state == RED_DURATION)
				{
					Time_in_state = 0;
					send_interrupt();
					Current_State = RED_AND_AMBER;
				}
		break;
		}
		case RED_AND_AMBER:
		{
			DIO_SetPinDirection(PORT2,PIN0,INPUT);
			DIO_SetPinDirection(PORT2,PIN1,INPUT);
			DIO_SetPinDirection(PORT2,PIN2,OUTPUT);
			if (++Time_in_state == RED_AND_AMBER_DURATION)
				{
					Current_State = GREEN;
					send_interrupt();
					Time_in_state = 0;
          //Current_State = AMBER;					
		    }
		break;
		}						
		case GREEN:
		{
			DIO_SetPinDirection(PORT2,PIN0,OUTPUT);
			DIO_SetPinDirection(PORT2,PIN1,OUTPUT);
			DIO_SetPinDirection(PORT2,PIN2,INPUT);
			if (++Time_in_state == GREEN_DURATION)
				{
					Current_State = AMBER;
					send_interrupt();
					Time_in_state = 0;
					//Current_State = RED;
				}
		break;
		}
		case AMBER:
		{
			DIO_SetPinDirection(PORT2,PIN0,OUTPUT);
			DIO_SetPinDirection(PORT2,PIN1,INPUT);
			DIO_SetPinDirection(PORT2,PIN2,OUTPUT);
			if (++Time_in_state == AMBER_DURATION)
				{
					Current_State = RED;
					send_interrupt();
					Time_in_state = 0;
					//Current_State = RED_AND_AMBER;
				}
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
	}
void external0_isr() interrupt 0{
	disable_interrupts();
   turn_on = TRUE;
	enable_interrupts();
}
void external1_isr() interrupt 2{
	disable_interrupts();
   turn_on = FALSE;
	enable_interrupts();
}
void send_interrupt(){
	DIO_SetPinDirection(PORT2,PIN3,INPUT);
	delay_ms_timer0(50);
  DIO_SetPinDirection(PORT2,PIN3,OUTPUT);
}
/*
seg_state 0 1 2 3
seg_num initial at 3
switch for seg_state then display seg_num
then if one second ended! dicrement seg_num
note:trans between state to another if seg_num =0
*/
void timer1_isr() interrupt 3{
	TF1 = 0;
	if(turn_on == TRUE){
	switch(seg_state){
		case 0:
		{
			SEG_DisplayNumber(PORT1,segg_num);
			if(seg_flag == one_second){
				seg_flag = 0;
				if(segg_num == 0){
				  segg_num = 3;
					seg_state = 1;}
				else{
				   segg_num--;
				   seg_state = 0;}}	
			else{
				seg_flag++;
				TH1 = 0x3C;   
        TL1 = 0xB0;}
     break;			
		}
		case 1:
			{
			SEG_DisplayNumber(PORT1,segg_num);
			if(seg_flag == one_second){
				seg_flag = 0;
				if(segg_num == 0){
				   seg_state = 2;
				   segg_num = 3;}
				else{
				   segg_num--;
				   seg_state = 1;}
				 }				
			else{
				seg_flag++;
				TH1 = 0x3C;   
        TL1 = 0xB0;}
     break;			
		}
		case 2:
			{
			SEG_DisplayNumber(PORT1,segg_num);
			if(seg_flag == one_second){
				seg_flag = 0;
				if(segg_num == 0){
				   seg_state = 0;
				   segg_num = 3;}
				else{
				   segg_num--;
				   seg_state = 2;}}	
			else{
				seg_flag++;
				TH1 = 0x3C;   
        TL1 = 0xB0;}	
     break; 			
		}				
		}
	}
	}