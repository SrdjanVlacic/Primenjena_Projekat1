#include "uart.h"

//RF2,RF3(OSNOVNI)
void initUART1(void)
{
    U1BRG=0x0015;//ovim odredjujemo baudrate 

    U1MODEbits.ALTIO=0;//biramo koje pinove koristimo za komunikaciju osnovne ili alternativne(OSNOVNE)

    IEC0bits.U1RXIE=1;//omogucavamo rx1 interupt

    U1STA&=0xfffc;

    U1MODEbits.UARTEN=1;//ukljucujemo ovaj modul

    U1STAbits.UTXEN=1;//ukljucujemo predaju
}

void WriteUART1(unsigned int data)
{
	  while(!U1STAbits.TRMT);

    if(U1MODEbits.PDSEL == 3)
        U1TXREG = data;
    else
        U1TXREG = data & 0xFF;
}

void WriteUART1dec2string(unsigned int data)
{
	unsigned char temp;

	temp=data/1000;
	WriteUART1(temp+'0');
	data=data-temp*1000;
	temp=data/100;
	WriteUART1(temp+'0');
	data=data-temp*100;
	temp=data/10;
	WriteUART1(temp+'0');
	data=data-temp*10;
	WriteUART1(data+'0');
    WriteUART1(13);
}


void RS232_putst(register const char *str){
    while((*str)!=0){
        WriteUART1(*str);
 //       if (*str==13) WriteUART1(10);
 //       if (*str==10) WriteUART1(13);
        str++;
    }
     WriteUART1(13);
}
