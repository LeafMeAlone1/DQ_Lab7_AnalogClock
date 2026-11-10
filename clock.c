
#include "clock.h"

void setUpClock(unsigned char clock){
	
	switch (clock){
		case 'A':
			RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
			break;
		case 'B':
			RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
			break;
		case 'C':
			RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
			break;
		case 'a':
			RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
			break;
		case 'b':
			RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
			break;
		case 'c':
			RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
			break;
		
		
	}
}


void setPin(GPIO_TypeDef * port, uint32_t pin, uint32_t value)
{
	uint32_t temp = port->ODR;
	uint32_t mask = 1<< pin;
	if(value)
	{
		// if we're setting pin to high
		temp |= mask;
	}
	else
	{
		// if we're setting pin to low
		temp &= ~mask;
	}
	
	port -> ODR =temp;
}



 
uint32_t getPin(GPIO_TypeDef * port, uint32_t pin)
{
	uint32_t temp = port -> IDR;
	temp = temp >> pin;					//Shift the value over by the value of that pin
	temp &= 0x00000001;						//mask to only read that pin
	return temp;									//return the value of that pin
	
}

