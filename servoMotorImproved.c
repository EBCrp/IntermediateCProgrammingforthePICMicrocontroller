/*
 * File:   servoMotorImproved.c
 * Description: A Program to control a servo motor - improved process
 * The 50Hz pulse train created with TMR0 16-bit
 * Author: Ellery Cadel
 * Copied from book by H.H. Ward 
 * Configuration: PIC18F4525
 * 
 * Created on February 13, 2024
 */

#include <xc.h>
#include <math.h>
#include <conFigInternalOscNoWDTNoLVP.h>

#define servoOut PORTBbits.RB0

// variables

unsigned int rotate;

// subroutines

void changeAngle ()
{
    ADCON0bits.GODONE = 1;
    while (ADCON0bits.GODONE);
    rotate = 1000 + (round (((ADRESH << 2) + (ADRESL >> 6)) * 0.95));
    if (rotate > 1999) rotate = 1999;
}

void main ()
{
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    TRISA = 0xFF;
    TRISB = 0;
    TRISC = 0;
    TRISD = 0;
    ADCON0 = 0x01;
    ADCON1 = 0x0E;
    ADCON2 = 0b00100001;
    OSCTUNE = 0;
    OSCCON = 0b01110100;
    T0CON = 0b10000000;
    rotate = 1000;
    while (1)
    {
        begin: TMR0 = 0;
        servoOut = 1;
        while (TMR0 < 2000) if (TMR0 >= rotate)servoOut = 0;
        while (TMR0 < 18500) changeAngle ();
        while (TMR0 < 20000);
        goto begin;
    }
}