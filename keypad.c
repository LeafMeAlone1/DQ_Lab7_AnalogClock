#include "stm32l476xx.h"
#include "keypad.h"
	
unsigned char values[4][4]  = {   {'1','2','3','\0'},{'4','5','6','\0'},{'7','8','9','\0'},{'\0','0','#','\0'}   };
int states[4][4] = {0};


void init_KeyPad(void)
{
	//set all rows initially to 1(which sets them to high impedenace mode); pins 7-10
	GPIOB->ODR |= (0xF<<7);
}


unsigned char updateKeypad(){

	
		
	//Coderun code
	
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
							return (values[r][c]);
						}
					}
		
				
			
			}
		  //set Row back to 1
			GPIOB->ODR |= (1u << (0 + r) );
		
		}	
		
	return '\0';
	
}
