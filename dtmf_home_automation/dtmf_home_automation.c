#include<avr/io.h>
#define	F_CPU	1000000
#include<util/delay.h>
int main(void)
{
	DDRD=0x00;
	DDRB=0x0f;
	unsigned char mobile_input;
	while(1)
	{
		mobile_input=PIND & 0xf0;
		if(mobile_input == 0x20)
		{
			PORTB=0x02;
		}
		else if(mobile_input == 0x80)
		{
			PORTB=0x00;
		}
		
		}
		else
		{	
			;
			/*Null statement*/
		}
	}
}
/*End of Program*/
