#ifndef _DIO_INT_H
#define _DIO_INT_H

/* Port Defines */
#define PORT0    0
#define PORT1    1
#define PORT2    2
#define PORT3    3

/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

/* PIN Directions */
#define INPUT  0
#define OUTPUT 1

/* Prototypes */

/* Set pin as Output or Input */
void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);

/* Set pin as Output or Input */
void DIO_SetPortDirection (u8 u8PortIdCopy, u8 u8PortDirCopy);

/* if pin is input - get value */
u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

/* Set Value To port */
void DIO_SetPortValue(u8 u8PortIdCopy,  u8 u8PortVal);

#endif