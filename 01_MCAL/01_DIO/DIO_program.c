/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DIO_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * Author : Repo Collabs
 * Layer  : MCAL.
 * SWC    : DIO.
 */

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_private.h"

void DIO_SetPinDirection(u8 port, u8 pin, bit direction)
{
    switch (port)
    {
    case 0:
        switch (pin)
        {
        case 0:
            P0_0 = direction;
            break;
        case 1:
            P0_1 = direction;
            break;
        case 2:
            P0_2 = direction;
            break;
        case 3:
            P0_3 = direction;
            break;
        case 4:
            P0_4 = direction;
            break;
        case 5:
            P0_5 = direction;
            break;
        case 6:
            P0_6 = direction;
            break;
        case 7:
            P0_7 = direction;
            break;
        }
        break;
    case 1:
        switch (pin)
        {
        case 0:
            P1_0 = direction;
            break;
        case 1:
            P1_1 = direction;
            break;
        case 2:
            P1_2 = direction;
            break;
        case 3:
            P1_3 = direction;
            break;
        case 4:
            P1_4 = direction;
            break;
        case 5:
            P1_5 = direction;
            break;
        case 6:
            P1_6 = direction;
            break;
        case 7:
            P1_7 = direction;
            break;
        }
        break;
    case 2:
        switch (pin)
        {
        case 0:
            P2_0 = direction;
            break;
        case 1:
            P2_1 = direction;
            break;
        case 2:
            P2_2 = direction;
            break;
        case 3:
            P2_3 = direction;
            break;
        case 4:
            P2_4 = direction;
            break;
        case 5:
            P2_5 = direction;
            break;
        case 6:
            P2_6 = direction;
            break;
        case 7:
            P2_7 = direction;
            break;
        }
        break;
    case 3:
        switch (pin)
        {
        case 0:
            P3_0 = direction;
            break;
        case 1:
            P3_1 = direction;
            break;
        case 2:
            P3_2 = direction;
            break;
        case 3:
            P3_3 = direction;
            break;
        case 4:
            P3_4 = direction;
            break;
        case 5:
            P3_5 = direction;
            break;
        case 6:
            P3_6 = direction;
            break;
        case 7:
            P3_7 = direction;
            break;
        }
        break;
    }
    return;
}
void DIO_SetPinValue(u8 port, u8 pin, bit value)
{
    switch (port)
    {
    case 0:
        switch (pin)
        {
        case 0:
            P0_0 = value;
            break;
        case 1:
            P0_1 = value;
            break;
        case 2:
            P0_2 = value;
            break;
        case 3:
            P0_3 = value;
            break;
        case 4:
            P0_4 = value;
            break;
        case 5:
            P0_5 = value;
            break;
        case 6:
            P0_6 = value;
            break;
        case 7:
            P0_7 = value;
            break;
        }
        break;
    case 1:
        switch (pin)
        {
        case 0:
            P1_0 = value;
            break;
        case 1:
            P1_1 = value;
            break;
        case 2:
            P1_2 = value;
            break;
        case 3:
            P1_3 = value;
            break;
        case 4:
            P1_4 = value;
            break;
        case 5:
            P1_5 = value;
            break;
        case 6:
            P1_6 = value;
            break;
        case 7:
            P1_7 = value;
            break;
        }
        break;
    case 2:
        switch (pin)
        {
        case 0:
            P2_0 = value;
            break;
        case 1:
            P2_1 = value;
            break;
        case 2:
            P2_2 = value;
            break;
        case 3:
            P2_3 = value;
            break;
        case 4:
            P2_4 = value;
            break;
        case 5:
            P2_5 = value;
            break;
        case 6:
            P2_6 = value;
            break;
        case 7:
            P2_7 = value;
            break;
        }
        break;
    case 3:
        switch (pin)
        {
        case 0:
            P3_0 = value;
            break;
        case 1:
            P3_1 = value;
            break;
        case 2:
            P3_2 = value;
            break;
        case 3:
            P3_3 = value;
            break;
        case 4:
            P3_4 = value;
            break;
        case 5:
            P3_5 = value;
            break;
        case 6:
            P3_6 = value;
            break;
        case 7:
            P3_7 = value;
            break;
        }
        break;
    }
    return;
}
void DIO_TogglePinValue(u8 port, u8 pin)
{
    switch (port)
    {
    case 0:
        switch (pin)
        {
        case 0:
            P0_0 = !P0_0;
            break;
        case 1:
            P0_1 = !P0_1;
            break;
        case 2:
            P0_2 = !P0_2;
            break;
        case 3:
            P0_3 = !P0_3;
            break;
        case 4:
            P0_4 = !P0_4;
            break;
        case 5:
            P0_5 = !P0_5;
            break;
        case 6:
            P0_6 = !P0_6;
            break;
        case 7:
            P0_7 = !P0_7;
            break;
        }
        break;
    case 1:
        switch (pin)
        {
        case 0:
            P1_0 = !P1_0;
            break;
        case 1:
            P1_1 = !P1_1;
            break;
        case 2:
            P1_2 = !P1_2;
            break;
        case 3:
            P1_3 = !P1_3;
            break;
        case 4:
            P1_4 = !P1_4;
            break;
        case 5:
            P1_5 = !P1_5;
            break;
        case 6:
            P1_6 = !P1_6;
            break;
        case 7:
            P1_7 = !P1_7;
            break;
        }
        break;
    case 2:
        switch (pin)
        {
        case 0:
            P2_0 = !P2_0;
            break;
        case 1:
            P2_1 = !P2_1;
            break;
        case 2:
            P2_2 = !P2_2;
            break;
        case 3:
            P2_3 = !P2_3;
            break;
        case 4:
            P2_4 = !P2_4;
            break;
        case 5:
            P2_5 = !P2_5;
            break;
        case 6:
            P2_6 = !P2_6;
            break;
        case 7:
            P2_7 = !P2_7;
            break;
        }
        break;
    case 3:
        switch (pin)
        {
        case 0:
            P3_0 = !P3_0;
            break;
        case 1:
            P3_1 = !P3_1;
            break;
        case 2:
            P3_2 = !P3_2;
            break;
        case 3:
            P3_3 = !P3_3;
            break;
        case 4:
            P3_4 = !P3_4;
            break;
        case 5:
            P3_5 = !P3_5;
            break;
        case 6:
            P3_6 = !P3_6;
            break;
        case 7:
            P3_7 = !P3_7;
            break;
        }
        break;
    }
    return;
}
bit DIO_GetPinValue(u8 port, u8 pin)
{
    switch (port)
    {
    case 0:
        switch (pin)
        {
        case 0:
            return P0_0;
            break;
        case 1:
            return P0_1;
            break;
        case 2:
            return P0_2;
            break;
        case 3:
            return P0_3;
            break;
        case 4:
            return P0_4;
            break;
        case 5:
            return P0_5;
            break;
        case 6:
            return P0_6;
            break;
        case 7:
            return P0_7;
            break;
        }
        break;
    case 1:
        switch (pin)
        {
        case 0:
            return P1_0;
            break;
        case 1:
            return P1_1;
            break;
        case 2:
            return P1_2;
            break;
        case 3:
            return P1_3;
            break;
        case 4:
            return P1_4;
            break;
        case 5:
            return P1_5;
            break;
        case 6:
            return P1_6;
            break;
        case 7:
            return P1_7;
            break;
        }
        break;
    case 2:
        switch (pin)
        {
        case 0:
            return P2_0;
            break;
        case 1:
            return P2_1;
            break;
        case 2:
            return P2_2;
            break;
        case 3:
            return P2_3;
            break;
        case 4:
            return P2_4;
            break;
        case 5:
            return P2_5;
            break;
        case 6:
            return P2_6;
            break;
        case 7:
            return P2_7;
            break;
        }
        break;
    case 3:
        switch (pin)
        {
        case 0:
            return P3_0;
            break;
        case 1:
            return P3_1;
            break;
        case 2:
            return P3_2;
            break;
        case 3:
            return P3_3;
            break;
        case 4:
            return P3_4;
            break;
        case 5:
            return P3_5;
            break;
        case 6:
            return P3_6;
            break;
        case 7:
            return P3_7;
            break;
        }
        break;
    }
}

