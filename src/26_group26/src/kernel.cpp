extern "C"
{
    #include "libc/print.h"  
    #include "Descriptortables/descript_tables.h"
}

extern "C" int kernel_main(void);

int kernel_main(){
    
    //init_gdt();
    //init_idt();


    monitor_write("Hello, World! Welcome to the Kernel.");

    //asm ("int $0x00");

    return 0;
}