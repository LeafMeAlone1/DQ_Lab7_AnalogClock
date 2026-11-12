
#include "motor.h"
void setMotor(void);

unsigned volatile char state = 0xC;



void init_Motor()
{
	state = 0xC;
	//initialize
	setModer(GPIOB,8,'O');
	setModer(GPIOB,9,'O');
	setModer(GPIOB,10,'O');
	setModer(GPIOB,11,'O');
	
}

void stepLeft()
{
	switch(state)
	{
		case(0x8):
			state =0x4;
		break;
		case(0x4):
			state =0x2;
		break;
		case(0x2):
			state =0x1;
		break;
		case(0x1):
			state =0x8;
		break;
		case(0xC):
			state =0x6;
		break;
		case(0x6):
			state =0x3;
		break;
		case(0x3):
			state =0x9;
		break;
		case(0x9):
			state =0xC;
		break;
		default:
			state = 0xC;
	}
	setMotor();
	delay_us(100);
}

void stepRight()
{
	switch(state)
	{
		case(0x8):
			state =0x1;
		break;
		case(0x4):
			state =0x8;
		break;
		case(0x2):
			state =0x4;
		break;
		case(0x1):
			state =0x2;
		break;
		case(0xC):
			state =0x9;
		break;
		case(0x6):
			state =0xC;
		break;
		case(0x3):
			state =0x6;
		break;
		case(0x9):
			state =0x3;
		break;
		default:
			state = 0xC;
	}
	setMotor();
	delay_us(100);
}

void hstepRight()
{
	switch(state)
	{
		case(0x8):
			state =0xC;
		break;
		case(0x4):
			state =0x6;
		break;
		case(0x2):
			state =0x3;
		break;
		case(0x1):
			state =0x9;
		break;
		case(0xC):
			state =0x4;
		break;
		case(0x6):
			state =0x2;
		break;
		case(0x3):
			state =0x1;
		break;
		case(0x9):
			state =0x8;
		break;
		default:
			state = 0xC;
	}
	setMotor();
	delay_us(100);
}

void hstepLeft()
{
	switch(state)
	{
		case(0x8):
			state =0x9;
		break;
		case(0x4):
			state =0xC;
		break;
		case(0x2):
			state =0x6;
		break;
		case(0x1):
			state =0x3;
		break;
		case(0xC):
			state =0x8;
		break;
		case(0x6):
			state =0x4;
		break;
		case(0x3):
			state =0x2;
		break;
		case(0x9):
			state =0x1;
		break;
		default:
			state = 0xC;
	}
	setMotor();
	delay_us(100);
}

void setMotor(void)
{
	uint32_t bit = (state >> 0)& 1;
	setPin(GPIOB,8,bit); //A
	
	bit = (state >> 1)& 1;
	setPin(GPIOB,9,bit); //B
	
	bit = (state >> 2)& 1;
	setPin(GPIOB,10,bit); //A prime
	
	bit = (state >> 3)& 1;
	setPin(GPIOB,11,bit); //B prime
}

