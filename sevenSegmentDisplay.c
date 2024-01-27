/*
 * A program to control a seven segment display
 * File:   sevenSegmentDisplay.c
 * Author: Ellery Cadel
 * Microcontroller: PIC19F4525
 * Created on January 23, 2024, 9:43 AM
 */
#include <conFigInternalOscNoWDTNoLVP.h>
#include <xc.h>
#include <PICSetUp.h>

// declare any global variables

#define _XTAL_FREQ (8000000)
#define zero 0b01111111
#define one 0b00000110
#define two 0b01011011
#define three 0b01001111
#define four 0b01100110
#define five 0b01101101
#define six 0b01111100
#define seven 0b00000111
#define eight 0b01111111
#define nine 0b01100111
#define startButton PORTAbits.RA0
#define stopButton PORTAbits.RA1

void main ()
{
    initialize ();
    start: while (! startButton);
    while (1)
    {
        if (stopButton) goto start;
        PORTB = zero;
        __delay_ms(2000);
        PORTB = one;
        __delay_ms(2000);
        PORTB = two;
        __delay_ms(2000);
        PORTB = three;
        __delay_ms(2000);
        PORTB = four;
        __delay_ms(2000);
        PORTB = five;
        __delay_ms(2000);
        PORTB = six;
        __delay_ms(2000);
        PORTB = seven;
        __delay_ms(2000);
        PORTB = eight;
        __delay_ms(2000);
        PORTB = nine;
        __delay_ms(2000);
    }
}


