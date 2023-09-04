#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0x01; //Takes PORTB as output
    while(1)
    {
		PORTB = 0x01; //Turns ON All LEDS
		_delay_ms(1000); //1 second delay
		PORTB = 0x00; //Turns OFF All LEDS
		_delay_ms(1000); //1 second delay
    }
}