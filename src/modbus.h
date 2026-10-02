#pragma once
#include <stdint.h>

uint8_t high_byte(uint16_t value);
uint8_t low_byte(uint16_t value);
uint16_t modbus_crc(const uint8_t *data, uint16_t length);
void build_read_request(uint8_t *out, uint8_t slave,uint16_t start,uint16_t count );
void build_write_request(uint8_t *out, uint8_t slave, uint16_t reg, uint16_t value);