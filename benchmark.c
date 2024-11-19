#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE (1024*1024) // 1 MB block size
#define NUM_BLOCKS 1000        // Number of blocks to allocate

int main()
{
    void* blocks[NUM_BLOCKS];

    for (int i = 0; i < NUM_BLOCKS; i++)
    {
        blocks[i] = malloc(BLOCK_SIZE);
        if (blocks[i] == NULL)
        {
            fprintf(stderr, "Memory allocation failed at iteration %d\n", i);
            exit(EXIT_FAILURE);
        }
        memset(blocks[i], 0, BLOCK_SIZE);  // Touch the memory
    }

    for (int i = 0; i < NUM_BLOCKS; i++)
    {
        free(blocks[i]);
    }

    printf("Memory stress test completed.\n");
    return 0;
}