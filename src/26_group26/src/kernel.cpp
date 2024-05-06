extern "C"
{
    #include "libc/print.h"  
    #include "Descriptortables/descript_tables.h"
}

extern "C" int kernel_main(void);

int kernel_main(){
    
    init_descriptor_tables();
    printf("Hello, World!\n");

    asm volatile ("int $0x0");
    printf("\n");
    asm volatile ("int $0x1");
    printf("\n");
    asm volatile ("int $0x1F");  
    while(1){}
    return 0;
}