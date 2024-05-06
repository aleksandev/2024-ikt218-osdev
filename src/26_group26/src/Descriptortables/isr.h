#ifndef ISR_H
#define ISR_H

#include "libc/stdint.h"

// Structure representing the registers saved on the stack during an interrupt.
typedef struct {
    uint32_t ds;                  // Data segment selector
    uint32_t edi, esi, ebp, unused, ebx, edx, ecx, eax;  // Pushed by pusha.
    uint32_t int_no, err_code;    // Interrupt number and error code (if applicable)
    uint32_t eip, cs, eflags, esp, ss; // Pushed by the processor automatically.
} registers_t;

void isr_handler(registers_t regs);
 
#endif // ISR_H
