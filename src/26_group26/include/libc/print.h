void print_string(const char* str) {
    // VGA text mode buffer address
    volatile char *video = (volatile char*)0xB8000;
    while (*str) {
        *video++ = *str++;
        *video++ = 0x0F; // Bright White on Black background attribute byte.
    }
}

// A basic printf function that only handles strings.
void printf(const char* format) {
    print_string(format);
}