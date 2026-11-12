#include "stm32l476xx.h"
#include "SYSTICKs.h"
#include "buzzer.h"
#include "keypad.h"
#include "motor.h"
#include "clock.h"
#include "delay.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	//SET UP periferals
	setUpClock('B');
	init_buzzer();
	init_KeyPad();
	init_Motor();
	
	//SET UP variables
	int state = 1;
	char fvalue = '\0';
	int set = 0;
	char time[3] = {0}; // in seconds
	time[2] = '\0';
	int n = 0;//number of full rotations
	
	
	//buzz(100);
	//for(int i = 0; i< 1000; i++)
	//				stepRight();
	//for(int i = 0; i< 1000; i++)
	//				stepLeft(); 
	
	//testing key pad
		// while(1)
		 //{
			// time[0]= updateKeypad();
		 //}
	
	while(1){
		switch(state){
		case 1:
			
			if (fvalue == '#')
			{
				state = 2;
				fvalue = '\0';
			}else
			{
				fvalue = updateKeypad();
				if (fvalue != '\0' && fvalue != '#'){
					char temp = time[1];
					time[1] = fvalue;
					time [0] = temp;
				}
			}
			break;
		case 2:
			if (set == 0){
				// set the variable "time" from char to int;
				int seconds = atoi(time);
				if (seconds == 0) { state = 1; time[0] = '\0'; break; }
				
				n = ((2048)* (seconds + 1))/60;
				for(int i = 0; i< n; i++)
					stepRight();
				set = 1;
			}
			
			fvalue = updateKeypad();
			if (fvalue == '#'){
				state = 3;
			}
			break;
		case 3:
			
			for(int i = 0; i < n; i++ )
			{
				stepLeft();
				delay_us(360);
			}
			buzz(50);
		
			//reset state and variables
			state = 1;
			set = 0;
			n = 0;
			fvalue = '\0';
			break;
		}
	}
	
}