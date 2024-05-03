#include "isr.h"
#include "libc/print.h"  // Assuming a simple text-output function is available

// Interrupt service routine handler
void isr_handler(registers_t regs) {
    monitor_write("Received interrupt: ");
    monitor_write_dec(regs.int_no);
    monitor_put('\n');
    
    // Additional specific interrupt handling code here
}
