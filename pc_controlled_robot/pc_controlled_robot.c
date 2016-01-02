#define F_CPU 1000000
#include<avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>
#define  baud_rate 1200
#define prescale ((F_CPU/(16*baud_rate))-1)



#define rs PB0
#define rw PB1
#define en PB2

void usart_transmit(unsigned char data);
unsigned char usart_receive(void);
void usart_init(void);
void lcd_init(void);
void lcd_cmd(int);
void dis_cmd(int);
void dis_data(int);
void lcd_data(int);
void string_lcd(unsigned char *str);
void lcd_number(int abc);


ISR(INT0_vect)
{
	dis_cmd(0x01);
	_delay_ms(1);
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

void lcd_init(void)
{
dis_cmd(0x02);
dis_cmd(0x28);
dis_cmd(0x0e);
dis_cmd(0x06);
dis_cmd(0x80);
}
void lcd_data(int x)
{
PORTB=x;
PORTB |=(1<<rs);
PORTB &=~(1<<rw);
PORTB |=(1<<en);
_delay_ms(1);
PORTB &=~(1<<en);
} 
void dis_data(int x)
{
int x1;
x1=x & 0xf0;
lcd_data(x1);
x1=(x<<4)&0xf0;
lcd_data(x1);
}
void lcd_cmd(int x)
{
PORTB =x;
PORTB &=~(1<<rs);
PORTB &=~(1<<rw);
PORTB |=(1<<en);
_delay_ms(1);
PORTB &=~(1<<en);
}
void dis_cmd(int x)
{
int x1;
x1=x & 0xf0;
lcd_cmd(x1);
x1=(x<<4)&0xf0;
lcd_cmd(x1);
}

void string_lcd(unsigned char *str )
{
int i;
for(i=0;str[i]!=0x0d; i++)
{
dis_data(str[i]);
}
}

void lcd_number(int abc )
{
dis_cmd(0x04);
unsigned int d=0;
while(abc!=0)
{
d=abc%10;
dis_data(d+48);
abc=abc/10;
}
}

int main()
{
DDRB=0XFF;
DDRD=0X00;
usart_init();
lcd_init();
unsigned char a;
unsigned char *str;
PORTD=0X04;
GICR=0B01000000;
sei();
int i=0;
while(1)
{	do
	{	
		a=usart_receive();
		_delay_ms(50);
		str[i++]=a;
	}while(a!=0x0d);
	dis_cmd(0x80);
	string_lcd(str);
}
}



