#include "libc/print.h"  
extern "C" int kernel_main(void);

int kernel_main(){
    printf("Hello World!");
    return 0;
}