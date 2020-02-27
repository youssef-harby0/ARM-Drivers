
#ifndef GPIO_H_
#define GPIO_H_
#include "RegisterMap.h"

typedef enum {MODE_IN = 0x00, MODE_OUT = 0xff, MODE_AF = 0x3} gpio_mode_t;
typedef enum {DIDITAL_EN = 0xff, ANALOG_EN = 0x00 } ENABLE_t;

typedef enum port_t {port_A,  port_B ,port_C, port_D ,port_E,port_F}port_t;
//typedef enum gpio_bus_t {AHB ,APB}gpio_bus_t;
typedef enum drive_t{C2MA = GPIODR2R , C4MA = GPIODR4R  ,C8MA = GPIODR8R, C8MA_SELOW}drive_t;
typedef enum pad_t {NO_THIG ,PULL_UP = GPIOPUR ,PULL_DOWN = GPIOPDR , OPEN_DRAIN = GPIOODR }pad_t;


void GPIOClockSet(port_t port);
void GPIOClockRst(port_t port);
uint8 GPIOClockGet(port_t port);



void GPIODirModSet ( uint32 port, uint8 pins , gpio_mode_t mode);
uint8 GPIOModeGet( uint32 port, uint8 pins);    // GPIO return (0),AF return (1)
uint8 GPIODirGet( uint32 port, uint8 pins); // OUTPUT return (1),INPUT return (0)


void GPIOPadSet(volatile uint32 port, uint8 pins, drive_t reg_I, pad_t pad, ENABLE_t enable_type );
uint8 GPIOPadDriveGet(uint32 port, uint8 pin);
uint8 GPIOPadPullUpGet(uint32 port, uint8 pins);
uint8 GPIOPadOpenDrainGet(uint32 port, uint8 pins);
uint8 GPIOPadPullDownGet(uint32 port, uint8 pins);


uint8 GPIORead(uint32 port, uint8 pins);
void GPIOWrite(uint32 port, uint8 pins, uint8 data);













#endif /* GPIO_H_ */
