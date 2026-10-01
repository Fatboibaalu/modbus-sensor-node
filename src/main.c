#include <stdio.h>     // instead of <iostream>
#include <stdint.h> // gives you uint8_t and uint16_t


uint16_t modbus_crc(const uint8_t *data, uint16_t length){
    uint16_t crc = 0xFFFF;

     for(int i=0;i<length;i++){
        crc=crc ^ data[i];
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
    return crc;

}

int main(){
    uint8_t frame[6]={01,03,00,00,00,02};
    uint8_t frame2[4]={01,03,00,02};
    printf("%04X\n", modbus_crc(frame, 6));
    printf("%04X\n", modbus_crc(frame2, 4));
}