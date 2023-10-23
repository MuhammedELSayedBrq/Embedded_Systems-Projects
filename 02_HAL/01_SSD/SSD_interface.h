/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SSD_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * Author : Repo Collabs
 * Layer  : HAL.
 * SWC    : 7_Segment.
 */

#ifndef SSD_interface_H_
#define SSD_interface_H_

#define SSD_COMM_ANODE 1
#define SSD_COMM_CATHODE 0

#define SSD_P0 0
#define SSD_P1 1
#define SSD_P2 2
#define SSD_P3 3

#define SSD_PIN0 0
#define SSD_PIN1 1
#define SSD_PIN2 2
#define SSD_PIN3 3
#define SSD_PIN4 4
#define SSD_PIN5 5
#define SSD_PIN6 6
#define SSD_PIN7 7

#define SSD_ELEMENTS_NUM 10
#define SSD_COMM_ANODE_TRUTH_TABLE {0x03, 0x9F, 0x25, 0x0D, 0x99, 0x49, 0x41, 0x1F, 0x01, 0x09}

typedef struct{
    u8 Type;
    u8 Data_Port;
    u8 Enable_Port;
    u8 Enable_Pin;
} SSD_type;

void SSD_init(SSD_type segment);
void SSD_enable(SSD_type segment);
void SSD_disable(SSD_type segment);
void SSD_SendData(SSD_type segment, u8 element);

#endif // SSD_interface_H_
