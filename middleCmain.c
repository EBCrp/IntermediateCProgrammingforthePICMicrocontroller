/*
 * File: middleCmain
 * Creating the Note Middle C
 * Author: Ellery Cadel
 * Copied from Book by H.H. Ward
 *
 * Created on February 9, 2024
 */


#include <xc.h>
#include <conFigInternalOscNoWDTNoLVP.h>
#include <PICSetup.h>

void main ()
{
    initialize ();
    OSCCON = 0b01010100;
    T2CON = 0x06;
    PR2 = 118;
    CCP1CON = 0b00111100;
    CCPR1L = 0x3B;
    while (1);
}
