#include <stdint.h>
#include "modbus.h"

uint8_t high_byte(uint16_t value){ return value>>8; }
uint8_t low_byte(uint16_t value){ return value & 0xFF; }

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
void build_write_request(uint8_t *out, uint8_t slave, uint16_t reg, uint16_t value){
    out[0]=slave;
    out[1]=0x06;
    out[2]=high_byte(reg);
    out[3]=low_byte(reg);
    out[4]=high_byte(value);
    out[5]=low_byte(value);
    uint16_t crc = modbus_crc(out,6);
    out[6]=low_byte(crc);
    out[7]=high_byte(crc);
}
