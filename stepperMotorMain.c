/*
 * File:   stepperMotorMain.c
 * Description: Basic Program for the Stepper Motor
 * Comments: 
 * MCLR connection - included 10K resistor from pin to 5V bar.
 * Needed to change stepper wires to match connections not colors shown in book
 * e.g. pink wire in position #1 (not blue) therefore pink became lead wire
 * similar issue for yellow and orange wires
 *
 * Author: Ellery Cadel
 * Copied from book by H.H. Ward 
 * Configuration: PIC18F4525
 * OSC set to INTI067
 * WDT set to OFF
 * LVP set to OFF
 *
 * Updated: January 30, 2025
 */

#include <conFigInternalOscNoWDTNoLVP.h>
#include <xc.h>
#include <PICSetUp.h>


// Some definitions

#define orange PORTBbits.RB3
#define yellow PORTBbits.RB2
#define pink PORTBbits.RB1
#define blue PORTBbits.RB0

// Global variables

unsigned char n, speed, clkcount;
unsigned int ck;

// Subroutines

void delay (unsigned char t)
{
    while (clkcount < t)
    {
        TMR0 = 0;
        while (TMR0 < 250);
        clkcount ++;
        
        
    }
}

void main ()
{
    initialize ();
    T0CON = 0xC6;
    speed = 50;
    while (1)
    {
        if (PORTAbits.RA0) speed = 75;
        if (PORTAbits.RA1) speed = 40; 
        if (PORTAbits.RA2) speed = 20;
        ck = 0;
        clockwise: while (ck < 400)
        {
            orange = 1;
            yellow = 0;
            pink = 0;
            blue = 1;
            TMR0 = 0;
            while (TMR0 < speed);
            orange = 0;
            yellow = 0;
            pink = 0;
            blue = 1;
            TMR0 = 0;
            while (TMR0 < speed);
            orange = 0;
            yellow = 0;
            pink = 1;
            blue = 1;
            TMR0 = 0;
            while (TMR0 < speed);
            orange = 0;
            yellow = 0;
            pink = 1;
            blue = 0;
            TMR0 = 0;
            while (TMR0 < speed);
            orange = 0;
            yellow = 1;
            pink = 1;
            blue = 0;
            TMR0 = 0;
            while (TMR0 < speed);
            orange = 0;
            yellow = 1;
            pink = 0;
            blue = 0;
            TMR0 = 0;
            while (TMR0 < speed);
            orange = 1;
            yellow = 1;
            pink = 0;
            blue = 0;
            TMR0 = 0;
            while (TMR0 < speed);
            orange = 1;
            yellow = 0;
            pink = 0;
            blue = 0;
            TMR0 = 0;
            while (TMR0 < speed);
            ck ++;
            
            goto clockwise;
        }
        ck = 0;
        anticlockwise: while (ck < 500)
        {
            TMR0 = 0;
            while (TMR0 < speed);
            orange = 1;
            yellow = 0;
            pink = 0;
            blue = 0;
            TMR0 = 0;
            while (TMR0 < speed);
            orange = 1;
            yellow = 1;
            pink = 0;
            blue = 0;
            TMR0 = 0;
            while (TMR0 < speed);
            orange = 0;
            yellow = 1;
            pink = 0;
            blue = 0;
            TMR0 = 0;
            while (TMR0 < speed);
            orange = 0;
            yellow = 1;
            pink = 1;
            blue = 0;
            TMR0 = 0;
            while (TMR0 < speed);
            orange = 0;
            yellow = 0;
            pink = 1;
            blue = 0;
            TMR0 = 0;
            while (TMR0 < speed);
            orange = 0;
            yellow = 0;
            pink = 1;
            blue = 1;
            TMR0 = 0;
            while (TMR0 < speed);
            orange = 0;
            yellow = 0;
            pink = 0;
            blue = 1;
            TMR0 = 0;
            while (TMR0 < speed);
            orange = 1;
            yellow = 0;
            pink = 0; // line missing in book
            blue = 1;
            TMR0 = 0;
            while (TMR0 < speed);
            ck ++;
            goto anticlockwise;
        }
        clkcount = 0;
        delay (16);
    }
}

