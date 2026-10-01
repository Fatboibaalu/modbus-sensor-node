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
uint8_t high_byte(uint16_t value){ return value>>8; }
uint8_t low_byte(uint16_t value){ return value & 0xFF; }

void build_read_request(uint8_t *out, uint8_t slave,uint16_t start,uint16_t count ){
    out[0]=slave;
    out[1]=0x03;
    out[2]=high_byte(start);
    out[3]=low_byte(start);
    out[4]=high_byte(count);
    out[5]=low_byte(count);
    uint16_t crc = modbus_crc(out,6);
    out[6]=low_byte(crc);
    out[7]=high_byte(crc);

    

}

int main(){
    uint8_t frame[6]={01,03,00,00,00,02};
    uint8_t frame2[4]={01,03,00,02};
    printf("%04X\n", modbus_crc(frame, 6));
    printf("%04X\n", modbus_crc(frame2, 4));
    uint8_t req[8];
    build_read_request(req, 1, 107,3);
    for (int i = 0; i < 8; i++) printf("%02X ", req[i]);
printf("\n");
}