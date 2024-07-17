#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <fcntl.h>
#include <pthread.h>

#include <sys/types.h>
#include <sys/ipc.h>    
#include <sys/sem.h>
#include <sys/stat.h>

#include "shared.h"

#define putchar(c)  putc((c), stdout)

int main (int argc, char *argv[]) 
{
    if (argc !=1)
    {
        printf("usage - %s // no args",argv[0]);
        return -1;
    }

    sem_unlink(SEM_CONSUMER_FRAME);
    sem_unlink(SEM_PRODUCER_FRAME); 

    sem_t *sem_prod = sem_open(SEM_PRODUCER_FRAME, IPC_CREAT, 0660, 0);
    if (sem_prod == SEM_FAILED)
    {
        perror("sem_open/producer");
        exit(EXIT_FAILURE);
    }

    sem_t *sem_cons = sem_open(SEM_CONSUMER_FRAME, IPC_CREAT, 0660, 1);
    if (sem_cons == SEM_FAILED)
    {
        perror("sem_open/consumer");
        exit(EXIT_FAILURE);
    }

    char *block = attach_memory_block(FILENAME, BLOCK_SIZE);
    if (block == NULL)
    {
        printf("ERROR: couldn't get block\n");
        return -1;
    }

    while (true)
    {
        sem_wait(sem_prod);
        if (strlen(block)>0)
        {
            printf("Reading: \"%s\"\n", block);
            bool done = (strcmp(block, "quit")==0);
            block[0] = 0;
            if (done) {break;}
        }
    }

    sem_close(sem_cons);
    sem_close(sem_prod);    
    detach_memory_block(block);
    return 0;
}