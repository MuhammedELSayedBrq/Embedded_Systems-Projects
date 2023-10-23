/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BUT_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Auther: Repo Collabs
Layer : HAL.
SWC   : BUTTON.
*/

#ifndef BUT_interface_H_
#define BUT_interface_H_

#define BUT_PULL_UP 1
#define BUT_PULL_DOWN 0

#define BUT_P0 0
#define BUT_P1 1
#define BUT_P2 2
#define BUT_P3 3

#define BUT_PIN0 0
#define BUT_PIN1 1
#define BUT_PIN2 2
#define BUT_PIN3 3
#define BUT_PIN4 4
#define BUT_PIN5 5
#define BUT_PIN6 6
#define BUT_PIN7 7

typedef struct
{
    u8 Type;
    u8 Port_in;
    u8 Pin_in;
} BUT_type;

void BUT_init(BUT_type button);
bit BUT_pressed(BUT_type button);

#endif // BUT_interface_H_
