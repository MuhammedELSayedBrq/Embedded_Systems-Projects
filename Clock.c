#include "STD_TYPES.h"
//#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DEL_interface.h"

#include "SSD_interface.h"
#include "BUT_interface.h"

#define HOU1 0
#define HOU0 1
#define MIN1 2		
#define MIN0 3
#define SEC1 4
#define SEC0 5

SSD_type hou_digit_1={SSD_COMM_ANODE, SSD_P2, SSD_P3, SSD_PIN5};
SSD_type hou_digit_0={SSD_COMM_ANODE, SSD_P2, SSD_P3, SSD_PIN4};
SSD_type min_digit_1={SSD_COMM_ANODE, SSD_P2, SSD_P3, SSD_PIN3};
SSD_type min_digit_0={SSD_COMM_ANODE, SSD_P2, SSD_P3, SSD_PIN2};
SSD_type sec_digit_1={SSD_COMM_ANODE, SSD_P2, SSD_P3, SSD_PIN1};
SSD_type sec_digit_0={SSD_COMM_ANODE, SSD_P2, SSD_P3, SSD_PIN0};

BUT_type start_Button ={BUT_PULL_DOWN, BUT_P1, BUT_PIN0};
BUT_type set_Button   ={BUT_PULL_DOWN, BUT_P1, BUT_PIN1};
BUT_type next_Button  ={BUT_PULL_DOWN, BUT_P1, BUT_PIN2};
BUT_type inc_Button   ={BUT_PULL_DOWN, BUT_P1, BUT_PIN3};

u8 Ho_1 = 0, Ho_0 = 0, Min_1 = 0,	Min_0 = 0, Sec_1 = 0, Sec_0 = 0;

//u8 i, 
bit Start = 0;

void En_Dis(u8 index){
	switch(index){
		case 0:
			SSD_disable(hou_digit_0);
			SSD_disable(min_digit_1);
			SSD_disable(min_digit_0);
			SSD_disable(sec_digit_1);
			SSD_disable(sec_digit_0);
			SSD_enable(hou_digit_1);
			SSD_SendData(hou_digit_1, Ho_1);
			break;
		case 1:
			SSD_disable(hou_digit_1);
			SSD_disable(min_digit_1);
			SSD_disable(min_digit_0);
			SSD_disable(sec_digit_1);
			SSD_disable(sec_digit_0);
			SSD_enable(hou_digit_0);
			SSD_SendData(hou_digit_0, Ho_0);
			break;
		case 2:
			SSD_disable(hou_digit_1);
			SSD_disable(hou_digit_0);
			SSD_disable(min_digit_0);
			SSD_disable(sec_digit_1);
			SSD_disable(sec_digit_0);
			SSD_enable(min_digit_1);
			SSD_SendData(min_digit_1, Min_1);
			break;
		case 3:
			SSD_disable(hou_digit_1);
			SSD_disable(hou_digit_0);
			SSD_disable(min_digit_1);
			SSD_disable(sec_digit_1);
			SSD_disable(sec_digit_0);
			SSD_enable(min_digit_0);
			SSD_SendData(min_digit_0, Min_0);
			break;
		case 4:
			SSD_disable(hou_digit_1);
			SSD_disable(hou_digit_0);
			SSD_disable(min_digit_0);
			SSD_disable(min_digit_1);
			SSD_disable(sec_digit_0);
			SSD_enable(sec_digit_1);
			SSD_SendData(sec_digit_1, Sec_1);
			break;
		case 5:
			SSD_disable(hou_digit_1);
			SSD_disable(hou_digit_0);
			SSD_disable(min_digit_0);
			SSD_disable(min_digit_1);
			SSD_disable(sec_digit_1);
			SSD_enable(sec_digit_0);
			SSD_SendData(sec_digit_0, Sec_0);
			break;
	}
	return;
}

void Set_Clock(){
	u8 INDEX = 0;
	while(Start == 0){
		En_Dis(INDEX);
		delay_ms(5);

		if(BUT_pressed(start_Button))Start = 1;

		if(BUT_pressed(next_Button))INDEX = (INDEX + 1)%6;

		if(BUT_pressed(inc_Button)){
			switch(INDEX){
				case 0:
					if(Ho_0 > 3)Ho_1 = (Ho_1 + 1)%2;
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
		}
	}
}

int main(){
    SSD_init(hou_digit_1);
    SSD_init(hou_digit_0);
    SSD_init(min_digit_1);
    SSD_init(min_digit_0);
    SSD_init(sec_digit_1);
    SSD_init(sec_digit_0);		

    BUT_init(start_Button);
    BUT_init(set_Button);
    BUT_init(next_Button);
    BUT_init(inc_Button);

	
	while(1){
		if(BUT_pressed(start_Button))Start = 1;
		if(Start == 1){
			u8 i;
			for(i = 0; i < 33; i++){
				En_Dis(HOU1);
				delay_ms(5);

				En_Dis(HOU0);
				delay_ms(5);

				En_Dis(MIN1);
				delay_ms(5);

				En_Dis(MIN0);
				delay_ms(5);

				En_Dis(SEC1);
				delay_ms(5);

				En_Dis(SEC0);
				delay_ms(5);

				if(BUT_pressed(set_Button)){
					Start = 0;
					Set_Clock();
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
	return 0;
}
