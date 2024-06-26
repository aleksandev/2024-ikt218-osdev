#ifndef PRINT_H
#define PRINT_H


#include "stdint.h"
#include "stdarg.h" 
void print_string(const char* str);

// Function to print a single character to the screen
void print_char(char c);

// Function to print an integer to the screen
void print_int(int value);

// Function to handle variable arguments and print formatted strings to the screen
void vprintf(const char* format, va_list args);

// Function to print formatted strings to the screen (variadic function)
void printf(const char* format, ...);

void printf_dec(uint32_t n);

void itoa(uint32_t n, char* buffer); 

#endif // PRINT_H
