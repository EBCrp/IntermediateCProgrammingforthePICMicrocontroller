/*
 Set up file for all inputs/outputs, ADC, oscillator and TMR0
 Created by: Ellery Cadel
 Microcontroller: PIC18F4525
 Date: 1/22/2024
 */

void initialize ()
{
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;
    TRISA = 0xFF;
    TRISB = 0;
    TRISC = 0;
    TRISD = 0b11111111;
    TRISE = 0;
    ADCON0 = 0;
    ADCON1 = 0b00001111;
    OSCTUNE = 0;
    OSCCON = 0b01110100;
    T0CON = 0b11000111;
}