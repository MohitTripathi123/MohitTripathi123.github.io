#include <avr/io.h>
#include <util/delay.h>
#include<avr/interrupt.h>

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

volatile unsigned char input;
volatile unsigned char count=0,entered_password[5],set_password[5]="1234",status=0;

ISR(INT1_vect)
{
	cli();
	input=PIND & 0xf0;
	if(status==0)
	{
		if(count<4)
		{
			_delay_ms(10);
			input=input>>4;
			if(input < 0x0a)
			{
				if(input==0x0a)
				{
					entered_password[count]=48;			
				}
				else
				{
					entered_password[count]=48+input;
				}

				string_LCD('*');
				count++;
				_delay_ms(500);
			}
			else
			{
				;
			}
		}
		else
		{
			;
		}
		if(count==4)
		{
			count=0;
			entered_password[4]='\0';
			if(!(strcmp(entered_password,set_password)))
			{
				status=1;
				lcd_cmd(0x01);
				string_LCD("Correct Password");
				_delay_ms(1000);
				_delay_ms(1000);
				lcd_cmd(0x01);
				string_LCD("Press 2,4,6,8,5:");
			}
			else
			{
				lcd_cmd(0x01);
				string_LCD("Wrong Password");
				status=0;
				_delay_ms(1000);
				_delay_ms(1000);
				lcd_cmd(0x01);
				string_LCD("Re-enter password:");
				lcd_cmd(0xC0);
			}
		}
		else
		{
			;
		}
	}
	else
	{
		;
	}

	sei();
int main(void)
{
	DDRD=0x00;
	DDRB=0x0f;
	lcd_init();
	string_LCD("Password DTMF");
	_delay_ms(500);
	_delay_ms(500);
	lcd_cmd(0x01);
	string_LCD("Enter password:");
	lcd_cmd(0xC0);
	unsigned char mobile_input;
	while(1)
	{
		mobile_input=PIND & 0xf0;
		if(mobile_input == 0x20)
		{
			PORTB=0x0A;
		}
		else if(mobile_input == 0x80)
		{
			PORTB=0x05;
		}
		else if(mobile_input == 0x40)
		{
			PORTB=0x02;
		}
		else if(mobile_input == 0x60)
		{
			PORTB=0x08;
		}
		else if(mobile_input == 0x50)
		{
			PORTB=0x0f;
		}
		else
		{	
			;
			/*Null statement*/
		}
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