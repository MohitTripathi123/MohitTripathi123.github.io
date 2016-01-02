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
DDRA=0xAA;
usart_init();
a= PIN&0x01;
b= PIN&0x02;
while(1)
a=usart_receive();
a=b;
{
if(a==0X00&&b==0X00)
 {
  PORTB=0X00;
 }
  else if(a==0X00&&b==0X02)
 {
  PORTB=0X01;
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
