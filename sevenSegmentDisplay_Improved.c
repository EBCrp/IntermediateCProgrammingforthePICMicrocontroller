/*
 * A program to control a seven segment display
 * File:   sevenSegmentDisplay_Improved.c
 * Description: Changed to use array and pointer
 * HHWard, Book2 - Intermediate C Programming for the PIC Microcontroller
 * Author: Ellery Cadel
 * Microcontroller: PIC19F4525
 * Created on January 24, 2024
 */
#include <conFigInternalOscNoWDTNoLVP.h>
#include <xc.h>
#include <PICSetUp.h>

// declare any global variables

unsigned char m;

// declare any definitions

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
unsigned char sevenDisplay [10] =
{
    zero,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
};
unsigned char *displayPointer;

void main ()
{
    initialize ();
    start: while (! startButton);
    while (1)
    {
        displayPointer = sevenDisplay;
        for (m = 0; m < 10; m ++)
        {
            if (stopButton) goto start;
            PORTB = *displayPointer;
            displayPointer ++;
            __delay_ms(2000);
        }
    }
}


