
#include <avr/io.h>
#include <xc.h>

int main(void)
{
	DDRA = 0xff; //Takes PORTA as output
	DDRC = ~(0x01); //Takes PORTC as input
	while(1)
	{
		if((PINC&1) == 0x00){
			PORTA = 0x0F;
		}
		else{
			PORTA = 0xF0;
		}
	}
}

