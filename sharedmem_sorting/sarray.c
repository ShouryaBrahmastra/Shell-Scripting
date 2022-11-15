/**
 * @file sarray.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

// Source code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
    // create a key
    int shmid = shmget((key_t)1228, 6, IPC_CREAT | 0777);
    // Allocation of the shared memory
    void *memory = shmat(shmid, NULL, 0);
    int *p = (int *)memory;
    // Sorting the array
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {
            if (p[j] > p[j + 1])
            {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\nSuccesfully read and sorted from the shared memory\n\n");
    return 0;
}
