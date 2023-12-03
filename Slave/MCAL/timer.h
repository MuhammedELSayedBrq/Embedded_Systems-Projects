#ifndef TIMER_H
#define TIMER_H
#include "LIB/STD_TYPES.h"

#define TIMER0_MODE0    0x00
#define TIMER0_MODE1    0x01
#define TIMER0_MODE2    0x02
#define TIMER0_MODE3    0x03

#define TIMER1_MODE0    0x10
#define TIMER1_MODE1    0x11
#define TIMER1_MODE2    0x12
#define TIMER1_MODE3    0x13

#define TIMER2_MODE0    0x20
#define TIMER2_MODE1    0x21
#define TIMER2_MODE2    0x22
#define TIMER2_MODE3    0x23

#define machine_cycle   1000   //12M-->1000   11.059M---->1085


void timer0_init(u8 mode, u16 initial_value);
void timer1_init(u8 mode, u16 initial_value);
void timer2_init(u8 mode, u16 initial_value);
void timer0_start();
void timer1_start();
void timer2_start();
void timer0_stop();
void timer1_stop();
void timer2_stop();

void delay_ms_timer0(u16 milliseconds);
void delay_ms_timer1(u16 milliseconds);

void delay_second_timer0(u16 seconds);
void delay_second_timer1(u16 seconds);

