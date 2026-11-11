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
	//init_Motor();
	
	//SET UP variables
	int state = 1;
	char fvalue;
	int count;
	int set;
	char time[3]; // in seconds
	time[2] = '\0';
	int n;//number of full rotations
	 
	
	while(1){
		switch(state){
		case 1:
			
			if (fvalue == '#')
			{
				state = 2;
			}else
			{
				fvalue = updateKeypad();
				if (fvalue != '\0' && count < 2){
					time[count] = fvalue;
				}
			}
			break;
		case 2:
			if (set == 0){
				
				// set the variable "time" from char to int;
				int temp = atoi(time);// set the variable "time" from char to int;
				
				n = (2048)/(temp * 60);
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
				delay_ms(1000);
			}
			buzz(1000);
		
			//reset state and variables
			state = 1;
			count = 0;
			set = 0;
			n = 0;
			break;
		}
	}
}