#include<LPC17xx.h>
#include<stdio.>

int temp1, temp2;

void delay_lcd(unsigned int r1)
{
	unsigned int r, m=0;
	for(r=0; r<r1; r++)
		m++;
}

void lcd_init(void)
{
	lcd_com(0x33);
	delay_lcd(800);

	lcd_com(0x32);
	delay_lcd(800);

	lcd_com(0x28);
	delay_lcd(800);

	lcd_com(0x0C);
	delay_lcd(800);

	lcd_com(0x06);
	delay_lcd(800);

	lcd_com(0x01);
	delay_lcd(800);
	return;
}

void clear_ports(void)
{
	LPC_GPIO0->FIOCLR=(0xF<<23);
	LPC_GPIO0->FIOCLR=(1<<27);
	LPC_GPIO0->FIOCLR=(1<<28);
	return;
}

void write_cmd(void)
{
	clear_ports();
	LPC_GPIO0->FIOPIN=temp2;
	LPC_GPIO0->FIOCLR=(1<<27);
	LPC_GPIO0->FIOSET=(1<<28);
	delay_lcd(800);
	LPC_GPIO0->FIOCLR=(1<<28);
	return;
}

void lcd_com(int temp1)
{
	temp2=temp1 & 0xF0;
	temp2=temp2<<19;
	write_cmd();
	delay_lcd(30000);

	temp2=temp1 & 0x0F;
	temp2=temp2<<23;
	write_cmd();
	delay_lcd(30000);
	return;
}

void write_data(void)
{
	clear_ports();
	LPC_GPIO0->FIOPIN=temp2;
	LPC_GPIO0->FIOCLR=(1<<27);
	LPC_GPIO0->FIOSET=(1<<28);
	delay_lcd(800);
	LPC_GPIO0->FIOCLR=(1<<28);
	return;
}

void lcd_data(int temp1)
{
	temp2=temp1 & 0xF0;
	temp2=temp2<<19;
	write_data();
	delay_lcd(30000);

	temp2=temp1 & 0x0F;
	temp2=temp2<<23;
	write_data();
	delay_lcd(30000);
	return;
}

void lcd_puts(unsigned char *buf)
{
	unsigned int i=0;

	while(buf[i]!='\0')
	{
		temp1=buf[i];
		lcd_data();
		delay_lcd(800);
		i++;

		if(i==16)
		{
			lcd_com(0xC0, 0);
			delay_lcd(800);
		}
	}
	return;
}