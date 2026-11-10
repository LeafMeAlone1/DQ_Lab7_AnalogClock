
#include "delay.h"

void delay_ms(unsigned int ms) {
	unsigned int i, j;
	for (i = 0; i < ms; i++)
	{
		for (j = 0; j < 16000; j++);
	}
	
}

void delay_us(unsigned int us) {
	unsigned int i, j;
	for (i = 0; i < us; i++)
	{
		for (j = 0; j < 16; j++);	}
	
}


