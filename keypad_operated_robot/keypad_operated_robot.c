#include<avr/io.h>
#include<util/delay.h>
int main()
{
DDRB=0Xff;
DDRC=0Xff;
PORTA=0xff;
while(1)
{
if(PINA==0b11111110)
{
 PORTC=0X06;
}
if(PINA==0b11111101)
{
 PORTC=0X09;
}
if(PINA==0b11111011)
{
 PORTC=0X08;
}
if(PINA==0b11110111)
{
 PORTC=0X02;
}
}
return 0;
}
