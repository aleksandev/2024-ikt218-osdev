extern "C"
{
    #include "libc/print.h"  
    #include "Descriptortables/idt.h"
    #include "Descriptortables/gdt.h"
}

extern "C" int kernel_main(void);

int kernel_main(){
    printf("Hello World!");


    //init_gdt();
    init_gdt();
    init_idt();

    return 0;
}