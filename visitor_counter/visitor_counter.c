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
void string_lcd(unsigned char *str);
void lcd_number(int);
unsigned int ADC_read(unsigned char chn);

int main()
{
int x=0;
DDRA=0X00;
DDRC=0XFF;
PORTA=0XFF;
lcd_init();

while(1)
{
 if((PINA&0X01)==1)
  {
    x=x+1;
  }
else
 if((PINA&0X02)==2)
 {  
  x=x-1;
 }
 dis_cmd(0X85);
 lcd_number(x);
 _delay_ms(100);
 lcd_cmd(0Xc4);
 string_lcd("No. of persons");
}
 return 0;
}



void lcd_init(void)
{
dis_cmd(0X02);  //home position
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

void string_lcd(unsigned char *str)
{
int i;
for(i=0;str[i]!='\0';i++)
{
dis_data(str[i]);
}
return 0;
}

void lcd_number(int abc)
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



unsigned int ADC_read(unsigned char chn) // chn=channel number
{
ADMUX=chn|0x40; // (1<<REFS0)|(0<<REFS1) //selecting channel
ADCSRA=0xE7;
while((ADCSRA & 0x10)==0); 
return ADC;
}
