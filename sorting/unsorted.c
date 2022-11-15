/**
 * @file unsorted.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 * Use a named pipe (FIFO) to send an array of integers from a process P1 to another process P2. The process P2, after receiving the array, will sort the array & send back to P1. P1 will print the sorted array.
 * [ Hints:
 * 1. Please refer  to the manual page of mkfifo() , open() , write(), read() , unlink()
 * 2.  Execute the programs using two separate terminals. ]
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
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(void)
{
    int a, b, z, size, f, arr[6], arr1[6];
    unlink("/home/student/pipe_transfer2");
    a = mkfifo("/home/student/pipe_transfer2", 0777);

    // Taking Array from the user
    printf("\nEnter the array : \n");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &arr[i]);
    }

    f = open("/home/student/pipe_transfer2", O_RDWR);
    z = write(f, arr, sizeof(arr));

    sleep(5);

    b = read(f, arr1, sizeof(arr1));

    // Printing the sorted array
    size = b / sizeof(int);

    printf("Sorted Array is : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr1[i]);
    }

    printf("\n");
    return 0;
}
