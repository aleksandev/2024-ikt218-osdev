#ifndef PRINT_H
#define PRINT_H


#include "stdint.h"

void printf(const char* format);

void print_string(const char* str);

void printf_dec(uint32_t n);

void itoa(uint32_t n, char* buffer); 

#endif // PRINT_H
