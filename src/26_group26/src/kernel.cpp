extern "C"
{
    #include "libc/print.h"  
    #include "Descriptortables/descript_tables.h"
}

extern "C" int kernel_main(void);

int kernel_main(){
    
    init_descriptor_tables();
    print_string("Hello, World!");

    asm volatile ("int $0x00"); 
    asm volatile ("int $0x1");
    asm volatile ("int $0x31");  

    return 0;
}