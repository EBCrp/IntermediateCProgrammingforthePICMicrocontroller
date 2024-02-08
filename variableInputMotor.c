/*
 * File: variableInputMotor
 * Varying the input voltage to change the speed of the DC motor
 * Author: Ellery Cadel
 * Copied from Book by H.H. Ward
 *
 * Created on February 8, 2024
 */


#include <xc.h>
#include <conFigInternalOscNoWDTNoLVP.h>
#include <PICSetup.h>
#include <math.h>

void changeSpeed ()
{
    ADCON0bits.GODONE = 1;
    while (ADCON0bits.GODONE);
    CCPR1L = round (ADRESH * 0.95);
}

void main ()
{
    initialize ();
    TRISA = 0x0F;
    ADCON0 = 0x01;
    ADCON1 = 0x0E;
    ADCON2 = 0b00010001;
    T2CON = 0x05;
    PR2 = 249;
    CCP1CON = 0b00001100;
    CCPR1L = 0x7D;
    while (1)
    {
        changeSpeed ();
    }
}
