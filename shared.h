#ifndef SHARED_MEM_H
#define SHARED_MEM_H

#include <stdbool.h>

char * attach_memory_block(char *filename, int size);
bool detach_memory_block(char *block);
bool destroy_memory_block(char *filename);


#define BLOCK_SIZE 4096
#define FILENAME "writemem.c"

#define SEM_PRODUCER_FRAME "/producer"
#define SEM_CONSUMER_FRAME "/consumer"

#endif