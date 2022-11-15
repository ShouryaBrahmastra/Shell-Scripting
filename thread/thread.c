/**
 * @file thread.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 * Write a program in C which calls sub-routinein thread which print the value of count from 1 to 10
 * after the main program ends. Try to analysis the flow of the program.
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

// Source code
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *fun(void *p)
{
    int i = 1;
    printf("\n Thread function starts\n");

    while (i <= 10)
    {
        printf("\n Value of count = %d", i);
        i++;
        // sleep(1);
    }
    printf("\nThread function ends\n");
}

int main()
{
    int a;
    pthread_t th; // data type declared
    printf("\nMain is started\n");
    a = pthread_create(&th, NULL, fun, NULL);
    if (a != 0)
    {
        printf("\nThread not created\n");
    }

    // sleep(20);
    printf("\nMain ends here\n");
    return (0);
}
