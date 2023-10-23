/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BUT_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Auther: Repo Collabs
Layer : HAL.
SWC   : BUTTON.
*/

#include "STD_TYPES.h"
// #include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DEL_interface.h"

#include "BUT_interface.h"
// #include "BUT_private.h"
// #include "BUT_config.h"

void BUT_init(BUT_type button)
{
    DIO_SetPinDirection(button.Port_in, button.Pin_in, DIO_PIN_INPUT);
}
bit BUT_pressed(BUT_type button)
{
    bit State = 0;
    if (button.Type == BUT_PULL_UP)
    {
        if (DIO_GetPinValue(button.Port_in, button.Pin_in))
        {
            delay_ms(20);
            if (DIO_GetPinValue(button.Port_in, button.Pin_in))
            {
                State = 1;
                while (DIO_GetPinValue(button.Port_in, button.Pin_in))
                    ;
            }
        }
    }
    else if (button.Type == BUT_PULL_DOWN)
    {
        if (DIO_GetPinValue(button.Port_in, button.Pin_in) == 0)
        {
            delay_ms(20);
            if (DIO_GetPinValue(button.Port_in, button.Pin_in) == 0)
            {
                State = 1;
                while (DIO_GetPinValue(button.Port_in, button.Pin_in) == 0)
                    ;
            }
        }
    }
    return State;
}
