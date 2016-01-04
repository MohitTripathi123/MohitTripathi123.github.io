#define F_CPU	4000000UL
#include<avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>
#include <string.h>

ISR(ADC_vect);

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
void LCD_goto(unsigned char y, unsigned char x);
void string_lcd(unsigned char *str);




int main(void)
{
    lcd_init();
	LCD_goto(1,2);
	string_lcd("Temperature is");
 
	control_PORT = (1<<set_hours | 1<<set_minute);
 
	DDRA = 0x00;			
 
	ADCSRA = 0x8F;			
				
	ADMUX = 0xE0;			
					
 
	sei();				
	ADCSRA |= 1<<ADSC;	
 
	while(1)
	{
		if(tempf>35)
		{
			PORTB=0x01;
		}
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
}

void LCD_goto(unsigned char y, unsigned char x)
{
	unsigned char firstAddress[] = {0x80,0xC0,0x94,0xD4};
 
	LCD_send_command(firstAddress[y-1] + x-1);
	_delay_ms(10);	
}



ISR(ADC_vect)
{	
	char tempC, tempF, display;
	float tempff;
 
	tempC = ADCH;			// Output ADCH to PortD
	tempff = (float)tempC;
	tempff = (tempff*9)/5 + 32;	
	tempF = tempff;
 
	LCD_goto(2,4);	
	itoa(tempC/10,display,10);
	string_lcd(display);
	itoa(tempC%10,display,10);
	string_lcd(display);
	lcd_data(0xDF);
	string_lcd("C   ");
	ADCSRA |= 1<<ADSC;	
}
