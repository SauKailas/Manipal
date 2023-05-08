#include<LPC17xx.h>
#include "LCD_Functions.c"
#include<stdlib.h>

int main()
{
	SystemInit();
	SystemCoreClockUpdate();

	LPC_GPIO1->FIODIR &= ~(1<<7);

	unsigned char Msg1[]={'Die Rolled:'};
	lcd_init();

	lcd_comdata(0x80, 0);
	delay_lcd(800);
	lcd_puts(&Msg[0]);

	while(1)
	{
		if(!(LPC_GPIO1->FIOPIN & (1<<7)))
		{
			unsigned int k=(rand()%6)+1;
			k=k+0x30;
			lcd_comdata(0xC0, 0);
			delay_lcd(800);
			lcd_puts(&k);
		}
	}
	return 0;
}