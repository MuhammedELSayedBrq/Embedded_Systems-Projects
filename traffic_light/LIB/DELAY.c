#include "LIB/STD_TYPES.h"
#include "LIB/DELAY_INT.h"
void Delay_ms(u32 msec)
{
	int i,j;
	for(i=0; i<msec; i++){
		for(j=0; j<260;j++){}
	}
}/*end of LDelay_voidDelay_ms()*/