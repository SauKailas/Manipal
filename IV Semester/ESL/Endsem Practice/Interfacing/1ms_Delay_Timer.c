#include<LPC17xx.h>

void initTimer0(void)
{
	LPC_TIM0->CTCR=0x0;
	LPC_TIM0->TCR=0x2;
	LPC_TIM0->PR=2;
	LPC_TIM0->MR0=999;
	LPC_TIM0->MCR=2;
	LPC_TIM0->EMR=0x20;
	LPC_TIM0->TCR=0x01;
}

void delay(void)
{
	initTimer0();
	while(!(LPC_TIM0->EMR & 1));
}