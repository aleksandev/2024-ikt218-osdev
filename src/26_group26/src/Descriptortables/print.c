#include "libc/print.h"

// The VGA framebuffer starts at 0xB8000.
static char* const VIDEO_MEMORY = (char*)0xB8000;

// Screen dimensions.
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

// Writes a single character out to the screen.
void monitor_put(char c) {
    static int cursor_x = 0;
    static int cursor_y = 0;
    int offset;

    // Convert the cursor position to an index into the video memory array.
    offset = (cursor_y * SCREEN_WIDTH + cursor_x) * 2;

    // Write the character and then a default light grey on black color byte.
    VIDEO_MEMORY[offset] = c;
    VIDEO_MEMORY[offset + 1] = 0x07; // Light grey on black.
    cursor_x++;

if (cursor_x >= SCREEN_WIDTH) {
    cursor_x = 0;
    cursor_y++;
}
}

// Outputs a null-terminated ASCII string to the monitor.
void monitor_write(const char* s) {
while (*s) {
monitor_put(*s++);
}
}

void monitor_write_dec(unsigned int num) {
    char buffer[20];
    itoa(num, buffer, 10);  // Convert integer to string (assuming you have such a function)
    monitor_write(buffer);
}
