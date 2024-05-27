#define KEYBOARD_DATA_PORT 0x60


void handle_scancode(unsigned char scancode);
// Keyboard handler
void keyboard_handler() {
    unsigned char scancode = inb(KEYBOARD_DATA_PORT);

    // Add scancode processing
    handle_scancode(scancode);
    //printf(char_to_print);
}

unsigned char scancode_to_char[] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', /* 9 */
    '9', '0', '-', '=', '\b', /* Backspace */
    '\t', /* Tab */
    'q', 'w', 'e', 'r', /* 19 */
    't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', /* Enter key */
    0, /* 29 - Control */
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', /* 39 */
    '\'', '`', 0, /* Left shift */
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', /* 49 */
    'm', ',', '.', '/', 0, /* Right shift */
    '*',
    0,  /* Alt */
    ' ', /* Space bar */
    // Add more mappings as needed...
};

// Handle scancode
void handle_scancode(unsigned char scancode) {
    if (scancode & 0x80) {
        // key release code, handle if needed
    } else {
        unsigned char ch = scancode_to_char[scancode];
        if (ch) {
            unsigned char printarray[2];
            printarray[0] = ch;
            printarray[1] = '\0';
            printf(printarray);  // Assuming terminal_write(char*, size, color)
        }
    }
}
