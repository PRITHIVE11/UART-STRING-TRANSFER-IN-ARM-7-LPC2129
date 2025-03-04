#include<lpc21xx.h>
void UART0_CONFIG(void);
void UART0_TX(unsigned char);
unsigned char UART0_RX(void);
void UART0_STR(unsigned char *);


void UART0_CONFIG()
{
	PINSEL0|=0x00000005;//P0.0 as TXD0 and P0.1 as RXD0
	U0LCR=0x83;//DLAB is 1 and 8N1 selected
	U0DLL=97;//To set the baudrate
	U0LCR=0x03;//DLAB is clear and to access U0THR and U0RBR 
	
}

void UART0_TX(unsigned char d)
{
	while((U0LSR&(1<<5))==0);
	U0THR=d;
	
}
unsigned char UART0_RX(void)
{
	while((U0LSR&(1<<0))==0);
	return U0RBR;
	
}

void UART0_STR(unsigned char *s)
{
	while(*s)
	{
		UART0_TX(*s++);
	}
	
}
