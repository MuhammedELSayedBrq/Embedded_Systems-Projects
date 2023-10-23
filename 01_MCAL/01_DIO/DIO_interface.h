/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DIO_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * Author : Repo Collabs
 * Layer  : MCAL.
 * SWC    : DIO.
 */

#ifndef DIO_interface_H_
#define DIO_interface_H_

#define DIO_PIN_INPUT  1
#define DIO_PIN_OUTPUT 0

#define DIO_P0 0
#define DIO_P1 1
#define DIO_P2 2
#define DIO_P3 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW  0

#define DIO_PORT_INPUT 0xFF
#define DIO_PORT_OUTPUT 0

#define DIO_PORT_HIGH 0xFF
#define DIO_PORT_LOW 0

void DIO_SetPinDirection(u8 port, u8 pin, bit direction);
void DIO_SetPinValue(u8 port, u8 pin, bit value);
void DIO_TogglePinValue(u8 port, u8 pin);
bit DIO_GetPinValue(u8 port, u8 pin);

void DIO_SetPortDirection(u8 port, u8 direction);
void DIO_SetPortValue(u8 port, u8 value);
void DIO_TogglePortValue(u8 port);
u8 DIO_GetPortValue(u8 port);

#endif // DIO_interface_H_
