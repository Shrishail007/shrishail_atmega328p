/*
    Description: A simple application where a pin goes high and low for certain delay, and delay length decreases on every iteration, could be used with LEDs.
    Supported IC/Controller: atmega328p
    Author: Shrishail C. Talukar
*/

void delay(volatile int value) {
    int i, j;

    for (i = 0; i < value; i++) 
        for (j = 0; j < value; j++) ;
}

void main(void) {
    int i;
    int flag = 0;

    *(volatile unsigned char *)((0x04) + 0x20) |= 1 << 5; // DDRB, set 5th pin as output
    *(volatile unsigned char *)((0x04) + 0x20) |= 1 << 4; // DDRB, set 5th pin as output

    for (i = 1000; i > 0; i = i - 50) {
        if (i == 100)
            flag = 1;    

        delay(i);
        *(volatile unsigned char *)((0x05) + 0x20) &= ~(1 << 5); // PORTB, set 5th pin as low
        delay(i);
        *(volatile unsigned char *)((0x05) + 0x20) |= 1 << 5; // PORTB, set 5h pin as high
    }

    if (flag == 1) {
        *(volatile unsigned char *)((0x05) + 0x20) &= ~(1 << 5); // PORTB, set 5h pin as low
        *(volatile unsigned char *)((0x05) + 0x20) |= (1 << 4); // PORTB, set 4h pin as high
    }

    while (1) ;
}
