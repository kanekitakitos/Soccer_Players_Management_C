#include <stdint.h>
// Override allocation functions
void *_malloc(size_t size, uint32_t line);
void _free(void *ptr, uint32_t line);

void print_memory_leak_report();

// redefine allocator functions
#define malloc(size) _malloc(size, __LINE__)
#define free(ptr) _free(ptr, __LINE__)