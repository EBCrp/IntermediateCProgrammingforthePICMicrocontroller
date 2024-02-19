/* File:   highLowPriorityInterrupts.c
 * This is a simple program to investigate interrupt high and low priority
 * It uses two external interrupt sources which are
 * INT1 and INT2, two external interrupts
 * INT1 and INT2 will effect the display on PORTB
 * The main program simply makes an led on PORTD flash
 * PIC Microcontroller: PIC18F4525
 * Written and updated by Ellery Cadel 
 * Date: 2/18/2024
 * Original from book by H.H. Ward
 */

// some include files

#include <xc.h>
#include <PICSetUp.h> //created earlier and should be loaded in xc-8 directory for correct software version
#include <conFigInternalOscNoWDTNoLVP.h>  //created earlier and should be loaded in xc-8 directory for correct software version

// some variables

unsigned char n;

// some subroutines

void delay (unsigned char t)
{
    for (n=0; n < t; n++)
    {
        TMR0 = 0;
        while (TMR0 < 255);
    }
}
void __interrupt() INTERRUPT_HighPriority (void) //changed to updated interrupt coding
{
    if (INTCON3bits.INT2IF == 1)
    {
        INTCON3bits.INT2IF = 0;
        PORTC = 0x0F;
        while (!PORTBbits.RB4);
        PORTC = 0;
    }
}

void __interrupt(low_priority) INTERRUPT_LowPriority (void) //changed to updated interrupt coding
{
    INTCON3bits.INT1IF = 0;
    PORTC = 0x2C;
    while (!PORTBbits.RB5);
    PORTC = 8;
}
    

void main ()
{
    initialize ();
    TRISB = 0xFF;
    TRISC = 0;
    TRISD = 0;
    RCON = 0b10000000;
    INTCON = 0b11000000;
    INTCON3 = 0b10011000;
    ADCON1 = 0x0F;
    OSCCON = 0b01110100;
    T0CON = 0b11000111;
    PORTD = 0;
    PORTC = 0x01;
    while (1)
    {
        PORTDbits.RD0 = 1;
        delay (30);
        PORTDbits.RD0 = 0;
        delay (30);
    }
}