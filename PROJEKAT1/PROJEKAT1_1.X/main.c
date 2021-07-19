#include <stdlib.h>
#include <p30F4013.h>
#include <p30fxxxx.h>
#include "tajmeri.h"
#include "adc.h"
#include "glcd.h"
#include "uart.h"

unsigned char const slika_bmp[1024] = {
   0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  3,  6, 12, 12, 28, 
  24, 48, 32, 96,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0, 24, 24, 24, 25, 25, 27, 63, 
 102,102,102, 60, 28, 24, 24, 24, 24, 24, 16, 48, 32, 32, 96, 64, 
  64, 64,192,128,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  1,  1,  3,  3,  6, 12, 12, 24, 16, 48, 32, 
  64,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,128,128,128,128,128,192, 64, 64, 64, 64, 32, 32, 32, 32, 
  32, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2, 
   2,  2,  2,  3,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0, 
   0,  0,128,128,128,128,128,128,192,192, 64, 64, 64, 64, 96, 32, 
  32, 32, 32, 33, 51, 18, 22, 60, 44, 40, 40, 40,104,104,248,152, 
 152,  8,  8,  8,  4,  4,  4,  4,  4,  2,  2,  2,  2,  3,  1,  1, 
   1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
  12,  4,  4,  4,  4,  6,  2,  2,  2,  2,  2,  2,  3,  1,  1,  1, 
   1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1, 
   1,  3,  6,  6, 12, 24, 24, 48, 32, 96,192,192,128,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0, 
   1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  3,  6, 
  12,  8, 24, 48, 48, 96,192,192,128,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   1,  0,  0,  0,  1,  0,  0,  0,  8,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  6,  6, 12, 24, 16, 
  48, 96, 96,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0, 64, 64,192,192,192,192,192, 64, 96, 
  32, 96, 96,192,192,192,192,192, 64, 64,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  1,  1,  3,  2,  6, 12,  8, 24, 48, 32, 96,192, 
 128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
  16, 16, 16, 24, 16, 24, 24, 24, 24, 24,  8,  8,  8,  8,  8,  8, 
   8,  8,  8,  8,  8,  8,  8,  8,  8,  8, 10, 11, 11,  9,  9,  9, 
   5,  5,  5,  5,  7,  7,  6,  4,  4,  4,  4,  4,  4,  4,  4,  4, 
   4,  4,  4,  4,  4,  0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2, 
   2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1,  0,  0,  0,  0,  1, 
   1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 
   0,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 
};

_FOSC(CSW_ON_FSCM_OFF & HS3_PLL4);
//_FOSC(CSW_FSCM_OFF & XT_PLL4);
_FWDT(WDT_OFF);
_FGS(CODE_PROT_OFF);

#define ZATVORI 3
#define NEUTRALNO 2
#define OTVORI 1
#define DRIVE_A PORTCbits.RC13
#define DRIVE_B PORTCbits.RC14

unsigned int X, Y,x_vrednost, y_vrednost;
unsigned int broj,broj1,broj2,temp0,temp1, mq3;
unsigned int pokusaj=0;
unsigned int sifra=0;
unsigned int greska=0;
unsigned int otkljucano=0;
unsigned int put;

unsigned int stoperica,pir;
int stanje=0;
unsigned int sirovi,sirovi1, sirovi2;
unsigned char tempRX;
unsigned int flag=0,flag1=0;


//B6(svetlo),B7(svetlo),B10(pir),B11(PWM),RD9(taster),RA11(bazer),RC13,RC14(LCD)
void initPINS()
{    
    
     TRISCbits.TRISC13=0;//tac
     TRISCbits.TRISC14=0;//tac
    
     ADPCFGbits.PCFG10=1;//pir 
     TRISBbits.TRISB10=1;//pir (ulazni)
     
     ADPCFGbits.PCFG11=1;//servo (digitalni)
     TRISBbits.TRISB11=0;//servo (izlazni)
     
     TRISAbits.TRISA11=0;//bazer
     
     ADPCFGbits.PCFG7=1;//svetla (digitalni)
     TRISBbits.TRISB7=0;//izlazni
     
     ADPCFGbits.PCFG6=1;//svetla (digitalni)
     TRISBbits.TRISB6=0;//izlazni
     
     TRISDbits.TRISD9=1;
     
     
}

