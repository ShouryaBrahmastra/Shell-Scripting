/**
 * @file shared2.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

// Source Code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{

    // create a key
    int shmid = shmget((key_t)1244, 6, IPC_CREAT | 0777);
    // Allocation of the shared memory
    void *memory = shmat(shmid, NULL, 0);
    char *p = (char *)memory;

    printf("%s", p);

    printf("\n");
    return 0;
}
