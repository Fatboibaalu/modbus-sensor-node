#include <stdio.h>     // instead of <iostream>
#include <stdint.h> // gives you uint8_t and uint16_t

int main(){

    uint8_t frame[6]={01,03,00,00,00,02};
    for(int i=0;i<6;i++){
        printf("%02X" " ",frame[i]);
    }
    
}