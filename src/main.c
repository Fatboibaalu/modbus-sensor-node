#include <stdio.h>     // instead of <iostream>
#include <stdint.h> // gives you uint8_t and uint16_t

int main(){
    uint8_t frame[6]={01,03,00,00,00,02};
    uint16_t crc = 0xFFFF;

    for(int i=0;i<6;i++){
        crc=crc ^ frame[i];
        for(int j=0;j<8;j++){
            if(crc & 1) {
                crc=crc>>1;
                crc= crc^ 0xA001;
            }
            else{
                crc=crc>>1;
            }
        
        }
    
    }
     printf("%04X" " ",crc);
     
    
}