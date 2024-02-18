/*
 * File:   threeInterruptSources.c
 * This is a simple program to investigate interrupts
 * It uses three interrupt sources which are
 * INT0 and INT2 two external interrupts
 * TMR2 match interrupt an internal peripheral interrupt
 * INT0 and INT2 will effect the display on PORTC
 * The TMR2 match will effect bit0 on PORTD
 * The program is written for the PIC18F4325
 * Written and updated by Ellery Cadel 
 * Date: 2/18/2024
 * Original from book by H.H. Ward
 */

#include <xc.h>
#include <PICSetUp.h> //created earlier and should be loaded in xc-8 directory for correct software version
#include <conFigInternalOscNoWDTNoLVP.h>  //created earlier and should be loaded in xc-8 directory for correct software version


void __interrupt () ISR (void)  //changed to updated function
{
    if (INTCONbits.INT0IF == 1)
    {
        INTCONbits.INT0IF = 0;
        PORTC = 0x0F;
    }
    else if (INTCON3bits.INT2IF == 1)
    {
        INTCON3bits.INT2IF = 0;
        PORTC = 0x2C;
    }
    else if (PIR1bits.TMR2IF == 1)
    {
        PIR1bits.TMR2IF = 0;
        if (PORTDbits.RD0 == 0) PORTDbits.RD0 = 1;
        else PORTDbits.RD0 = 0;
    }
}

main ()
{
    initialize ();
    TRISBbits.RB0 = 1;
    TRISBbits.RB2 = 1;
    TRISBbits.RB4 = 1;
    TRISBbits.RB5 = 1;
    TRISD = 0;
    INTCON = 0b11010000;
    INTCON2 = 0b00000000;
    INTCON3 = 0b00010000;
    PIE1 = 0b00000010;
    RCONbits.IPEN = 0;
    OSCCON = 0b00010100;
    T2CON = 0b00000111;
    PR2 = 250;
    PORTC = 0;
    while (1)
    {
        if (PORTBbits.RB4 == 1) PORTC = 0;
        else if (PORTBbits.RB5 == 1) PORTC = 6;
    }
}