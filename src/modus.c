#include <stdint.h>

uint8_t high_byte(uint16_t value){ return value>>8; }
uint8_t low_byte(uint16_t value){ return value & 0xFF; }