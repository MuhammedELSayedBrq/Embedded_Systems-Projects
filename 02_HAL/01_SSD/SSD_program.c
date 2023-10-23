/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SSD_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * Author : Repo Collabs
 * Layer  : HAL.
 * SWC    : 7_Segment.
 */

 #include "STD_TYPES.h"
 //#include "BIT_MATH.h"
 #include "DIO_interface.h"


 #include "SSD_interface.h"
 //#include "SSD_private.h"
 //#include "SSD_config.h"

void SSD_init(SSD_type segment){
    DIO_SetPortDirection(segment.Data_Port, DIO_PORT_OUTPUT);
    DIO_SetPinDirection(segment.Enable_Port,segment.Enable_Pin, DIO_PIN_OUTPUT);
	return;
}
void SSD_enable(SSD_type segment){
    if(segment.Type == SSD_COMM_ANODE){
        DIO_SetPinValue(segment.Enable_Port,segment.Enable_Pin, DIO_PIN_HIGH);
    }else if(segment.Type == SSD_COMM_CATHODE){
        DIO_SetPinValue(segment.Enable_Port,segment.Enable_Pin, DIO_PIN_LOW);
    }
	return;
}
void SSD_disable(SSD_type segment){
    if(segment.Type == SSD_COMM_CATHODE){
        DIO_SetPinValue(segment.Enable_Port,segment.Enable_Pin, DIO_PIN_HIGH);
    }else if(segment.Type == SSD_COMM_ANODE){
        DIO_SetPinValue(segment.Enable_Port,segment.Enable_Pin, DIO_PIN_LOW);
    }
	return;
}
void SSD_SendData(SSD_type segment, u8 element){
    u8 Data_Arr[SSD_ELEMENTS_NUM] = SSD_COMM_ANODE_TRUTH_TABLE;
    if(segment.Type == SSD_COMM_ANODE)DIO_SetPortValue(segment.Data_Port, Data_Arr[element]);
    else if(segment.Type == SSD_COMM_CATHODE)DIO_SetPortValue(segment.Data_Port, ~(Data_Arr[element]));
	return;
}
