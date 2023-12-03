#ifndef INTERRUPT_H
#define INTERRUPT_H


void interrupt_init();
void enable_interrupts();
void disable_interrupts();
void timer1_interrupt_init();
void timer2_interrupt_init();

#endif 


//body of main code
/*
#define time_ticks 20	
	u8 ticks = 0;
	
int main(void){
	DIO_SetPinDirection(PORT2,PIN2,INPUT);
	timer_interrupt_init();
	while(1){
		//DIO_SetPinDirection(PORT2,PIN2,INPUT);
	}
return 0;
}
void timer2_isr() interrupt 5 {
		TF2 = 0;
    // This ISR is called every 1 second
    // Toggle the LED state
	  if(ticks > time_ticks){
		DIO_SetPinDirection(PORT2,PIN2,OUTPUT);
			ticks = 0;
		}
		else
			ticks++;
}
*/