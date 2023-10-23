/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DEL_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Auther: Repo Collabs
Layer : MCAL.
SWC   : DELAY.
*/

#include "STD_TYPES.h"
// #include "BIT_MATH.h"

#include "DEL_interface.h"
// #include "DEL_private.h"
// #include "DEL_config.h"

void delay_ms(u32 msec)
{
	u32 i;
	u8 j;
	for (i = 0; i < msec; i++)
	{
		for (j = 0; j < 113; j++)
		{
		}
	}
}
