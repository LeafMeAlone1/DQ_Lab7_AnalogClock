#include "stm32l476xx.h"
#include "delay.h"
#include "buzzer.h"



void pulse(void);

void init_buzzer(void)
	{
		GPIOB->MODER &= 0xFCFFFFFF; //Set buzzer to output mode
		GPIOB->MODER |= 0x01000000;
	}
	
void buzz(int time_ms){
	for (int i = 0; i < time_ms; i++){
		pulse();
	}
}

void pulse(void)
	{
	GPIOB->ODR |= 0x00001000;
	//setPin(GPIOB,12,1);
	delay_us(200);
	GPIOB->ODR &= 0x00000000;
	//setPin(GPIOB,12,0);
	delay_us(200);
}
