//basic
//#include <avr/io.h>
//#include<avr/interrupt.h>
//#define TWENTYFIVE 25
//#define FIFTY 50
//#define SEVENTYFIVE 75
//#define FULL 100
//volatile bool led_state = 0;
//ISR(INT0_vect){
//    led_state = !led_state;// toggle Led status
//    while(!(PIND & (1<<PIND2))){}  // wait untill release button
//    if (led_state){
//        PORTD |= (1<<PD7);// led_state=1, LED ON
//    }else{
//        PORTD &= ~(1<<PD7);// led_state=0, LED OFF
//    }
//}
//int main (void) {
//    DDRD |= (1<<PD7);// set PD7 as OUTPUT
//    DDRD &= ~(1<<PD2);// set PD2 as INPUT
//    PORTD |= ~(1<<PD7); // LED off.
//    EICRA &= (~(1<<ISC01)|~(1<<ISC00)); // set INT0 LOW level interrupt request
//    EIMSK |= (1<<INT0);  // enable INT0
//    sei(); // enable interrupt
//    while(1){}
//}

//bonus
//#include <avr/io.h>
//#include<avr/interrupt.h>
//#define TWENTYFIVE 25
//#define FIFTY 50
//#define SEVENTYFIVE 75
//#define FULL 100
//volatile int led_state = 0;
//ISR(INT0_vect){
//    led_state++;// toggle Led status
//    while(!(PIND & (1<<PIND2))){}  // wait untill release button
//    switch (led_state%4)
//    {
//    case 0:
//        OCR1A = 400;
//        break;
//    case 1:
//        OCR1A = 4000;
//        break;
//    case 2:
//        OCR1A = 20000;
//        break;
//    case 3:
//        OCR1A = 39999;
//        break;
//    }
//}
//int main (void) {
//    DDRB |= (1<<PB1);// set PD7 as OUTPUT
//    TCCR1A |= (1 << WGM11) | (1 << COM1A1);
//    TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS11);
//    DDRD &= ~(1<<PD2);// set PD2 as INPUT
//    EICRA &= (~(1<<ISC01)|~(1<<ISC00)); // set INT0 LOW level interrupt request
//    EIMSK |= (1<<INT0);  // enable INT0
//    ICR1 = 39999;
//    OCR1A = 0;
//    sei(); // enable interrupt
//    while(1){}
//}

#include <avr/io.h>
#include<avr/interrupt.h>
#define TWENTYFIVE 25
#define FIFTY 50
#define SEVENTYFIVE 75
#define FULL 100
volatile int led_state = 0;
ISR(INT1_vect){
    led_state++;// toggle Led status
    while(!(PIND & (1<<PIND3))){}  // wait untill release button
    switch (led_state%4)
    {
    case 0:
        OCR1A = 400;
        break;
    case 1:
        OCR1A = 4000;
        break;
    case 2:
        OCR1A = 20000;
        break;
    case 3:
        OCR1A = 39999;
        break;
    }
}
int main (void) {
    DDRB |= (1<<PB1);// set PD7 as OUTPUT
    TCCR1A |= (1 << WGM11) | (1 << COM1A1);
    TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS11);
    DDRD &= ~(1<<PD3);// set PD3 as INPUT
    EICRA &= (~(1<<ISC01)|~(1<<ISC00)); // set INT0 LOW level interrupt request. Low triggered interrupt
    EIMSK |= (1<<INT1);  // enable INT1
    ICR1 = 39999;
    OCR1A = 0;
    sei(); // enable external interrupt
    while(1){}
}