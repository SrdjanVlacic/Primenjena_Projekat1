#include <p30fxxxx.h>
#include "tajmeri.h"


#define TMR2_period 333/*  Fosc = 3.3Mhz,
					          1/Fosc = 1/3.3MHZ !!!, 0.3us * X = 100us  */


void Init_T2(void)
{
	TMR2 = 0;
	PR2 = TMR2_period;
	
	T2CONbits.TCS = 0; // 0 = Internal clock (FOSC/4)
	IFS0bits.T2IF = 0; // clear interrupt flag
	IEC0bits.T2IE = 1; // enable interrupt
	T2CONbits.TON = 1; // T2 on 
}

