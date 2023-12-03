#include "LIB\STD_TYPES.h"
#include "LIB\BIT_MATH.h"
#include "MCAL\DIO_INT.h"
#include "MCAL\timer.h"
#include "MCAL\DIO_REG.h"

void timer0_init(u8 mode, u16 initial_value) {
    TMOD &= 0xF0;
    TMOD |= mode;

    TH0 = (u8)(initial_value >> 8);
    TL0 = (u8)initial_value;
}

void timer1_init(u8 mode, u16 initial_value) {
    TMOD &= 0x0F;
    TMOD |= (mode << 4);

    TH1 = (u8)(initial_value >> 8);
    TL1 = (u8)(initial_value);
}

void timer2_init(u8 mode, u16 initial_value) {
    T2CON &= 0xF0;
    T2CON |= mode;

    RCAP2H = (u8)(initial_value >> 8);
    RCAP2L = (u8)initial_value;
}
void timer0_start() {
    TR0 = 1;
}

void timer1_start() {
    TR1 = 1;
}

void timer2_start() {
    TR2 = 1;
}

void timer0_stop() {
    TR0 = 0;
}

void timer1_stop() {
    TR1 = 0;
}

void timer2_stop() {
    TR2 = 0;
}
void delay_ms_timer0(u16 milliseconds) {
    // Assuming a 12 MHz crystal frequency
    // Timer 0 with 16-bit mode, 1 ms = 12,000 counts
    u16 counts = machine_cycle * milliseconds;

    timer0_init(TIMER0_MODE1, 65536 - counts);
    timer0_start();

    while (TF0 == 0) {} // Wait for overflow flag
    timer0_stop();
    TF0 = 0; // Clear the overflow flag
}

void delay_ms_timer1(u16 milliseconds){
    // Assuming a 12 MHz crystal frequency
    // Timer 1 with 16-bit mode, 1 ms = 12,000 counts
	  //u16 label_1 = 12 / Crystal_Freq;
    //u8  label_2 = milliseconds / 1000;	
    u32 counts = machine_cycle * milliseconds;
    timer1_init(TIMER1_MODE1,65536 - counts);
    timer1_start();
    while (TF1 == 0) {} // Wait for overflow flag
    timer1_stop();
    TF1 = 0; // Clear the overflow flag
		}
void delay_second_timer0(u16 seconds){
	int i,j;
	for(i=0;i<seconds;i++){
		for(j=0;j<20;j++){
			delay_ms_timer0(50);
		}
	}
}
void delay_second_timer1(u16 seconds){
	int i,j;
	for(i=0;i<seconds;i++){
		for(j=0;j<20;j++){
			delay_ms_timer1(50);
		}
	}
}
