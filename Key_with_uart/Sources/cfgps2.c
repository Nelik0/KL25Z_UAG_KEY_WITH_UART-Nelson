/*
 *  Created on: Feb 19, 2014
 *      Author: Nelson Antonio Pérez Cervantes
 */
#include "derivative.h"
#include "cfgps2.h"
#include "lcd.h"

void cfgPortPS2(void) 
{ 
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;

    PORTD_PCR1 |= (PORT_PCR_MUX(1)); 	//data
    PORTD_PCR0 |= (PORT_PCR_MUX(1)); //clk
  
    PORTD_PCR0 |= (PORT_PCR_IRQC(0b1010));
    
    GPIOD_PDDR = 0x0;
    
    NVIC_ICPR |= 1 <<((INT_PORTD-16)%32);
   	NVIC_ISER |= 1 <<((INT_PORTD-16)%32);
   	
   	d = 0;
   	data = 0;
   	start_trama = 0;
} 

void PORTD_IRQHandler(void)
{
	if (((GPIOD_PDIR & 0x02) == 0x00) && (data_ready == 0))
		{
			start_trama = 1;
		}
		if ((start_trama == 1))
		{
			switch (GPIOD_PDIR & 0x02)
			{
			case 0x02:
				data_bit = 1;
				break;
			default:
				data_bit = 0;
				break;
			}
			switch (d)
			{
			case 0:
				d0 = data_bit;
				break;
			case 1:
				d1 = data_bit * 1;
				break;
			case 2:
				d2 = data_bit * 2;
				break;
			case 3:
				d3 = data_bit * 4;
				break;
			case 4:
				d4 = data_bit * 8;
				break;
			case 5:
				d5 = data_bit * 16;
				break;
			case 6:
				d6 = data_bit * 32;
				break;
			case 7:
				d7 = data_bit * 64;
				break;
			case 8:
				d8 = data_bit * 128;
				break;	
			case 9:
				d9 = data_bit;
				break;
			case 10:
				d10 = data_bit; 
				break;
			}
			d++;
			if((d >= 11) && ((GPIOD_PDIR & 0x02) == 0x02))
			{
				d = 0;
				data_ready = 1;
				start_trama = 0;
				data =d1+d2+d3+d4+d5+d6+d7+d8;
			}
		}
		data_mouse();
	PORTD_PCR0 |= 0x1000000;
}
	

