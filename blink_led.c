#include <avr/io.h>
#include <util/delay.h>
#define MS_DELAY 200
int main (void) {    
  DDRB = 0x00;   
  DDRD = 0x00;

  DDRD &= ~(1<<PD4);	//PORTB0 as output
  DDRB |= (1<<PB0);	//PORTB0 as output
  DDRB |= (1<<PB4);	//PORTB4 as output
  DDRB |= (1<<PB5);	//PORTB5 as output
  PORTB = 0x00;
  int dir=true;
  bool curstate=false;
  bool laststate=curstate;
    while(1) {     
		if(!((PIND&(1<<4)) == 16)){
			curstate=!curstate;
		}

		if(curstate!=laststate)dir++;
		if(curstate==true){
		PORTB |= (1<<PB0);        
        _delay_ms(MS_DELAY);              
        PORTB &= ~(1<<PB0);              
        _delay_ms(MS_DELAY);
		PORTB |= (1<<PB0);
		PORTB |= (1<<PB4);        
        _delay_ms(MS_DELAY);               
        PORTB &= ~(1<<PB4);           
        _delay_ms(MS_DELAY);
		PORTB |= (1<<PB4);
		PORTB |= (1<<PB5);        
        _delay_ms(MS_DELAY);               
        PORTB &= ~(1<<PB5);           
        _delay_ms(MS_DELAY);
		PORTB |= (1<<PB5);
		}else{
		PORTB |= (1<<PB5);        
        _delay_ms(MS_DELAY);              
        PORTB &= ~(1<<PB5);              
        _delay_ms(MS_DELAY);
		PORTB |= (1<<PB5);
		PORTB |= (1<<PB4);        
        _delay_ms(MS_DELAY);               
        PORTB &= ~(1<<PB4);           
        _delay_ms(MS_DELAY);
		PORTB |= (1<<PB4);
		PORTB |= (1<<PB0);        
        _delay_ms(MS_DELAY);               
        PORTB &= ~(1<<PB0);           
        _delay_ms(MS_DELAY);
		PORTB |= (1<<PB0);
		}
		
		laststate=curstate;
    }
}
