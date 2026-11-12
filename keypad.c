#include "stm32l476xx.h"
#include "keypad.h"
	
unsigned char values[4][4]  = {   {'1','2','3','\0'},{'4','5','6','\0'},{'7','8','9','\0'},{'\0','0','#','\0'}   };
int states[4][4] = {0};


void init_KeyPad(void)
{
	//GPIOB->MODER &= 0xFFFF0055;
	//GPIOB->MODER |= 0x00000055;
	//GPIOB->OTYPER |= 0x0000000F;//Set rows to open drain
	//set all rows initially to 1(which sets them to high impedenace mode); pins 0-3
	//GPIOB->ODR |= (0xF<<0);
	
	setModer(GPIOB,0,'O');
	setModer(GPIOB,1,'O');
	setModer(GPIOB,2,'O');
	setModer(GPIOB,3,'O');
	setModer(GPIOB,4,'I');
	setModer(GPIOB,5,'I');
	setModer(GPIOB,6,'I');
	setModer(GPIOB,7,'I');
	
	setOtyper(GPIOB,0,'O');
	setOtyper(GPIOB,1,'O');
	setOtyper(GPIOB,2,'O');
	setOtyper(GPIOB,3,'O');
	
	setPin(GPIOB,0,1);
	setPin(GPIOB,1,1);
	setPin(GPIOB,2,1);
	setPin(GPIOB,3,1);

	
}


unsigned char updateKeypad(){

		 unsigned char send = '\0';
	
		for(int r = 0; r<4;r++)
		{
				//set row to 0
				GPIOB->ODR &= ~(1u << (0 + r) );
				
				for(int c = 0; c<4;c++)
				{
					int input;
					switch (c)
					{
						case 0: 
							input  = ((GPIOB -> IDR >> 4) & 1u); //pin 4
							break;
						case 1: 
							input  = ((GPIOB -> IDR >> 5) & 1u); //pin 5
							break;
						case 2:
							input  = ((GPIOB -> IDR >> 6) & 1u); //pin 6
							break;
						case 3:
							input  = ((GPIOB -> IDR >> 7) & 1u);//pin 7
					}
					
					
					//state 0
					if(states[r][c] == 0)
					{
						if (input == 0)
							states[r][c] = 1;
						else
							 states[r][c] = 0;
					}
					//state 1
					else if(states[r][c] == 1)
					{
						if (input == 0)
							states[r][c] = 2;
						else
							 states[r][c] =0;
					}
					//State 2
					else
					{
						if (input == 0)
							states[r][c] = 2;
						else
						{
							states[r][c] = 0;
							
							send = (values[r][c]);
						}
					}
		
				
			
			}
		  //set Row back to 1
			GPIOB->ODR |= (1u << (0 + r) );
		
		}	
		
	return send;
	
}
