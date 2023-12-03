#include "LIB\STD_TYPES.h"
#include "LIB\BIT_MATH.h"
#include "MCAL\DIO_INT.h"
#include "MCAL\DIO_REG.h"


/* IO Pins */
void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy)
{
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((u8PortIdCopy <= PORT3) && (u8PinIdCopy <= PIN7))
	{
		if ( u8PinDirCopy == INPUT )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORT0: SET_BIT(PORT0_Register,u8PinIdCopy); break;
				case PORT1: SET_BIT(PORT1_Register,u8PinIdCopy); break;
				case PORT2: SET_BIT(PORT2_Register,u8PinIdCopy); break;
				case PORT3: SET_BIT(PORT3_Register,u8PinIdCopy); break;
			}
		}

		else if ( u8PinDirCopy == OUTPUT )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORT0: CLR_BIT(PORT0_Register,u8PinIdCopy); break;
				case PORT1: CLR_BIT(PORT1_Register,u8PinIdCopy); break;
				case PORT2: CLR_BIT(PORT2_Register,u8PinIdCopy); break;
				case PORT3: CLR_BIT(PORT3_Register,u8PinIdCopy); break;
			}
		}

		else
		{
			/* Do nothing, Wrong Direction Required */
		}
	}

	else
	{
		/* Do nothing, Error in the Pin ID or PORT ID */
	}
}

void DIO_SetPortDirection (u8 u8PortIdCopy, u8 u8PortDirCopy)
{
	/* Make sure that the Port ID and Pin ID are in the valid range */
		if ( u8PortDirCopy == INPUT )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORT0: PORT0_Register = 0xff ; break;
				case PORT1: PORT1_Register = 0xff ; break;
				case PORT2: PORT2_Register = 0xff ; break;
				case PORT3: PORT3_Register = 0xff ; break;
			}
		}

		else if ( u8PortDirCopy == OUTPUT )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORT0: PORT0_Register = 0x00 ; break;
				case PORT1: PORT1_Register = 0x00 ; break;
				case PORT2: PORT2_Register = 0x00 ; break;
				case PORT3: PORT3_Register = 0x00 ; break;
			}
		}

	else
	{
		/* Do nothing, Error in  PORT ID */
	}
}

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy)
{
	/* Define Local Variable to get the BIT Value */
	u8 u8ResultLocal;
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((u8PortIdCopy <= PORT3) && (u8PinIdCopy <= PIN7))
	{
		/* Check on the Required PORT Number */
		switch (u8PortIdCopy)
		{
			case PORT0: u8ResultLocal= GET_BIT(PORT0_Register,u8PinIdCopy); break;
			case PORT1: u8ResultLocal= GET_BIT(PORT1_Register,u8PinIdCopy); break;
			case PORT2: u8ResultLocal= GET_BIT(PORT2_Register,u8PinIdCopy); break;
			case PORT3: u8ResultLocal= GET_BIT(PORT3_Register,u8PinIdCopy); break;
		}
	}
	else
	{
		/* return 0xff in case of error in the Pin ID or PORT ID */
		u8ResultLocal = 0xFF;
	}
	return u8ResultLocal;
}
void DIO_SetPortValue(u8 u8PortIdCopy,  u8 A_u8PortVal)
{
	if(u8PortIdCopy <= PORT3)
	{
		switch(u8PortIdCopy)
		{
			case PORT0:
				PORT0_Register= A_u8PortVal; break;
			case PORT1:
				PORT1_Register= A_u8PortVal; break;
			case PORT2:
				PORT2_Register= A_u8PortVal; break;
			case PORT3:
				PORT3_Register= A_u8PortVal; break;
		}
	}
}
