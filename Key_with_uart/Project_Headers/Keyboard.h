//cfgps2.h

#ifndef cfgps2_H_
#define GPIO_PIN_MASK 0x1Fu 
#define GPIO_PIN(x) (((1)<<(x & GPIO_PIN_MASK)))
	

void teclado_use(void);
void writeLCD(int letra);
void deleteLCD(void);
void shift_use(void);
void alternative_key(int op_a,int op_b);
void bloq_mayus(void);
void alternative_mayus(int ma, int mi);
void despla_up(void);
void despla_der(void);
void despla_izq(void);
void despla_down(void);
void LCD_use(void);
void F_keyboad(int selection);
void enter(void);
void clear_page(void);
void uart_use(void);
void UARTinit(void);

int uart;
int mayus;
int teclado;
int memory;
int shift;
unsigned char LCD[255];
int page;
int place;
int writting;
int lim_lo, lim_hi;
#endif /* cfgps2_H_ */
