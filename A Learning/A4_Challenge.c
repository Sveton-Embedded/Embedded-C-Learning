#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#define POOL_SIZE 1024

static uint8_t memoryPool[POOL_SIZE];
static size_t poolOffset = 0; 

void* pool_alloc(size_t size)
{
    if (poolOffset + size > POOL_SIZE)
    {
        return NULL;
    }

    void *ptr = &memoryPool[poolOffset];
    poolOffset += size;

    return ptr;
}

int main(void)
{
    int *a = pool_alloc(sizeof(int));
    int *b = pool_alloc(sizeof(int));

    *a = 100;
    *b = 200;

    printf("a = %d, b = %d\n", *a, *b);
    printf("poolOffset now = %zu\n", poolOffset);   

    return 0;
}