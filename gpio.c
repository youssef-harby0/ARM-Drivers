#include "gpio.h"
//111111111111111111111111111111
void GPIODirModSet ( uint32 port , uint8 pins , gpio_mode_t mode)
{
volatile uint32 *REG =0;
         REG = ((uint32*)(port + GPIODIR));
         uint8 reg_data= *REG;

if (mode == MODE_IN || MODE_OUT ){
        reg_data = ~(pins ^ mode);
        *REG =   (mode == MODE_OUT) ?  *REG | reg_data :  *REG & reg_data;
}
//else (mode == MODE_AF)
else{
     REG = (uint32*)(port + GPIOAFSEL);
    *REG |= pins;
}
}
//222222222222
uint8 GPIOModeGet( uint32 port, uint8 pins)
{

    volatile uint32 *REG = ( uint32*)(port + GPIOAFSEL);
    uint8 data = *REG;
    data &= pins;
    return data;
}
//222222222222
uint8 GPIODirGet( uint32 port, uint8 pins){
 volatile uint32 *REG = 0;
 REG = (port + GPIODIR);
 uint8 data = *REG;
 data &= pins;
 return data;
}

void GPIOClockSet(port_t port){
    volatile uint32 *REG = 0;
    REG = RCGCGPIO;
    uint8 reg_data= *REG;
    reg_data |=(1 << port);
    *REG= reg_data;
}


uint8 GPIOClockGet(port_t port){
    volatile uint32 *REG = 0;
    REG = RCGCGPIO;
    uint8 reg_data = *REG;
    reg_data =(reg_data >> port);
    return reg_data;
}
void GPIOClockRst(port_t port){
    volatile uint32 *REG = 0;
    REG = RCGCGPIO;
    *REG &=~(1 << port);
}

void GPIOPadSet(uint32 port, uint8 pins, drive_t reg_I, pad_t pad, ENABLE_t enable_type){
    volatile uint32 *REG = 0 ;

    REG =(uint32*)(port + reg_I);
    *REG |= pins;

    REG =(uint32*)( port + pad);
    *REG = (pad == NO_THIG)? *REG|0x00 :  *REG | pins;

   // *REG |= pins;

    REG = (uint32*)(port + GPIODEN);
    pins &=enable_type;
    *REG |= pins;
}


uint8 GPIOPadDriveGet(uint32 port, uint8 pin){  //if pins ???????????
   volatile uint32 *REG =  0;
   REG = (volatile uint32*) (port +0x500);
   uint8 reg_data =  *REG;
   uint8 j =  2;
   volatile uint32 i = port+0x500;
for(i ; i <= (port+0x508); i+=0x04)
{

    REG = i;
    reg_data =  *REG;
    if (reg_data & (1 << pin)){break;}

    j*=2;
}
return j;
}

uint8 GPIOPadPullUpGet(uint32 port, uint8 pins){
    volatile uint32 *REG = (uint32*) (port + GPIOPUR) ;
    uint8 reg_data = *REG;
    return reg_data &= pins;
}
uint8 GPIOPadOpenDrainGet(uint32 port, uint8 pins){
    volatile uint32 *REG = (uint32*)(port + GPIOODR) ;
      uint8 reg_data = *REG;
      return reg_data &= pins;
}

uint8 GPIOPadPullDownGet(uint32 port, uint8 pins){
    volatile uint32 *REG =(uint32*)( port + GPIOPDR) ;
      uint8 reg_data = *REG;
      return reg_data &= pins;
}


/*void GPIOWrite(uint32 port, uint8 pins, uint8 data){
    volatile uint32 *REG_data = (uint32*)(port + GPIODATA );

    *REG_data |= ((pins & data)<<2); // to write one's
    *REG_data &=  ((~pins) | (pins & data)<<2); // to write zeros's

}*/

void GPIOWrite(uint32 port, uint8 pins, uint8 data){
    volatile uint32 *REG_data = (uint32*)(port + GPIODATA + ((uint16)pins << 2));
    *REG_data = data;
}

uint8 GPIORead(uint32 port, uint8 pins)
{
    volatile uint32 *REG_data = (uint32*)(port + GPIODATA + ((uint16)pins << 2));
    uint8 reg_data = *REG_data;
    return reg_data;
}
