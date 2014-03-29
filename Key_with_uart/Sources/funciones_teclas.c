/*
 *  Created on: Feb 19, 2014
 *      Author: Nelson Antonio Pérez Cervantes
 */
#include "derivative.h"
#include "cfgps2.h"
#include "lcd.h"
#include "Keyboard.h"

void shift_use(void)
{
	if ((mayus==0)&&(shift==0))
	{
		while ((teclado == 0x12)||(teclado == 0x59))
		{
			if(data_ready)
			{
			teclado = data;
			data_ready = 0;
			}
			mayus = 1;
			shift = 1;
		}
		teclado_use();
	}
	else if ((mayus==1)&&(shift==0))
	{
		while ((teclado == 0x12)||(teclado == 0x59))
		{
			if(data_ready)
			{
			teclado = data;
			data_ready = 0;
			}
			mayus = 0;
			shift = 1;
		}
		teclado_use();
	}
	else if((mayus==0)&&(shift==1))
	{
		while ((teclado == 0x12)||(teclado == 0x59))
		{
			if(data_ready)
			{
			teclado = data;
			data_ready = 0;
			}
			mayus = 1;
			shift = 0;
		}
		teclado_use();
	}
	else if((mayus==1)&&(shift==1))
	{	
		while ((teclado == 0x12)||(teclado == 0x59))
		{
			if(data_ready)
			{
			teclado = data;
			data_ready = 0;
			}
			mayus = 0;
			shift = 0;
		}
		teclado_use();
	}
	
}
void alternative_mayus(int ma, int mi)
{
if (mayus)
	{
	writeLCD(ma);
	}
	else
	{
	writeLCD(mi);
	}
}
void alternative_key(int op_a,int op_b)
{
if (shift)
	{
	writeLCD(op_b);
	}
	else
	{
	writeLCD(op_a);
	}
}
void bloq_mayus(void)
{
if (mayus == 0)
	{
		if (memory)
		{
			mayus = 1;
			memory = 0;
		}
		else
		{
		memory++;
		}
	}
	else if (mayus == 1)
	{
		if (memory)
		{
			mayus = 0;
			memory = 0;
		}
		else
		{
		memory++;
		}
	}
}
void writeLCD(int letra)
{	
	if (memory)
	{	
		writting = 1;
		memory = 0;
		if ((pos < 256))
		{	
			sendCode(nIns,0x01);
			LCD[pos] = letra;
			pos++;
			if (pos < 32)
			{
				page = 0;
			}
			else if ((pos >= 32)&&(pos < 64))
			{	
				page = 1;
			}
			else if ((pos >= 64)&&(pos < 96))
			{	
				page = 2;
			}
			else if ((pos >= 96)&&(pos < 128))
			{	
				page = 3;
			}
			else if ((pos >= 128)&&(pos < 160))
			{	
				page = 4;
			}
			else if ((pos >= 160)&&(pos < 192))
			{	
				page = 5;
			}
			else if ((pos >= 192)&&(pos < 224))
			{	
				page = 6;
			}
			else if ((pos >= 224)&&(pos < 256))
			{	
				page = 7;
			}
		}
	}
	else
	{
	memory++;
	}
}
void despla_izq(void)
{
	if (memory)
	{	
		memory = 0;
		if (pos > 0)
		{
			pos--;
			writting = 1;
		}
		if ((pos >= 0) && (pos < 32))
		{
			page = 0;
		}
		else if ((pos>=32)&(pos<64))
		{
			page = 1;
		}
		else if ((pos>=64)&(pos<96))
		{
			page = 2;
		}
		else if ((pos>=96)&(pos<128))
		{
			page = 3;
		}
		else if ((pos>=128)&(pos<160))
		{
			page = 4;
		}
		else if ((pos>=160)&(pos<192))
		{
			page = 5;
		}
		else if ((pos>=192)&(pos<224))
		{
			page = 6;
		}
		else if ((pos>=224)&(pos<256))
		{
			page = 7;
		}
	}
	else
	{
	memory++;
	}
}
void despla_der(void)
{
	if (memory)
	{	
		memory = 0;
		if (pos<254)
		{
			pos++;
			writting = 1;
		}
		if ((pos >= 0) && (pos < 32))
		{
			page = 0;
		}
		else if ((pos>=32)&(pos<64))
		{
			page = 1;
		}
		else if ((pos>=64)&(pos<96))
		{
			page = 2;
		}
		else if ((pos>=96)&(pos<128))
		{
			page = 3;
		}
		else if ((pos>=128)&(pos<160))
		{
			page = 4;
		}
		else if ((pos>=160)&(pos<192))
		{
			page = 5;
		}
		else if ((pos>=192)&(pos<224))
		{
			page = 6;
		}
		else if ((pos>=224)&(pos<256))
		{
			page = 7;
		}
	}
	else
	{
	memory++;
	}
}
void despla_up(void)
{
if (memory)
	{	
		memory = 0;
		if (pos > 15)
		{
		pos = pos - 16;
		writting = 1;
		}
		if ((pos >= 0) && (pos < 32))
		{
		page = 0;
		}
		else if ((pos>=32)&(pos<64))
		{
		page = 1;
		}
		else if ((pos>=64)&(pos<96))
		{
		page = 2;
		}
		else if ((pos>=96)&(pos<128))
		{
		page = 3;
		}
		else if ((pos>=128)&(pos<160))
		{
		page = 4;
		}
		else if ((pos>=160)&(pos<192))
		{
		page = 5;
		}
		else if ((pos>=192)&(pos<224))
		{
		page = 6;
		}
		else if ((pos>=224)&(pos<256))
		{
		page = 7;
		}
	}
else
	{
	memory++;
	}
}
void despla_down(void)
{
if (memory)
	{	
		memory = 0;
		if (pos < 240)
		{
		pos = pos + 16;
		writting = 1;
		}
		if ((pos >= 0) && (pos < 32))
		{
		page = 0;
		}
		else if ((pos>=32)&(pos<64))
		{
		page = 1;
		}
		else if ((pos>=64)&(pos<96))
		{
		page = 2;
		}
		else if ((pos>=96)&(pos<128))
		{
		page = 3;
		}
		else if ((pos>=128)&(pos<160))
		{
		page = 4;
		}
		else if ((pos>=160)&(pos<192))
		{
		page = 5;
		}
		else if ((pos>=192)&(pos<224))
		{
		page = 6;
		}
		else if ((pos>=224)&(pos<256))
		{
		page = 7;
		}
	}
else
	{
	memory++;
	}
}
void F_keyboad(int selection)
{
	if (memory)
	{
	writting = 1;
	page = selection;
	memory = 0;
	pos = selection * 32;
	}
	else
	{
	memory++;
	}
}
void deleteLCD(void)
{
	if (memory)
	{	
		writting = 1;
		if ((pos > 0))
		{
			pos--;
			LCD[pos] = ' ';
		}
		if (pos < 32)
		{
			sendCode(nIns,0x01);
			page = 0;
		}
		else if ((pos >= 32)&&(pos < 64))
		{	
			sendCode(nIns,0x01);
			page = 1;
		}
		else if ((pos >= 64)&&(pos < 96))
		{	
			sendCode(nIns,0x01);
			page = 2;
		}
		else if ((pos >= 96)&&(pos < 128))
		{	
			sendCode(nIns,0x01);
			page = 3;
		}
		else if ((pos >= 128)&&(pos < 160))
		{	
			sendCode(nIns,0x01);
			page = 4;
		}
		else if ((pos >= 160)&&(pos < 192))
		{	
			sendCode(nIns,0x01);
			page = 5;
		}
		else if ((pos >= 192)&&(pos < 224))
		{	
			sendCode(nIns,0x01);
			page = 6;
		}
		else if ((pos >= 224)&&(pos < 256))
		{	
			sendCode(nIns,0x01);
			page = 7;
		}
		memory = 0;
	}
	else
	{
	memory++;
	}
}
void enter(void)
{
if (memory)
	{
	writting = 1;
	if (pos<16)
	{
	page = 0;
	pos = 16;
	}
	else if ((pos>=16)&&(pos<32))
	{
	page = 1;
	pos = 32;
	}
	else if ((pos>=32)&&(pos<48))
	{
	page = 1;
	pos = 48;
	}
	else if ((pos>=48)&&(pos<64))
	{
	page = 2;
	pos = 64;
	}
	else if ((pos>=64)&&(pos<80))
	{
	page = 2;
	pos = 80;
	}
	else if ((pos>=80)&&(pos<96))
	{
	page = 3;
	pos = 96;
	}
	else if ((pos>=96)&&(pos<112))
	{
	page = 3;
	pos = 112;
	}
	else if ((pos>=112)&&(pos<128))
	{
	page = 4;
	pos = 128;
	}
	else if ((pos>=128)&&(pos<144))
	{
	page = 4;
	pos = 144;
	}
	else if ((pos>=144)&&(pos<160))
	{
	page = 5;
	pos = 160;
	}
	else if ((pos>=160)&&(pos<176))
	{
	page = 5;
	pos = 176;
	}
	else if ((pos>=176)&&(pos<192))
	{
	page = 6;
	pos = 192;
	}
	else if ((pos>=192)&&(pos<208))
	{
	page = 6;
	pos = 208;
	}
	else if ((pos>=208)&&(pos<224))
	{
	page = 7;
	pos = 224;
	}
	else if ((pos>=224)&&(pos<240))
	{
	page = 7;
	pos = 240;
	}
	memory = 0;
	}
else
	{
	memory++;
	}
}
void clear_page(void)
{
	if (memory)
	{
		writting = 1;
		lim_lo = page*32;
		lim_hi = (page+1)*32;
		for (place = lim_lo;place<lim_hi;place++)
		{
		LCD[place]= ' ';
		}
		memory = 0;
	}
	else
	{
	memory++;
	}
}
void uart_use(void)
{
if (memory)
	{
		uart = 1;
		memory = 0;
	}
	else
	{
	memory++;
	}
}
void UARTinit(void)
{
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	 SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;                                                   
		
	 /* PORTA_PCR1: ISF=0,MUX=2 */
	 PORTA_PCR1 |= (PORT_PCR_MUX(2));
	 
	 /* PORTA_PCR2: ISF=0,MUX=2 */
	 PORTA_PCR2 |= (PORT_PCR_MUX(2));

	 /* Disable TX & RX while we configure settings */
	 UART0_C2 &= ~(UART0_C2_TE_MASK); //disable transmitter
	 UART0_C2 &= ~(UART0_C2_RE_MASK); //disable receiver
	 
	 /* UART0_C1: LOOPS=0,DOZEEN=0,RSRC=0,M=0,WAKE=0,ILT=0,PE=0,PT=0 */
	 UART0_C1 = 0x00U; /* Set the C1 register */
	 /* UART0_C3: R8T9=0,R9T8=0,TXDIR=0,TXINV=0,ORIE=0,NEIE=0,FEIE=0,PEIE=0 */
	 UART0_C3 = 0x00U; /* Set the C3 register */
	 /* UART0_S2: LBKDIF=0,RXEDGIF=0,MSBF=0,RXINV=0,RWUID=0,BRK13=0,LBKDE=0,RAF=0 */
	 UART0_S2 = 0x00U; /* Set the S2 register */
	 
	 SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1); //set clock source to be from PLL/FLL
	 SIM_SOPT2 |= SIM_SOPT2_CLKOUTSEL(0b100);
	 unsigned SBR = 546;//137; //Set the baud rate register, SBR = 137
	 UART0_BDH |= (~UART0_BDH_SBR_MASK) | SBR >> 8;
	 UART0_BDL |= (~UART0_BDL_SBR_MASK) | SBR;
	 
	 char OSR = 3; //set the oversampling ratio to option #3 = 4x
	 UART0_C4 &= (~UART0_C4_OSR_MASK) | OSR;
	 
	 /*
	 * Target Baud rate = 38400 9600
	 *
	 * Baud rate = baud clock / ((OSR+1) * SBR)
	 * baud clock = FLL/PLL = 20.97152MHz  32kHZ
	 * OSR = 3
	 * SBR = 137 //546
	 * Resulting Baud rate = 20.97152MHz / ((3 + 1) * 546) = 9600
	 */
	 
	 UART0_C5 |= UART0_C5_BOTHEDGE_MASK; //enable sampling on both edges of the clock
	 UART0_C2 |= UART0_C2_TE_MASK; //enable transmitter
	 UART0_C2 |= UART0_C2_RE_MASK; //enable receiver
}
