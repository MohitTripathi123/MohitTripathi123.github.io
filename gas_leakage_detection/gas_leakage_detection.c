#include <avr/io.h>
#include <util/delay.h>
#include<avr/interrupt.h>
#include<avr/adc.h>

#define F_CPU 1000000
#define rs PC0
#define rw PC1
#define en PC2
void lcd_init(void);
void lcd_cmd(int);
void dis_cmd(int);
void lcd_data(int);
void dis_data(int);
void string_LCD(char *str);
void lcd_number(int);


int main(void)
{

DDRB=0xff;
DDRD=0x07;
int bomb_fire_detection;
lcd_init();
adc_init();
string_LCD(“Zorro Fox”);
lcd_cmd(0xc0);
string_LCD(“Gas leakage”);
_delay_ms(500);
_delay_ms(500);
_delay_ms(500);
_delay_ms(500);
while(1)
{
lcd_cmd(0x01);
string_LCD(“MQ-6 Value:-“);
lcd_cmd(0xc0);
gas_leakage=read_adc_channel(0);
lcd_number(gas_leakage,10);
_delay_ms(500);
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
