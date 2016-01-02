#include<avr/io.h>
#include<util/delay.h>
#define rs PC0
#define rw PC1
#define en PC2
void lcd_init(void);
void lcd_cmd(int);
void dis_cmd(int);
void lcd_data(int);
void dis_data(int);
void string_LCD(char *str);
int key();
void lcd_num(int);

int main()
{
int y,sum1=1235,sum=0;
DDRA=0X00;
DDRD=0XFF;
DDRC=0XFF;
PORTA=0x0f;
lcd_init();
while(1)
{
sum=0;
dis_cmd(0x82);
string_LCD("enter password");

do
{
 y=key();
if(y==8)
break;

else
{
sum=sum*10+y;
dis_cmd(0xc5);
lcd_num(sum);
}
}while(y!=8);

if(sum==sum1)
{
dis_cmd(0x01);
_delay_ms(50);
dis_cmd(0xc2);
string_LCD("congrates");
break;
}
else
{
dis_cmd(0x01);
_delay_ms(50);
dis_cmd(0xc2);
string_LCD("try again");
break;
}
}
return 0;
}


int key()
{ 
int key=1;
while(key)
{
PORTD=0b11111110;
_delay_ms(50);
if((PINA&0X01)==0){while((PINA&0X01)==0);return 1;}
if((PINA&0X02)==0){while((PINA&0X02)==0);return 2;}
if((PINA&0X04)==0){while((PINA&0X04)==0);return 3;}
if((PINA&0X08)==0){while((PINA&0X08)==0);return 4;}

key=1;
PORTD=0b11111101;
_delay_ms(50);
if((PINA&0X01)==0){while((PINA&0X01)==0);return 5;}
if((PINA&0X02)==0){while((PINA&0X02)==0);return 6;}
if((PINA&0X04)==0){while((PINA&0X04)==0);return 7;}
if((PINA&0X08)==0){while((PINA&0X08)==0);return 8;}
key=1;
PORTD=0b11111011;
_delay_ms(50);
if((PINA&0X01)==0){while((PINA & 0X01)==0);return 9;}
if((PINA&0X02)==0){while((PINA & 0X02)==0);return 10;}
if((PINA&0X04)==0){while((PINA & 0X04)==0);return 11;}
if((PINA&0X08)==0){while((PINA & 0X08)==0);return 12;}
key=1;
PORTD=0b11110111;
_delay_ms(50);
if((PINA&0X01)==0){while((PINA&0X01)==0);return 13;}
if((PINA&0X02)==0){while((PINA&0X02)==0);return 14;}
if((PINA&0X04)==0){while((PINA&0X04)==0);return 15;}
if((PINA&0X08)==0){while((PINA&0X08)==0);return 16;}
key=1;
}
}

void lcd_init(void)
{
dis_cmd(0X02);
dis_cmd(0X28);
dis_cmd(0X0c);
dis_cmd(0X06);
dis_cmd(0X80);
}

void lcd_cmd(int x)
{
PORTC=x;
PORTC&=~(1<<rs);
PORTC&=~(1<<rw);
PORTC|=(1<<en);
_delay_ms(1);
PORTC&=~(1<<en);
}

void dis_cmd(int x)
{
int x1;
x1=x&0Xf0;
lcd_cmd(x1);
x1=(x<<4)&0Xf0;
lcd_cmd(x1);
}

void lcd_data(int x)
{
PORTC=x;
PORTC|=(1<<rs);
PORTC&=~(1<<rw);
PORTC|=(1<<en);
_delay_ms(1);
PORTC&=~(1<<en);
}

void dis_data(int x)
{
int x1;
x1=x&0Xf0;
lcd_data(x1);
x1=(x<<4)&0Xf0;
lcd_data(x1);
}

void string_LCD(char *str)
{
int i;
for (i=0;str[i]!='\0';i++)
{
dis_data(str[i]);
}
}

void lcd_num(int abc)
{
dis_cmd(0x04);
unsigned int d=0;
while (abc!=0)
{
d=abc%10;
dis_data(d+48);
abc=abc/10;
}
}