void __attribute__((__interrupt__)) _U1RXInterrupt(void) 
{
    IFS0bits.U1RXIF = 0;
    tempRX=U1RXREG;
} 

void Delay(unsigned int N)
{
	unsigned int i;
	for(i=0;i<N;i++);
}

void Touch_Panel (void)
{
// vode horizontalni tranzistori
	DRIVE_A = 1;  
	DRIVE_B = 0;
    
     LATCbits.LATC13=1;
     LATCbits.LATC14=0;

	Delay(500); //cekamo jedno vreme da se odradi AD konverzija
				
	// ocitavamo x	
	x_vrednost = temp0;//temp0 je vrednost koji nam daje AD konvertor na BOTTOM pinu		

	// vode vertikalni tranzistori
     LATCbits.LATC13=0;
     LATCbits.LATC14=1;
	DRIVE_A = 0;  
	DRIVE_B = 1;

	Delay(500); //cekamo jedno vreme da se odradi AD konverzija
	
	// ocitavamo y	
	y_vrednost = temp1;// temp1 je vrednost koji nam daje AD konvertor na LEFT pinu	

    X=(x_vrednost-239)*0.03828;
	Y= (y_vrednost-327)*0.020069;

}

void __attribute__((__interrupt__)) _ADCInterrupt(void) 
{
	sirovi=ADCBUF2;	//mq3		
    sirovi1=ADCBUF0; //tac
    sirovi2=ADCBUF1; //tac
    
    mq3=sirovi;
    temp0=sirovi1;
    temp1=sirovi2;
    
    IFS0bits.ADIF = 0;

}

void Write_GLCD(unsigned int data)
{
    unsigned char temp;

    temp=data/1000;
    Glcd_PutChar(temp+'0');
    data=data-temp*1000;
    temp=data/100;
    Glcd_PutChar(temp+'0');
    data=data-temp*100;
    temp=data/10;
    Glcd_PutChar(temp+'0');
    data=data-temp*10;
    Glcd_PutChar(data+'0');
}

void Delay_ms (int vreme)//funkcija za kasnjenje u milisekundama
	{
		stoperica = 0;
		while(stoperica < vreme);
	}


void __attribute__ ((__interrupt__)) _T2Interrupt(void) // svakih 1ms
{

		TMR2 =0;
    stoperica++;//brojac za funkciju Delay_ms
   
	IFS0bits.T2IF = 0; 
       
}


void motor(int polozaj)
{
    
    if(polozaj==1)
    {
        LATBbits.LATB11=1;
        Delay_ms (10);
        LATBbits.LATB11=0;
        Delay_ms (190);
    }
    
    if(polozaj==2)
    {
        LATBbits.LATB11=1;
        Delay_ms (15);
        LATBbits.LATB11=0;
        Delay_ms (185);   
    }
    
    if(polozaj==3)
    {
        LATBbits.LATB11=1;
        Delay_ms (20);
        LATBbits.LATB11=0;
        Delay_ms (180); 
    }
    
}
 
void rst_system()
{
    pokusaj=0;
    sifra=0;
    tempRX=0;
    GLCD_ClrScr();
}

int alarm()
{
    while(1)
    {
        LATAbits.LATA11=1;
        Delay_ms(40);
        LATAbits.LATA11=0;
        Delay_ms(5);
        
        if(tempRX=='e')
        {
            greska=0;
            rst_system();
            return 0;
        }
    }
}

