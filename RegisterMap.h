#include "Types.h"
#ifndef REGISTERMAP_H_
#define REGISTERMAP_H_
//#define GPIO_HIGH_SPEED_BUS
//AHP BUS
#ifdef GPIO_HIGH_SPEED_BUS
#define portA ((volatile uint32 *)(0x40058000)) //‰’— »ÌﬁÊ· «‰ «Ì Â«—œÊÌ— —ÌÃ” — »⁄„·Â ›Ê· Ì· ⁄‘«‰
#define portB ((volatile uint32 *)(0x40059000))
#define portC ((volatile uint32 *)(0x4005A000))
#define portD ((volatile uint32 *)(0x4005B000))
#define portE ((volatile uint32 *)(0x4005C000))
#define portF ((volatile uint32 *)(0x4005D000))
#endif

//APB BUS
#ifndef GPIO_HIGH_SPEED_BUS
#define portA ((volatile uint32 *)(0x40004000))
#define portB ((volatile uint32 *)(0x40005000))
#define portC ((volatile uint32 *)(0x40006000))
#define portD ((volatile uint32 *)(0x40007000))
#define portE ((volatile uint32 *)(0x40024000))
#define portF ((volatile uint32 *)(0x40025000))
#endif


#define RCGCGPIO ((volatile uint32 *)(0x400FE608))
/*===== OFFESET of GPIO Register Map ====== */

#define GPIODATA 0x000  //GPIO Data read or write
#define GPIODIR 0x400   //GPIO Direction input(0) output(1)
#define GPIOIS 0x404    //GPIO interrupt sense
#define GPIOIBE 0x408 //GPIO interrupt both Edges is allows both edges to cause interrupts need steps P665
#define GPIOIEV 0x40c   //GPIO interrupt event
#define GPIOIM 0x410    //GPIO Interrupt Mask
#define GPIORIS 0x414   //GPIO Raw Interrupt Status
#define GPIOMIS 0x418   //GPIO Masked Interrupt Status
#define GPIOICR 0x41C   //GPIO Interrupt Clear
#define GPIOAFSEL 0x420     //GPIO Alternate Function Select
#define GPIODR2R 0x500  //GPIO 2-mA Drive Select
#define GPIODR4R 0x504  //GPIO 4-mA Drive Select
#define GPIODR8R 0x508  //GPIO 8-mA Drive Select
#define GPIOODR 0x50C   //GPIO Open Drain Select
#define GPIOPUR 0x510        //GPIO Pull-Up Select
#define GPIOPDR 0x514   //GPIO Pull-Down Select
#define GPIOSLR 0x518   //GPIO Slew Rate Control Select
#define GPIODEN 0x51C   //GPIO Digital Enable
#define GPIOLOCK 0x520  //GPIO Lock
#define GPIOCR 0x524 //GPIO Commit
#define GPIOAMSEL 0x528 //GPIO Analog Mode Select
#define GPIOPCTL 0x52C //GPIO Port Control
#define GPIOADCCTL 0x530 //GPIO ADC Control
#define GPIODMACTL 0x534 //GPIO DMA Control


#endif /* REGISTERMAP_H_ */
