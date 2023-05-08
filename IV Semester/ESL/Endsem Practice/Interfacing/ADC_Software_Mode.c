#include<LPC17xx.h>
#include "LCD_Functions.c"
#include<stdio.h>

#define Ref_Vtg 3.300
#define Full_Scale 0xFFF

unsigned char Msg1[]={"ANALOG IP: "};
unsigned char Msg2[]={"ADC O/P: "};
unsigned long adc_temp;

int main(void)
{
	LPC_PINCON->PINSEL3 = 3<<30;
	LPC_SC->PCON |= (1<<12);

	lcd_init();
	lcd_comdata(0x80, 0);
	delay_lcd(800);
	lcd_puts(&Msg1[0]);

	lcd_comdata(0xC0, 0);
	delay_lcd(800);
	lcd_puts(&Msg2[0]);

	while(1)
	{
		LPC_ADC->ADCR = (1<<5) | (1<<21) | (1<<24);

		while(!(LPC_ADC->ADDR5 & 0x80000000));

		adc_temp=LPC_ADC->ADDR5;
		adc_temp>>=4;
		adc_temp &= 0x00000FFF;

		in_vtg=((float)adc_temp*Ref_Vtg)/Full_Scale;
		sprintf(vtg, "%3.2fV", in_vtg);
		sprintf(dval, "%x", adc_temp);

		for(i=0; i<2000; i++);

		lcd_comdata(0x89, 0);
		delay_lcd(800);
		lcd_puts(%vtg[0]);

		lcd_comdata(0xC8, 0);
		delay_lcd(800);
		lcd_puts(&dval[0]);

		for(i=0; i<20000; i++);
		for(i=0; i<7; i++)
			vtg[i]=dval[i]=0x00;

		adc_temp=0;
		in_vtg=0;
	}

	return 0;
}