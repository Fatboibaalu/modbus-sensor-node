#include <stdio.h>
#include "modbus.h"


int main(){
    int failures =0;
    if (high_byte(0xABCD) != 0xAB) { printf("FAIL high_byte\n"); failures++; }
    if (low_byte(0xABCD)  != 0xCD) { printf("FAIL low_byte\n");  failures++; }
    
    if (modbus_crc((const uint8_t *)"123456789", 9) != 0x4B37) { printf("FAIL modbus_crc\n"); failures++; }

}