void DIO_SetPortDirection(u8 port, u8 direction)
{
    switch (port)
    {
    case 0:
        P0 = direction;
        break;
    case 1:
        P1 = direction;
        break;
    case 2:
        P2 = direction;
        break;
    case 3:
        P3 = direction;
        break;
    }
    return;
}
void DIO_SetPortValue(u8 port, u8 value)
{
    switch (port)
    {
    case 0:
        P0 = value;
        break;
    case 1:
        P1 = value;
        break;
    case 2:
        P2 = value;
        break;
    case 3:
        P3 = value;
        break;
    }
    return;
}
void DIO_TogglePortValue(u8 port)
{
    switch (port)
    {
    case DIO_P0:
        P0 = ~P0;
        break;
    case DIO_P1:
        P1 = ~P1;
        break;
    case DIO_P2:
        P2 = ~P2;
        break;
    case DIO_P3:
        P3 = ~P3;
        break;
    }
    return;
}
u8 DIO_GetPortValue(u8 port)
{
    u8 Val;
    switch (port)
    {
    case DIO_P0:
        Val = P0;
        break;
    case DIO_P1:
        Val = P1;
        break;
    case DIO_P2:
        Val = P2;
        break;
    case DIO_P3:
        Val = P3;
        break;
    }
    return Val;
}
