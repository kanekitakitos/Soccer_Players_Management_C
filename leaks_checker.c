//credits to Namam Tamrakar
//source code taken from https://dev.to/namantam1/a-simple-program-to-detect-memory-leak-in-our-c-program-5c5i

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_ALLOCATIONS 100
#define WARN(msg, line) (printf("Warning %d: %s\n", line, msg))

/* 
Data Structure to keep track of memory allocations
*/
typedef struct {
    size_t address;
    size_t size;
    uint32_t line;
} Mem;

struct {
    Mem mem[MAX_ALLOCATIONS];
    size_t total_allocated_size;
    size_t total_free_size;
} data;

/**
 * Find a memory by its address
 * 
 * @return: Pointer to memory
*/
Mem *find_by_address(size_t address) {
    for (uint32_t i=0; i<MAX_ALLOCATIONS; i++) {
        if (data.mem[i].address == address)
            return &data.mem[i]; // as soon as find return
    }

    // otherwise return null
    return NULL;
}


/**
 * insert memory allocated with size
*/
void insert(size_t address, size_t size, uint32_t line) {
    // check for null
    if (address == 0) {
        WARN("Memory allocation failed", line);
        return;
    }

    Mem *mem = find_by_address(0);
    // if the return value is null we need to increase the MAX_ALLOCATIONS value
    if (mem == NULL) {
        WARN("Max allocations reached", line);
        return;
    }

    // save all the allocation info
    mem->address = address;
    mem->size = size;
    mem->line = line;
    data.total_allocated_size += size;
}

/**
 * Remove the memory allocation
 * 
 * @return: -1 on failure else 0
*/
int erase(size_t address, uint32_t line) {
    if (address == 0) {
        WARN("Tried to free a null ptr", line);
        return -1;
    }

    Mem *mem = find_by_address(address);
    // if the address is not found we assume it is already deleted
    if (mem == NULL) {
        WARN("Double free detected", line);
        return -1;
    }

    // set address to null and update info
    mem->address = 0;
    data.total_free_size += mem->size;
    return 0;
}

void print_memory_leak_report() {
    printf("\nLeak Summary\n");
    printf("Total Memory allocated %u bytes\n", data.total_allocated_size);
    printf("Total Memory freed     %u bytes\n", data.total_free_size);
    printf("Memory Leaked          %u bytes\n\n", 
        data.total_allocated_size - data.total_free_size);

    if (data.total_free_size != data.total_allocated_size) {
        printf("Detailed Report\n");
        for (int i=0; i<MAX_ALLOCATIONS; i++) {
            if (data.mem[i].address != 0) {
                printf("Memory leak at line %d: (%u bytes)\n", 
                    data.mem[i].line,
                    data.mem[i].size);
            }
        }
    }
}

// Override allocation functions
void *_malloc(size_t size, uint32_t line) {
    void *ptr = malloc(size);

    // insert to memory data
    insert((size_t)ptr, size, line);

    return ptr;
}

void _free(void *ptr, uint32_t line) {
    // erase memory data
    if (erase((size_t)ptr, line) == 0)
        free(ptr);
}
