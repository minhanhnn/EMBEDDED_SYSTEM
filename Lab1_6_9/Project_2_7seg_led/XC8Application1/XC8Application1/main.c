#include <avr/io.h>
#include <xc.h>

#define Num0 0x3F
#define Num1 0x06
#define Num2 0x5B
#define Num3 0x4F
#define Num4 0x66
#define Num5 0x6D
#define Num6 0x7D
#define Num7 0x07
#define Num8 0x7F
#define Num9 0x6F

volatile char wait_flag = 1;
volatile char number = 0;

void print_number(int num){
	switch(num){
		case 0:
		PORTA = Num0;
		break;
		case 1:
		PORTA = Num1;
		break;
		case 2:
		PORTA = Num2;
		break;
		case 3:
		PORTA = Num3;
		break;
		case 4:
		PORTA = Num4;
		break;
		case 5:
		PORTA = Num5;
		break;
		case 6:
		PORTA = Num6;
		break;
		case 7:
		PORTA = Num7;
		break;
		case 8:
		PORTA = Num8;
		break;
		case 9:
		PORTA = Num9;
		break;
		default:
		PORTA = Num0;
	}
}

int main(void)
{
	DDRA = 0xff;  //Takes PORTA as output
	DDRC = ~(0x01); //Takes PORTC as output 
    while(1)
    {   
		if((PINC&1) == 0x00){  //when button is pressed, PINC0 = 0 
			if(wait_flag == 1){ //check the wait_flag to prevent continuous number incrementation when the button is pressed and held
				wait_flag = 0;
				number++;
				if(number > 9){
					number = 0;
				}
				print_number(number); //display number on 7 segment LED
			}
		}
		else{
			wait_flag = 1;
		}
	}
}

