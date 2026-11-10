#include "SYSTICKs.h"


int Run;

void SysTick_Initialize (uint32_t ticks)
	{ 
		// Disable SysTick IRQ and SysTick counter 
		SysTick->CTRL = 0; 
	
		// Set reload register 
		SysTick->LOAD = ticks - 1;
	
		// Set interrupt priority of SysTick 
		// Make SysTick Least urgent (i.e., highest priority number) 
		// ~NVIC_PRIO_BITS: number of bits for priority levels, defined in CMSIS 
		NVIC_SetPriority (SysTick_IRQn, (1<< __NVIC_PRIO_BITS) - 1); 
	
		// Reset the SysTick counter value 
		SysTick->VAL = 0; 
	
		// Select processor clock 
		// 1 = processor clock; e = external clock 
		SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
	
		// Enables SysTick exception request 
		// 1 = counting down to zero asserts the SysTick exception request 
		// e = counting down to zero does not assert the SysTick exception request 
		SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk; 
		
		// Enable SysTick timer 
		SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk; 
		
	}

	
	 void SysTick_Handler (void) 
	 { 
		//SysTick interrupt service routine 
		 
	 }
	 
	 //Setup and implement external interrupst
void EXTI_Init(void){
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN; //Set GPIOC clock on
	
	GPIOB->MODER &= 0xFFFFFFC0; //Set to input mode
	//GPIOC->MODER |= 0x00000015;
	GPIOB->PUPDR &= 0xFFFFFFC0; //Set to pull-up mode
	GPIOB->PUPDR |= 0x00000015;
	//GPIOC->OTYPER &= 0xFFFFFFF8; //Set to open-drain
	//GPIOC->OTYPER |= 0x00000007;
	
	
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN; //Enable SYSCFG clock
	
	NVIC_EnableIRQ(EXTI0_IRQn); //Enable EXTI 0 interrupt
	NVIC_EnableIRQ(EXTI1_IRQn); //Enable EXTI 1 interrupt
	NVIC_EnableIRQ(EXTI2_IRQn); //Enable EXTI 2 interrupt
	
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI0; //_PC //Select PC0 has the trigger source of EXTI 0
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI1; //Select PC1 has the trigger source of EXTI 1
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI2; //Select PC2 has the trigger source of EXTI 2
	
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PB;
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI1_PB;
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI2_PB;
	
	//EXTI->RTSR1 |= EXTI_RTSR1_RT0; 	//Enable risig edge trigger for EXTI 0
	//EXTI->RTSR1 |= EXTI_RTSR1_RT1; 	//Enable risig edge trigger for EXTI 1
	//EXTI->RTSR1 |= EXTI_RTSR1_RT2; 	//Enable risig edge trigger for EXTI 2
	
	//EXTI->FTSR1 &= ~EXTI_FTSR1_FT0; //Disable falling edge trigger for EXTI 0
	//EXTI->FTSR1 &= ~EXTI_FTSR1_FT1; //Disable falling edge trigger for EXTI 1
	//EXTI->FTSR1 &= ~EXTI_FTSR1_FT2; //Disable falling edge trigger for EXTI 2
	
	EXTI->RTSR1 &= ~EXTI_RTSR1_RT0; 	//Disable risig edge trigger for EXTI 0
	EXTI->RTSR1 &= ~EXTI_RTSR1_RT1; 	//Disable risig edge trigger for EXTI 1
	EXTI->RTSR1 &= ~EXTI_RTSR1_RT2; 	//Disable risig edge trigger for EXTI 2
	
	EXTI->FTSR1 |= EXTI_FTSR1_FT0; //Enable falling edge trigger for EXTI 0
	EXTI->FTSR1 |= EXTI_FTSR1_FT1; //Enable falling edge trigger for EXTI 1
	EXTI->FTSR1 |= EXTI_FTSR1_FT2; //Enable falling edge trigger for EXTI 2
	
	EXTI->PR1 = EXTI_PR1_PIF0;
	EXTI->PR1 = EXTI_PR1_PIF1;
	EXTI->PR1 = EXTI_PR1_PIF2;
	
	EXTI->IMR1 |= EXTI_IMR1_IM0; //Enable EXTI 0 interrupt, line 0
	EXTI->IMR1 |= EXTI_IMR1_IM1; //Enable EXTI 1 interrupt, line 1
	EXTI->IMR1 |= EXTI_IMR1_IM2; //Enable EXTI 2 interrupt, line 2
	
	
	NVIC_SetPriority(EXTI0_IRQn, 1); //Set EXTI 0 to 1
	NVIC_SetPriority(EXTI1_IRQn, 1); //Set EXTI 1 to 1
	NVIC_SetPriority(EXTI2_IRQn, 1); //Set EXTI 2 to 1
	
	
	
}


void EXTI0_IRQHandler(void)  //green button
{
    if (EXTI->PR1 & EXTI_PR1_PIF0)
    {
        /////Insert Code here
			
				///// End Code here
        EXTI->PR1 = EXTI_PR1_PIF0;
    }
}
