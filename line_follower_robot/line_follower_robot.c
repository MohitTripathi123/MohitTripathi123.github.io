#include<avr/io.h>
#include<util/delay.h>

int main()
{
DDRA=0X80;
DDRB=0Xff;
while(1)
{
 int a,b;// select a for sensor1 and b for sensor2  
  a=PINA&0X01;// make input pin for sensor 1 at pin 1
  b=PINA&0X02;// make input pin for sensor 2 at pin 2
  if(a==0X00&&b==0X00)// if sesnor 1 and 2 is not getting any input
 {
  PORTB=0X00;//motor stop
 }
  else if(a==0X00&&b==0X02)//if sensor1 is not active and sensor2 is active
 {
  PORTB=0X01;//motor1 move 
 }
 else if(a==0X01&&b==0X00)//if sensor2 is not active and sensor1 is active
 {
  PORTB=0X08;//motor2 move
 }
 else if(a==0X01&&b==0X02) //when both sensor is active
 {
  PORTB=0X09;//both motor move
 } 
}
return 0;
}
