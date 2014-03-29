/*
 *  Created on: Feb 19, 2014
 *      Author: Nelson Antonio Pérez Cervantes
 */
#include "derivative.h"
#include "cfgps2.h"
#include "lcd.h"

void sendmouse(unsigned char intruction)
{
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;

	PORTD_PCR1 |= (PORT_PCR_MUX(1)); 	//data
	PORTD_PCR0 |= (PORT_PCR_MUX(1));	//clk
	mask = 1;
	
	GPIOD_PDDR |= 0x01;
	GPIOD_PDOR &= 0x01;
	
	delay(205);
	
	GPIOD_PDDR |= 0x02;
	GPIOD_PDDR &= 0x02;
	
	GPIOD_PDDR &= ~0x01;
	
	while((GPIOD_PDIR & 0x1) == 0);
	
	for (counter_bit = 0; counter_bit <= 7; counter_bit++)
	{
		while((GPIOD_PDIR & 0x01) == 0x01);
		if((intruction & mask)== mask)							
		{
			GPIOD_PDDR &= ~0x02;
		}
		else
		{
			GPIOD_PDDR |= 0x02;
			GPIOD_PDDR &= 0x02;
		}
		while((GPIOD_PDIR & 0x01) == 0);
		mask = mask << 1;	
	}
	
	while((GPIOD_PDIR & 0x01) == 0x01);
	
	GPIOD_PDDR |= 0x02;
	GPIOD_PDDR &= 0x02;
	
	while((GPIOD_PDIR & 0x01) == 0);
	
	while((GPIOD_PDIR & 0x01) == 0x01);
	
	GPIOD_PDDR &= ~0x02;
	
	while((GPIOD_PDIR & 0x01) == 0);
	
	while((GPIOD_PDIR & 0x01) == 0x04);
	while((GPIOD_PDIR & 0x01) == 0);  
	trama = 0;
	data_trama_ready = 0;
}

void data_mouse(void)
{
	if((data_ready)&&(data_trama_ready == 0))
	{
		if (data!=0xFA)
		{
		trama_mouse[trama] = data;
		trama++;
		data = 0;
		data_ready = 0;
			if (trama >= 3)
			{
				trama = 0;
				data_trama_ready = 1;
			}
		}
		else
		{
			data = 0;
			data_ready = 0;
		}
	}
}
