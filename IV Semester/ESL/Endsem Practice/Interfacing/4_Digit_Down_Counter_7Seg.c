#include<LPC17xx.h>

unsigned int i, m=0, counter=9999;
unsigned char array_dec[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void delay(void)
{
	for(i=0; i<10000; i++)
		m++;
}

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();

	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= (0xFF<<4);

	while(1)
	{
		unsigned int digit1=(counter/1000)%10;
		unsigned int digit2=(counter/100)%10;
		unsigned int digit3=(counter/10)%10;
		unsigned int digit4=(counter)%10;

		LPC_GPIO0->FIOPIN=(array_dec[digit1]<<4) | (array_dec[digit2]) | (array_dec[digit3]<<12) | (array_dec[digit4]<<8);
		delay();
		counter=counter-1;

		if(counter<0)
			counter=9999;
	}
	return 0;
}	