#include<p30fxxxx.h>
#include "adc.h"


//B12(MQ3,POTENCIOMETAR),B8,B9(TAC);
void confADCPINS(void)
{
     ADPCFGbits.PCFG12=0;//mq3_potenciometar
     TRISBbits.TRISB12=1;//mq3_potenciometar (ulazni)
    
     ADPCFGbits.PCFG8=0;//tac
     TRISBbits.TRISB8=1;
     ADPCFGbits.PCFG9=0;
     TRISBbits.TRISB9=1;   
}


void ADCinit(void)
{

ADCON1bits.ADSIDL=0;
ADCON1bits.FORM=0;
ADCON1bits.SSRC=7;
ADCON1bits.SAMP=1;

ADCON2bits.VCFG=7;
ADCON2bits.CSCNA=1;
ADCON2bits.SMPI=2; //broj konvertora-1 
ADCON2bits.BUFM=0;
ADCON2bits.ALTS=0;

ADCON3bits.SAMC=31;
ADCON3bits.ADRC=1;
ADCON3bits.ADCS=31;


ADCHSbits.CH0NB=0;
ADCHSbits.CH0NA=0;

ADCHSbits.CH0SA=0;
ADCHSbits.CH0SB=0;


  ADCSSL=0b0001001100000000; //RB12, RB8, RB9
ADCON1bits.ASAM=1;

IFS0bits.ADIF=1;
IEC0bits.ADIE=1;


}

