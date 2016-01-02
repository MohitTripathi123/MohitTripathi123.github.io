#include<avr/io.h>
#include<util/delay.h>

int main()
{
DDRA=0X80;
DDRB=0Xff;
while(1)
{
int a,b,c;
a=PINA&0X01;
b=PINA&0X02;
c=PINA&0x04;

if(a==0X00&&b==0X00&&c==0X00)
 {
  PORTB=0X05;
 }
else if(a==0X01&&b==0X00&&c==0X00)
 {
  PORTB=0X06;
 }
else if(a==0X01&&b==0X02&&c==0X00)
 {
 PORTB=0X09;
 }
else if(a==0X01&&b==0X02&&c==0X04)
 {
  PORTB=0X0A;
 }
else if(a==0X00&&b==0X02&&c==0X00) 
 {
  PORTB=0X06;
 }
else if(a==0X00&&b==0X02&&c==0X04)
 {
 PORTB=0X09;
 }
else if(a==0X00&&b==0X00&&c==0X04)
 {
 PORTB=0X09;
 } 
else if(a==0X01&&b==0X00&&c==0X04)
 {
 PORTB=0X05;
 }
}
return 0;
}
