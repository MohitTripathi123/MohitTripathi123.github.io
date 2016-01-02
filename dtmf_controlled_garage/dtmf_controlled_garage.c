#include <avr/io.h>
#define	F_CPU	1000000
#include <util/delay.h>
#include <avr/timercounter0.h>
#include <avr/timercounter2.h>
int main(void)
{
	DDRA=0x00;
	DDRB=0x08;
	DDRD=0x80;
	DDRC=0x0f;
	set_timercounter0_mode(3);
	set_timercounter0_prescaler(4);
	set_timercounter0_output_mode(2);
	set_timercounter2_mode(3);
	set_timercounter2_prescaler(4);
	set_timercounter2_output_mode(2);
	unsigned char mobile_input;
	while(1)
	{
		mobile_input=PINA & 0xf0;
		if(mobile_input == 0x20)
		{
		set_timercounter0_compare_value(255);
		set_timercounter2_compare_value(255);
		PORTC=0x0a;
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		}		
		
		else if (mobile_input==0x80)
		{
		set_timercounter0_compare_value(180);
		set_timercounter2_compare_value(180);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		}
		else if (mobile_input==0x40)
		{		
		set_timercounter0_compare_value(100);
		set_timercounter2_compare_value(100);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		}		
		else
		{
			;
		}
	}
}

