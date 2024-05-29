#include "libc/system.h"
#include "libc/print.h"

__attribute__((noreturn)) void panic(const char*);
void* _impure_ptr = NULL;


void __stack_chk_fail_local()
{
    panic("Stack protector: Canary modified");
    __builtin_unreachable();
}
__attribute__((used))
void __stack_chk_fail()
{
    panic("Stack protector: Canary modified");
    __builtin_unreachable();
}

void _exit(int status)
{
    char buffer[64] = {};
    printf("Exit called with status");
    panic(buffer);
    __builtin_unreachable();
}

