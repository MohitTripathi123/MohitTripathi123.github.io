#include<avr/io.h>
/*Includes io.h header file where all the Input/Output Registers and its Bits are defined for all AVR microcontrollers*/

#define	F_CPU	1000000
/*Defines a macro for the delay.h header file. F_CPU is the microcontroller frequency value for the delay.h header file. Default value of F_CPU in delay.h header file is 1000000(1MHz)*/

#include<util/delay.h>
/*Includes delay.h header file which defines two functions, _delay_ms (millisecond delay) and _delay_us (microsecond delay)*/

int main(void)
{
	DDRD=0x00;
	/*All the 8 pins of PortD are declared as input (DTMF Decoder is connected)*/
	
	DDRB=0x0f;
	/*PB0,PB1,PB2 and PB3 pins of PortB are declared as output ( i/p1,i/p2,i/p3,i/p4 pins of DC Motor Driver are connected )*/
	
	unsigned char mobile_input;
	/*Variable declarations*/

	/*Start of infinite loop*/
	while(1)
	{
		mobile_input=PIND & 0xf0;
		/*Reading DTMF decoder output value and masking its lower 4 bits*/ 
		
		/*Checking DTMF values to move the robot in direction*/
		if(mobile_input == 0x20)
		{
			PORTB=0x0A;
			/* Robot will move in forward direction*/
		}
		else if(mobile_input == 0x80)
		{
			PORTB=0x05;
			/*Robot will move in backward direction*/
		}
		else if(mobile_input == 0x40)
		{
			PORTB=0x02;
			/*Robot will move in left direction*/
		}
		else if(mobile_input == 0x60)
		{
			PORTB=0x08;
			/*Robot will move in Right direction*/
		}
		else if(mobile_input == 0x50)
		{
			PORTB=0x0f;
			/*Robot will stop*/
		}
		else
		{	
			;
			/*Null statement*/
		}
	}
}
/*End of Program*/
