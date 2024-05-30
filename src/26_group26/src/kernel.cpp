extern "C"
{
    #include "libc/print.h"  
    #include "Descriptortables/descript_tables.h"
    #include "Descriptortables/pit.h"
    #include "libc/memory.h"
}

extern "C" int kernel_main(void);
void* operator new(size_t size) {
    return malloc(size);
}

void* operator new[](size_t size) {
    return malloc(size);
}

// Existing global operator delete overloads
void operator delete(void* ptr) noexcept {
    free(ptr);
}

void operator delete[](void* ptr) noexcept {
    free(ptr);
}

// Add sized-deallocation functions
void operator delete(void* ptr, size_t size) noexcept {
    (void)size; // Size parameter is unused, added to match required signature
    free(ptr);
}

void operator delete[](void* ptr, size_t size) noexcept {
    (void)size; // Size parameter is unused, added to match required signature
    free(ptr);
}
extern uint32_t end;
int kernel_main(){
  
    init_descriptor_tables();
    init_paging();
    init_pit();
    init_kernel_memory(&end);
    
    print_memory_layout();
    void* some_memory = malloc(12345); 
    void* memory2 = malloc(54321); 
    void* memory3 = malloc(13331);
    char* memory4 = new char[1000]();
    asm volatile("sti");
    printf("Hello, World!");
    printf("\n");
    asm volatile ("int $0x0");
    printf("\n");
    asm volatile ("int $0x1");
    printf("\n");
    asm volatile ("int $0x1F"); 
    printf("\n");
    int counter = 0;
    while(true){
        printf("[%d]: Sleeping with busy-waiting (HIGH CPU).", counter);
        printf("\n");
        sleep_busy(1000);
        printf("[%d]: Slept using busy-waiting.\n", counter++);

        printf("[%d]: Sleeping with interrupts (LOW CPU).\n", counter);
        sleep_interrupt(1000);
        printf("[%d]: Slept using interrupts.\n", counter++);
 };
 
    while(1){}
    return 0;
}