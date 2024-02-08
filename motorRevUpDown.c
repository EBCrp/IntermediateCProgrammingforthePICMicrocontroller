/*
 * File: motorRevUpDown
 * Revving up the motor to full speed and back down again in endless loop
 * My program to build on information presented in books
 * Author: Ellery Cadel
 * 
 *
 * Created on February 8, 2024
 */


#include <xc.h>
#include <conFigInternalOscNoWDTNoLVP.h>
#include <PICSetup.h>
#define _XTAL_FREQ (8000000)

int i = 0;


void main() 
{
    initialize ();
    T2CON = 0x06;
    PR2 = 249;
    CCP1CON = 0b00001100;
    CCPR1L = 0x7D;
    for (i=60;i<255;i=i+20)
    {
       CCPR1L = i;
       __delay_ms(1000);
    }
    __delay_ms(10000);
    
    for (i=255; i >60; i = i-20)
    {
        CCPR1L = i;
        __delay_ms(1000);
    }
}
