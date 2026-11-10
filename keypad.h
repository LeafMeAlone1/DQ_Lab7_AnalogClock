#ifndef __STM32L476R_NUCLEO_KEYPAD_H
#define __STM32L476R_NUCLEO_KEYPAD_H
#include "clock.h"

void init_KeyPad(void);
unsigned char updateKeypad(void);

#endif