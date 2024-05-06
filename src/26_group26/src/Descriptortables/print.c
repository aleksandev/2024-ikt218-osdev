#include "libc/print.h"

    void print_string(const char* str) {
    volatile char *video = (volatile char*)0xB8000;
    while (*str) {
        *video++ = *str++;
        *video++ = 0x0F; 
    }
}

void printf(const char* format) {
    print_string(format);
}