void main (void)
{
    ConfigureLCDPins();
    initPINS();
    confADCPINS();
    
    GLCD_LcdInit();
	GLCD_ClrScr();
    
    initUART1();
    
    ADCinit();
    ADCON1bits.ADON=1;
    
    Init_T2();

    
    
    while(1)
    {
        if(flag1==0)
        {
            if(PORTBbits.RB10==1)
                flag1=1;
        }
       
        if(PORTDbits.RD9==1)
        {
            LATBbits.LATB7=0;
            LATBbits.LATB6=0;
            rst_system();
            motor(NEUTRALNO);
            RS232_putst("UNESI PIN");
            flag=1;
        }
        
        if(flag==1 && flag1==1)
        {
        Touch_Panel ();
        
        GoToXY(13,1);
        GLCD_Printf ("A");
        GLCD_Rectangle(1,1,29,20);
        GoToXY(45,1);
        GLCD_Printf ("B");
        GLCD_Rectangle(32,1,62,20);
        GoToXY(78,1);
        GLCD_Printf ("C");
        GLCD_Rectangle(65,1,95,20);
        GoToXY(111,1);
        GLCD_Printf ("D");
        GLCD_Rectangle(98,1,127,20);
        GoToXY(13,3);
        GLCD_Printf ("1");
        GLCD_Rectangle(1,21,29,40);
        GoToXY(45,3);
        GLCD_Printf ("2");
        GLCD_Rectangle(32,21,62,40);
        GoToXY(78,3);
        GLCD_Printf ("3");
        GLCD_Rectangle(65,21,95,40);
        GoToXY(111,3);
        GLCD_Printf ("4");
        GLCD_Rectangle(98,21,127,40);
        
        if ((1<=X)&&(X<=29)&& (43<=Y)&&(Y<=62))
        {
            if(sifra==0)
            {
                sifra++;
            }
            else
            {    
                sifra=0;
            }
            
            pokusaj++;
        }
    if ((32<=X)&&(X<=62)&& (43<=Y)&&(Y<=62))
    {
            if(sifra==1)
            {
                sifra++;
            }
            else
            {
                sifra=0;
            }
        pokusaj++;
    }
        
    if ((65<=X)&&(X<=95)&& (43<=Y)&&(Y<=62))
    {
        if(sifra==2)
            sifra++;
        else
        {
            sifra=0;
        }
        pokusaj++;
    }
        
    if ((98<=X)&&(X<=127)&& (43<=Y)&&(Y<=62))
    {
        if(sifra==3)
            sifra++;
        else
        {
            sifra=0;
        }
        pokusaj++;
    }
        
    if ((1<=X)&&(X<=29)&& (20<=Y)&&(Y<=40))
    {
        sifra=0;
        pokusaj++;
    }
        
    if ((32<=X)&&(X<=64)&& (20<=Y)&&(Y<=40))
    {
        sifra=0;
        pokusaj++;
    }
    
    if ((65<=X)&&(X<=95)&& (20<=Y)&&(Y<=40))
    {
        sifra=0;
        pokusaj++;
    }
    
    if ((98<=X)&&(X<=127)&& (20<=Y)&&(Y<=40))
    {
        sifra=0;
        pokusaj++;
    }    
           
        
     switch (pokusaj)
     {
        case 0: GoToXY(43,6); GLCD_Printf ("PIN:"); break;
        case 1: GoToXY(43,6); GLCD_Printf ("PIN:*"); break;
        case 2: GoToXY(43,6); GLCD_Printf ("PIN:**"); break;
        case 3: GoToXY(43,6); GLCD_Printf ("PIN:***"); break;
        case 4: GoToXY(43,6); GLCD_Printf ("PIN:****"); break;
     }   
     
     if(pokusaj==4)
     {
         if(sifra==4)
         {
             flag1=0;
             flag=0;
             rst_system();
             if(mq3>0 && mq3<1500)
             {
                  motor(OTVORI);
                  RS232_putst("OTKLJUCANO");
                  RS232_putst("UCITANA LOKACIJA");
                  LATBbits.LATB7=1;
                  LATBbits.LATB6=1;
                  greska=0;
                  GLCD_DisplayPicture(slika_bmp);
             }
             else
             {
                  motor(ZATVORI);
                  LATBbits.LATB7=0;
                  LATBbits.LATB6=0;
                  RS232_putst("PREKOMERNA KOLICINA ALKOHOLA");
                  GoToXY(40,3);
                  GLCD_Printf("PIJAN SI");
                  GoToXY(40,5);
                  GLCD_Printf("NAPOLJE");
                  alarm();
                  greska=0;
             }
         }
         else
         {   
             greska++;
             RS232_putst("POGRESNA SIFRA");
             rst_system();
         }
     }
       
     if(greska==3)
     {
         LATBbits.LATB7=0;
         LATBbits.LATB6=0;
         flag1=0;
         flag=0;
         motor(ZATVORI);
         RS232_putst("PROVALA");
         GoToXY(15,3);
         GLCD_Printf("MOTOR JE BLOKIRAN");
         alarm();
     }
      
        }
    }
}