/**
 * @file sorted.c
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
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(void)
{
    int a, z, f1, arr1[6];

    f1 = open("/home/student/pipe_transfer2", O_RDWR);
    z = read(f1, arr1, sizeof(arr1));

    // Sorting the array
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {
            if (arr1[j] > arr1[j + 1])
            {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }

    z = write(f1, arr1, sizeof(arr1));
    sleep(1);

    printf("\nPipe read successfully\n \n");

    return 0;
}
