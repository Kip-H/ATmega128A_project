/*
 * GccApplication9.c
 *
 * Created: 2023-09-18 오후 10:22:40
 * Author : yjhoo
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>

int main(void)
{
	char tel_num[20] = {0x00, 0x00, 0x00, 0x00, 0x3f, 0x06, 0x3f, 0x40, 0x27, 0x6D, 0x6F, 0x4F, 0x40, 0x3F, 0x6D, 0x6D, 0x3F, 0x00, 0x00, 0x00};
    
    int i, j;
	DDRC = 0xff;
	DDRG = 0x0f;
	while(1){
		for(i=0; i<17; i++){
			for(j=0; j<50; j++){
				PORTC = tel_num[i]; PORTG = 0x08; _delay_ms(5);
				PORTC = tel_num[i+1]; PORTG = 0x04; _delay_ms(5);
				PORTC = tel_num[i+2]; PORTG = 0x02; _delay_ms(5);
				PORTC = tel_num[i+3]; PORTG = 0x01; _delay_ms(5);
			}
		}
	}
	
}

