#include<LPC17xx.h>

unsigned int i, m=0;
unsigned int dig_counter_up=0x00, dig1_up=0x00, dig2_up=0x00, dig3_up=0x00, dig4_up=0x00, temp1=0x00;
unsigned int counter_down=9999, dig1_down, dig2_down, dig3_down, dig4_down;
unsigned char array_dec[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned int seg_select[]={0<<23, 1<<23, 2<<23, 3<<23};

void Delay(void)
{
	for(i=0; i<10000; i++)
		m++;
}

void Display(void)
{
	LPC_GPIO1->FIOPIN=seg_select[dig_counter_up];

	if(dig_counter_up==0x00)
		temp1=dig1_up;
	else if(dig_counter_up=0x01)
		temp1=dig2_up;
	else if(dig_counter_up=0x02)
		temp1=dig3_up;
	else
		temp1=dig4_up;

	LPC_GPIO0->FIOPIN=array_dec[temp1]<<4;
	Delay();
}

void Up_Counter(void)
{
	while(1)
	{
		Delay();
		Display();
		dig_counter_up=dig_counter_up+1;

		if(dig_counter_up==0x04)
		{
			dig_counter_up=0x00;
			dig1_up=dig1_up+1;

			if(dig1_up==0x0A)
			{
				dig1_up=0x00;
				dig2_up=dig2_up+1;

				if(dig2_up==0x0A)
				{
					dig2_up=0x00;
					dig3_up=dig3_up+1;

					if(dig3_up==0x0A)
					{
						dig3_up=0x00;
						dig4_up=dig4_up+1;

						if(dig4_up==0x0A)
							dig4_up=0x00;
					}
				}
			}
		}
	}
}

void Down_Counter(void)
{
	while(1)
	{
		dig1_down=(counter_down/1000)%10;
		dig2_down=(counter_down/100)%10;
		dig3_down=(counter_down/10)%10;
		dig4_down=(counter_down)%10;

		LPC_GPIO0->FIOPIN=(array_dec[dig1_down]<<4) | (array_dec[dig2_down]) | (array_dec[dig3_down]<<12) | (array_dec[dig4_down]<<8);
		Delay();

		counter_down=counter_down-1;
		if(counter_down==0)
			counter_down=9999;
	}
}

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();

	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= (0xFF)<<4;
	LPC_GPIO1->FIODIR &= ~(0x1)<<7;
	LPC_GPIO1->FIODIR |= (0xF)<<23; //Seven Segment Display

	if(LPC_GPIO1->FIOPIN & (0x1)<<7) //Up Counter
		Up_Counter();
	else
		Down_Counter();

	return 0;
}