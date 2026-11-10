#ifndef __STM32L476R_NUCLEO_BUZZER_H
#define __STM32L476R_NUCLEO_BUZZER_H
#include "stm32l476xx.h"
#include "delay.h"
#include "clock.h"

void init_buzzer(void);
void buzz(int time_ms);

#endif