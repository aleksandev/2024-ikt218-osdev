#include "isr.h"
#include "libc/print.h"  // Assuming a simple text-output function is available


void itoa(uint32_t n, char* buffer) {
    int i = 0;
    if (n == 0) {
        buffer[i++] = '0';
    } else {
        while (n != 0) {
            buffer[i++] = (n % 10) + '0'; // Get the last digit and convert it to char
            n /= 10;
        }
    }

    buffer[i] = '\0';

    // Reverse the string since the digits are stored in reverse order
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
        start++;
        end--;
    }
}

void printf_dec(uint32_t n) {
    char buffer[12]; // Maximum of 10 digits for 32-bit integers + sign + null terminator
    itoa(n, buffer); 
    printf(buffer);
}


// Interrupt service routine handler
void isr_handler(registers_t regs) {
    printf("Received interrupt: ");
    int temp = regs.int_no;
    printf_dec(regs.int_no);

    
    // Additional specific interrupt handling code here
   
}
