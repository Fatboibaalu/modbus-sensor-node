#include <stdio.h>     // instead of <iostream>
#include <stdint.h> // gives you uint8_t and uint16_t
#include "modbus.h"


int main(){
    uint8_t frame[6]={01,03,00,00,00,02};
    uint8_t frame2[4]={01,03,00,02};
    printf("%04X\n", modbus_crc(frame, 6));
    printf("%04X\n", modbus_crc(frame2, 4));
    uint8_t req[8];
    build_read_request(req, 1, 107,3);
    for (int i = 0; i < 8; i++) printf("%02X ", req[i]);
printf("\n");

uint8_t write[8];
build_write_request(write,1,107,3);
 for (int i = 0; i < 8; i++) printf("%02X ", write[i]);
printf("\n");



}