

/**
 * main.c
 */

#include "gpio.h"

int main(void)
{
    GPIOClockSet(port_F);
    GPIODirModSet (portF ,0b11111111 , MODE_OUT);
    GPIOPadSet(portF, 0b11111111, C2MA , NO_THIG , DIDITAL_EN);
    int i=0,j=0,k=0;
int I= GPIOPadDriveGet(portF, 0x01);

    while(1)
    {


        GPIOWrite(portF, 0b00001111, 0b00001110);
        for (i=0 ; i < 1000 ; i++){
            for (j=0 ; j < 2000 ; j++) {}
        }
        GPIOWrite(portF, 0b00001111, 0b00000010);
        for (i=0 ; i < 1000 ; i++){
            for (j=0 ; j < 2000 ; j++) {}
        }
        GPIOWrite(portF, 0b00001111, 0b00000100);
        for (i=0 ; i < 1000 ; i++){
            for (j=0 ; j < 2000 ; j++) {}
        }
    }
	return 0;
}



