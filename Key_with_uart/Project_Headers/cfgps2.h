//cfgps2.h

#ifndef cfgps2_H_
#define GPIO_PIN_MASK 0x1Fu 
#define GPIO_PIN(x) (((1)<<(x & GPIO_PIN_MASK)))
	

void cfgPortPS2(void);
void reading(void);
void cfgPortMouse(void);
void close_init(void);
void data_mouse(void);
void dec_mouse(void);
void sendmouse(unsigned char instruction);
void UARTsend(void);

int d, n, data, clk;
int data_ready;
int start_trama;
int d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10;
int data_bit; 
int init;
unsigned int initialization_mouse[10];
unsigned char trama_mouse[3];
int trama;
int sig_y, sig_x, value_x, value_y;
int data_trama_ready;
int coord_X, coord_Y;
int coord_x, coord_y;
unsigned char mask;
unsigned char counter_bit;
#endif /* cfgps2_H_ */
