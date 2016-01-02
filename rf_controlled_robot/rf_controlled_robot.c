#define F_CPU 1000000
#define  baud_rate 1200
#define prescale ((F_CPU/(16*baud_rate))-1)
#include<avr/io.h>
#include<util/delay.h>
void usart_transmit(unsigned char data);
unsigned char usart_receive(void);
void usart_init();


int main()
{
DDRB=0XFF;
usart_init();
int b;
while(1)
{

b=usart_receive();
if(b=='A')
{PORTB=0B00001010;
}
if(b=='B')
{
PORTB=0B00000101;

}


if(b=='C')
{PORTB=0B00001001;
}
if(b=='D')
{
PORTB=0B00000110;

}

}
return 0;
}
 void usart_init()
{

UCSRB=0B00011000;
UCSRC=0B10100110;
UBRRL=prescale;
UBRRH=(prescale>>8);
}

void usart_transmit(unsigned char data)
{
while(!(UCSRA&(1<<UDRE)));

UDR=data;
}

unsigned char usart_receive(void)
{
while(!(UCSRA&(1<<RXC)));
return UDR;
}
