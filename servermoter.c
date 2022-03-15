//basic
#include <avr/io.h>
#include <util/delay.h>
int main(void) {
    DDRB |= 1 << PB1;
    TCCR1A |= (1 << WGM11) | (1 << COM1A1);
    TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS11);
    ICR1 = 39999;
    int offset = 400;
    while(1) {
        OCR1A = 1599 + offset;
        _delay_ms(1000);
        OCR1A = 1099 - offset;
        _delay_ms(1000);
    }
    return 0;
}

//bonus
//#include <avr/io.h>
//#include <util/delay.h>
//int main(void) {
//    DDRB |= 1 << PB3;
//    TCCR2A |= (1 << WGM20) | (1 << WGM21)| (1 << COM2A1);
//    TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);
//    int offset = 30;
//    while(1) {
//        OCR2A = 45 + offset;
//        _delay_ms(500);
//        OCR2A = 45 - offset;
//        _delay_ms(500);
//    }
//    return 0;
//}