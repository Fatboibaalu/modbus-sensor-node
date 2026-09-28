#include <stdio.h>     // instead of <iostream>
#include <stdint.h> // gives you uint8_t and uint16_t


uint8_t low_byte(uint16_t value){
    return value & 0xFF;
}

uint8_t high_byte(uint16_t value){
    return value>>8;
}

int main(){

    printf("%02x\n", low_byte(0xABCD));
    printf("%02X\n", high_byte(0xABCD));
    
}