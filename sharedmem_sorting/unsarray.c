/**
 * @file unsarray.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 * Write a program in C in which an array of elements is supplied by user and is written into the
 * shared memory by one program and another program sorts the content after which the first program
 * will print the sorted array.
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

// Source code

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
    int n;
    printf("\nEnter the length of the array: \n");
    scanf("%d", &n);
    int arr[n + 1];

    // Taking Array from the user
    printf("\nEnter the array elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // create a key
    int shmid = shmget((key_t)1228, 6, IPC_CREAT | 0777);
    // Allocation of the shared memory
    void *memory = shmat(shmid, NULL, 0);
    int *p = (int *)memory;

    sleep(5);

    // Printing the sorted array
    printf("Sorted Array is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }

    printf("\n");
    return 0;
}
