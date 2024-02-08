/*
 * File: 75_25SquareWave500Hz.c
 * Creating 75/25 Square Wave at 500Hz
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
    CCPR1L = 0xBB;
    while (1);
}
