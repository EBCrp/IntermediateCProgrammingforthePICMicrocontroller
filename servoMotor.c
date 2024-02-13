/*
 * File:   servoMotor.c
 * Description: Controlling the Positions of the Servo Motor with a Variable Resistor
 * Author: Ellery Cadel
 * Copied from book by H.H. Ward 
 * Configuration: PIC18F4525
 * 
 *
 * Created on February 12, 2024
 */

#include <conFigInternalOscNoWDTNoLVP.h>
#include <xc.h>
#include <math.h>

// some variables

unsigned char n, button;

// some subroutines

void changeAngle ()
{
    ADCON0bits.GODONE = 1;
    while (ADCON0bits.GODONE);
    CCPR1L = (7 + round (ADRESH * 0.0314));
}

void main ()
{
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    TRISA = 0xFF;
    TRISB = 0;
    TRISC = 0;
    ADCON0 = 0x01;
    ADCON1 = 0x0E;
    ADCON2 = 0b00100000;
    OSCTUNE = 0;
    OSCCON = 0x14;
    T0CON = 0xC1;
    T2CON = 0x05;
    PR2 = 156;
    CCP1CON = 0b00111100;
    CCPR1L = 0x0E;
    while (1)
    {
        changeAngle ();
    }
}