/*
 * File: 3SpeedMotorProgram
 * Three-Speed Control of DC Motor
 * Author: Ellery Cadel
 * Copied from Book by H.H. Ward
 *
 * Created on February 7, 2024
 */


#include <xc.h>
#include <conFigInternalOscNoWDTNoLVP.h>
#include <PICSetup.h>


void main() 
{
    initialize ();
    T2CON = 0x06;
    PR2 = 249;
    CCP1CON = 0b00001100;
    CCPR1L = 0x7D;
    while (1)
    {
        if (PORTAbits.RA0) CCPR1L = 0xBB;
        if (PORTAbits.RA1) CCPR1L = 0xDB;
        if (PORTAbits.RA2) CCPR1L = 0x3E;
        if (PORTAbits.RA3) CCPR1L = 0x7D;
    }
}
