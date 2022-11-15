/**
 * @file shared1.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 * Write a program in C to pass a string  using a shared memory by program 1 and program2
 * will read the content of shared memory  an print the same to verify it.
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
    int n;
    printf("\nEnter the length of the string: \n");
    scanf("%d", &n);
    char *str = (char *)malloc(n * sizeof(str));

    printf("Enter the String: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &str[i]);
    }

    // create a key
    int shmid = shmget((key_t)1244, 6, IPC_CREAT | 0777);
    // Allocation of the shared memory
    void *memory = shmat(shmid, NULL, 0);
    char *p = (char *)memory;

    memset(p, 20, '\0');
    memcpy(p, str, strlen(str));

    printf("\n");
    return 0;
}
