/*
 * File:   twoSquareWave500Hz.c
 * Creating two Square Waves at 500Hz
 * Author: Ellery Cadel
 * Copied from Book by H.H. Ward
 *
 * Created on January 29, 2024
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
    CCP2CON = 0b00001100;
    CCPR2L = 0x7D;
    while (1);
}
