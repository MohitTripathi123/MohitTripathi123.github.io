#include<reg52.h>
#include<stdio.h>
#define KEYPADPORT    P1 
void delay(void);

//led connection
sbit led1 = P2^2;
sbit led2 = P2^3;
sbit led3 = P2^4;
sbit led4 = P2^5;
sbit led5 = P2^6;
sbit led0 = P2^7;

//motor connection
sbit motor_pin_1 = P2^0;
sbit motor_pin_2 = P2^1;

//sensor connection
sbit sensor1 = P3^0;
sbit sensor2 = P3^1;
sbit sensor3 = P3^2;
sbit sensor4 = P3^3;
sbit sensor5 = P3^4;

//Keypad Connections
sbit R1 = P1^0;
sbit R2 = P1^1;
sbit R3 = P1^2;
sbit R4 = P1^3;
sbit C1 = P1^4;
sbit C2 = P1^5;
sbit C3 = P1^6;
sbit C4 = P1^7;



void main() //initilze function
{ 
sensor1=sensor2=sensor3=sensor4=sensor5=0;//sensor move in zero
  {
  C1=1;	  // keypad initilazation connection
  C2=1;
  C3=1;
  C4=1;
  R1=0;
  R2=1;
  R3=1;
  R4=1;
  {
  //for 1st floor
  if(sensor1==1&&sensor2==0&&sensor3==0&&sensor4==0&&sensor5==0)//define 1st floor through sensor
   { 
   	if(C1==0)	 //choose 1st key
   	   {
  		led1 =0;  // led off
  		motor_pin_1 = 1;	//1st floor
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 0;	 // stop motor
   		motor_pin_2 = 0;
	    led1 = 1;	 //led on
   	   }
   else if(C2==0)  	//choose 2nd key
       {
   		led2 = 0;	 //led off
   		motor_pin_1 = 1;	//1nd floor
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 1;	//2nd floor
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 0;	 //stop motor
   		motor_pin_2 = 0; 
		led2 = 1;	  //led on
       }
   else if(C3==0)	 // choose 3rd key
	   {
		led3 = 0;	  //led 
   		motor_pin_1 = 1;	//1rd
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 1;	//2rd
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 1;	//3rd
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 0;
   		motor_pin_2 = 0; 
    	led3 = 1;	   //led on
	   }
   else if(C4==0)	  // choos 4th key
       {
		led4 = 0;	  //led on
	 	motor_pin_1 = 1;	//1st floor
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 1;	//2nd  floor
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 1;	//3rd  floor
   		motor_pin_2 = 0;
   		delay();
		motor_pin_1 = 1;	//4th  floor
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 0;	//motor stop
   		motor_pin_2 = 0;
		led4 = 1; 	 // led on
 	    }
	    R1=1;		 //for select row in 4*4 matrix keypad
  		R2=0;
  		R3=1;
  		R4=1;
		if(C1==0)
        {
		led5 = 0;	  //led off
	 	motor_pin_1 = 1;	//1st floor
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 1;	//2nd floor
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 1;	//3rd floor
   		motor_pin_2 = 0;
   		delay();
		motor_pin_1 = 1;	//4th floor
   		motor_pin_2 = 0;
   		delay();
		motor_pin_1 = 1;	//5th floor
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 0;	 //motor stop
   		motor_pin_2 = 0;
		led5 = 1; 		//led on
	    }
      }
	// for second floor
    else if(sensor1==0&&sensor2==1&&sensor3==0&&sensor4==0&&sensor5==0)	// for second floor choose 2nd sensor
     { 
      if(C1==0) 		//choose keypad 1st
	  {
	   	led2 = 0;	 //led off
   		motor_pin_1 = 0;	//2nd floor
   		motor_pin_2 = 1;
   		delay();
   		motor_pin_1 = 0;	// 3rd floor
   		motor_pin_2 = 0; 
		led2 = 1;  //led on
	   }
      if(C2==0) // choose second key 
       {
   		led2 = 0;	  //led off
   		motor_pin_1 = 1;	//2nd floor
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 0;   //motor stop
   		motor_pin_2 = 0; 
		led2 = 1;	  //led on
       }
   else if(C3==0)  // choose third key
     	{
		led3 = 0;	//led off
   		motor_pin_1 = 1;	//2nd
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 1;	//3rd
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 0;	 //motor stop
   		motor_pin_2 = 0; 
    	led3 = 1;	 //led on
	    }
   else if(C4==0)  //choose 4th key
        {
		led4 = 0;
   		motor_pin_1 = 1;	//2nd
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 1;	//3rd
   		motor_pin_2 = 0;
   		delay();
		motor_pin_1 = 1;	//4rd
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 0;
   		motor_pin_2 = 0;
		led4 = 1; 
 	    }
	    R1=1;
  		R2=0;
  		R3=1;
  		R4=1;
		if(C1==0)
        {
		led5 = 0;
   		motor_pin_1 = 1;	//2rd
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 1;	//3rd
   		motor_pin_2 = 0;
   		delay();
		motor_pin_1 = 1;	//4rd
   		motor_pin_2 = 0;
   		delay();
		motor_pin_1 = 1;	//5rd
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 0;
   		motor_pin_2 = 0;
		led5 = 1; 
	    }
	   else if(C1==0)
	    {
  		led0 =0;
  		motor_pin_1 = 0;	//0th 
   		motor_pin_2 = 1;
   		delay();
   		motor_pin_1 = 0;
   		motor_pin_2 = 0;
	    led0 = 1;
   	    }
	  //for 3rd floor
   else if(sensor1==0&&sensor2==0&&sensor3==1&&sensor4==0&&sensor5==0)
       { 
       if(C1==1)
   		{
    	led1=0;
		motor_pin_1 = 0;	//2th 
   		motor_pin_2 = 1;
   		delay();
		motor_pin_1 = 0;	//1th 
   		motor_pin_2 = 1;
   		delay();
   		motor_pin_1 = 0;
   		motor_pin_2 = 0;
		led1 = 1;
   	 	}
		if(C2==2)
		{
		led2=0;
   		motor_pin_1 = 0;   //2nd
   		motor_pin_2 = 1;
		motor_pin_1 = 0;
   		motor_pin_2 = 0;
		led2 = 1;
   	 	}
   	else if(C4==0)
		{
		led4 = 0;
   		motor_pin_1 = 1;	//4th
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 0;
   		motor_pin_2 = 0; 
    	led5 = 1;
		}
	    R1=1;
  		R2=0;
  		R3=1;
  		R4=1;
		if(C1==0)
    	{
		led5 = 0;
   		motor_pin_1 = 1;	//4rd
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 1;	//5rd
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 0;
   		motor_pin_2 = 0;
		led5 = 1; 
	  	}
	   else if(C2==0)
	   {
  		led0 =0;
  		motor_pin_1 = 0;	//2th 
   		motor_pin_2 = 1;
   		delay();
		motor_pin_1 = 0;	//1th 
   		motor_pin_2 = 1;
   		delay();
		motor_pin_1 = 0;	//1st 
   		motor_pin_2 = 1;
   		delay();
   		motor_pin_1 = 0;
   		motor_pin_2 = 0;
	    led0 = 1;
   	  	}
		//4th floor
 	else if(sensor1==0&&sensor2==0&&sensor3==0&&sensor4==1&&sensor5==0)
   		{ 
   		if(C1==1)
   		{
    	led1=0;
		motor_pin_1 = 0;	//3rd 
   		motor_pin_2 = 1;
   		delay();
		motor_pin_1 = 0;	//2nd 
   		motor_pin_2 = 1;
   		delay();
		motor_pin_1 = 0;	//1st 
   		motor_pin_2 = 1;
   		delay();
   		motor_pin_1 = 0;
   		motor_pin_2 = 0;
		led1 = 1;
   	 	}
		if(C2==2)
		led2=0;
   		motor_pin_1 = 0;	//3rd
   		motor_pin_2 = 1;
		motor_pin_1 = 0;	//2nd 
   		motor_pin_2 = 1;
   		delay();
		motor_pin_1 = 0;
   		motor_pin_2 = 0;
		led2 = 1;
   	 	}
      if(C3==0)  
   		{
   		led3 = 0;
   		motor_pin_1 = 1;	//3th
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 0;
   		motor_pin_2 = 0; 
		led3 = 1;
   		}
	    R1=1;
  		R2=0;
  		R3=1;
  		R4=1;
		if(C1==0)
    	{  	
		led5 = 0;
   		motor_pin_1 = 1;	//5th
   		motor_pin_2 = 0;
   		delay();
   		motor_pin_1 = 0;
   		motor_pin_2 = 0;
		led5 = 1; 
	  	}
	   else if(C2==0)
	   {
  		led0 =0;
  		motor_pin_1 = 0;	//3th 
   		motor_pin_2 = 1;
   		delay();
		motor_pin_1 = 0;	//2th 
   		motor_pin_2 = 1;
   		delay();
		motor_pin_1 = 0;	//1th 
   		motor_pin_2 = 1;
   		delay();
		motor_pin_1 = 0;	//0th 
   		motor_pin_2 = 1;
   		delay();
   		motor_pin_1 = 0;
   		motor_pin_2 = 0;
	    led0 = 1;
  	 	  }
    //5th floor
   else if(sensor1==0&&sensor2==0&&sensor3==0&&sensor4==1&&sensor5==0)
   		{ 
   		if(C1==1)
   		{
    	led1=0;
		motor_pin_1 = 0;	//4th
   		motor_pin_2 = 1;
   		delay();
		motor_pin_1 = 0;	//3rd 
   		motor_pin_2 = 1;
   		delay();
		motor_pin_1 = 0;	//2nd 
   		motor_pin_2 = 1;
   		delay();
		motor_pin_1 = 0;	//1st 
   		motor_pin_2 = 1;
   		delay();
   		motor_pin_1 = 0;
   		motor_pin_2 = 0;
		led1 = 1;
   		 }
		if(C2==2)
		{
		led2=0;
		motor_pin_1 = 0;	//4th
   		motor_pin_2 = 1;
   		delay();
   		motor_pin_1 = 0;	//3rd
   		motor_pin_2 = 1;
		delay();
		motor_pin_1 = 0;	//2nd 
   		motor_pin_2 = 1;
   		delay();
		motor_pin_1 = 0;
   		motor_pin_2 = 0;
		led2 = 1;
   	 	}
      	if(C3==0)  
     	{
   		led3 = 0;
		motor_pin_1 = 0;	//4th
   		motor_pin_2 = 1;
   		delay();
   		motor_pin_1 = 0;	//3th
   		motor_pin_2 = 1;
   		delay();
   		motor_pin_1 = 0;
   		motor_pin_2 = 0; 
		led3 = 1;
	    }
	   if(C4==0)
	   {
	   	led4 = 0;
   		motor_pin_1 = 0;	//4th
   		motor_pin_2 = 1;
   		delay();
   		motor_pin_1 = 0;
   		motor_pin_2 = 0; 
		led4 = 1;
   	   }
	    R1=1;
  		R2=0;
  		R3=1;
  		R4=1;
	   if(C2==0)
	   {
  		led0 =0;
		motor_pin_1 = 0;	//4th 
   		motor_pin_2 = 1;
   		delay();
  		motor_pin_1 = 0;	//3th 
   		motor_pin_2 = 1;
   		delay();
		motor_pin_1 = 0;	//2th 
   		motor_pin_2 = 1;
   		delay();
		motor_pin_1 = 0;	//1th 
   		motor_pin_2 = 1;
   		delay();
		motor_pin_1 = 0;	//0th 
   		motor_pin_2 = 1;
   		delay();
   		motor_pin_1 = 0;
   		motor_pin_2 = 0;
	    led0 = 1;
   	  	}
		}
	  }
    }
  }
 }
 }

void delay()
{
int count=0,sec;
  for(sec=0;sec<60;sec++)
  {
	count=0;
	while(count!=40)
	{
	TMOD=0x01;  //16-bit timer0 selected
	TH0=0xF8;   // Loading high byte in TH
	TL0=0xCC;   // Loaded low byte in TL
	TR0=1;      // Running the timer
	while(!TF0);   //Checking the timer flag register if it is not equal to 1 
	TR0 = 0;      // If TF0=1 stop the timer
	TF0 = 0;      // Clear the Timer Flag bit for next calculation
	count++;
	}
  }
}