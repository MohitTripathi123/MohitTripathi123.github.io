#include<avr/io.h>
#define	F_CPU	1000000
#include<util/delay.h>
#include<avr/touchscreen.h>
int main(void)
{

	DDRB=0b00111110;
	int x,y;
	adc_init();
	while(1)
	{
		x=read_touchscreen_x_coordinate();
		_delay_ms(1);
		y=read_touchscreen_y_coordinate();
		_delay_ms(1);
		if((x>210) && (x<340) && (y>510) && (y<650))
		{
			PORTB=0b00000001;
		}
		else if((x>210) && (x<340) && (y>200) && (y<340))
		{
			PORTB=0b00000010;
		}
		else if((x>90) && (x<210) && (y>350) && (y<510))
		{
			PORTB=0b00000100;		
		}
		else if((x>340) && (x<480) && (y>350) && (y<510))
		{
			PORTB=0b00001111;
		}
		else if((x>210) && (x<340) && (y>350) && (y<510))
		{
			PORTB=0b0000011;			
		}
		else
		{
			;
			/*Null statement*/
		}
	}
}
/*End of Program*/

