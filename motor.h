#ifndef __STM32L476R_NUCLEO_MOTOR_H
#define __STM32L476R_NUCLEO_MOTOR_H
#include "clock.h"
#include "stm32l476xx.h"
#include "delay.h"


void init_Motor();

void stepRight();
void stepLeft();
void hStepRight();
void hStepLeft();


#endif







