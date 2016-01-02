#define F_CPU	4000000UL
#include<avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>
#include <string.h>

unsigned char hours=0;
unsigned char minutes=0;
unsigned char seconds=0;
char time[] = "00:00:00";

ISR(TIMER1_COMPA_vect);

#define control_PORT	PORTC
#define control_DDR	DDRC
#define control_PIN	PINC

#define rs PC5
#define rw PC6
#define en PC7
#define set_hours PC0;
#define set_minute PC1;

void lcd_init(void);
void lcd_cmd(int);
void dis_cmd(int);
void lcd_data(int);
void dis_data(int);
void string_lcd(unsigned char *str);
void lcd_update_time(void);
void LCD_goto(unsigned char y, unsigned char x);


int main(void)
{
	unsigned char i; 
 
    lcd_init();
	LCD_goto(1,2);
	string_lcd("Digital Clock");
	LCD_goto(2,4);
	string_lcd(time);
 
	control_PORT = 1<<set_hours | (1<<set_minute);
 
	TCCR1B = (1<<CS12|1<<WGM12);
	OCR1A = 15625-1;
	TIMSK = 1<<OCIE1A;
	sei();
 
	while(1)
    {
		if(!(control_PIN & (1<<set_hours)))
		{
			hours++;
			if(hours > 23)
				hours = 0;
		}
		if(!(control_PIN & (1<<set_minute)))
		{
			minutes++;
			if(minutes > 59)
				minutes = 0;
		}
		_delay_ms(250);
	}
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
PORTD=x;
PORTD&=~(1<<rs);
PORTD&=~(1<<rw);
PORTD|=(1<<en);
_delay_ms(1);
PORTD&=~(1<<en);
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
PORTD=x;
PORTD|=(1<<rs);
PORTD&=~(1<<rw);
PORTD|=(1<<en);
_delay_ms(1);
PORTD&=~(1<<en);
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

void LCD_goto(unsigned char y, unsigned char x)
{
	unsigned char firstAddress[] = {0x80,0xC0,0x94,0xD4};
 
	LCD_send_command(firstAddress[y-1] + x-1);
	_delay_ms(10);	
}


ISR(TIMER1_COMPA_vect)
{
	seconds++;
	if(seconds==60)
	{
		seconds=0;
		minutes++;
	}
	if (minutes==60)
	{
		minutes=0;
		hours++;
	}
	if (hours==60)
		hours=0;
		lcd_update_time();
}

void lcd_update_time()
{
	unsigned char temp;
	LCD_goto(2,4);
 
	itoa(hours/10,temp,10);
	string_lcd(temp);
	itoa(hours%10,temp,10);
	string_lcd(temp);
	string_lcd(":");
 
	itoa(minutes/10,temp,10);
	string_lcd(temp);
	itoa((minutes%10),temp,10);
	string_lcd(temp);
	string_lcd(":");
 
	itoa(seconds/10,temp,10);
	string_lcd(temp);
	itoa(seconds%10,temp,10);
	string_lcd(temp);
}
