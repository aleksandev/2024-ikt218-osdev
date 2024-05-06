#include "libc/print.h"
// Screen dimensions
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

// Function to print a string to the screen
void print_string(const char* str) {
    static int cursor_x = 0;
    static int cursor_y = 0;
    volatile char* video = (volatile char*)0xB8000;

    while (*str) {
        if (*str == '\n') {
            cursor_x = 0;
            cursor_y++;
        } else {
            int offset = (cursor_y * SCREEN_WIDTH + cursor_x) * 2;
            video[offset] = *str;
            video[offset + 1] = 0x0F; // Light grey on black
            cursor_x++;
            
            // Move to the next line if cursor exceeds screen width
            if (cursor_x >= SCREEN_WIDTH) {
                cursor_x = 0;
                cursor_y++;
            }
        }
        
        str++;
        
        // Handle screen overflow
        if (cursor_y >= SCREEN_HEIGHT) {
            cursor_y = 0; // Wrap around to the top of the screen
        }
    }
}


void printf(const char* format) {
    print_string(format);
}