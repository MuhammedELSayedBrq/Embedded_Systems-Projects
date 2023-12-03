#include "MCAL/interrupt.h"
#include "MCAL/DIO_REG.h"

void interrupt_init() {

       EX0 = 1;
	     EX1 = 1;
    // ET0 = 1;
	     ET1 = 1;
    // ES = 1;
       EA = 1;
}

void enable_interrupts() {
    EA = 1;
}

void disable_interrupts() {
    EA = 0;
}
void timer1_interrupt_init() {
    TMOD |= 0x10; 
    TH1 = 0x63;   
    TL1 = 0xC0;
    ET1 = 1;
    EA  = 1;
	  TR1 = 1;
}
void timer2_interrupt_init() {
	
    T2CON  = 0x04;   
    TH2    = 0x3C;
	  RCAP2H = 0x3C;   
    TL2    = 0xB0;
	  RCAP2L = 0xB0;
    ET2 = 1;
    EA = 1;
	  TR2 = 1;
}