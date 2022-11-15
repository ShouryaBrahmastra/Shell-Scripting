/**
 * @file multithread.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 * Write a program in C that creates 5 threads & each thread calls a function individually & prints
 * the parameter for which it is called.
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

// Source Code
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *fun(void *p)
{
    long tid;
    tid = (long)p;
    printf("Thread called id  = %ld\n", tid);
    pthread_exit(NULL);
}

int main()
{
    int a;
    pthread_t th[5]; // data type declared
    printf("\nMain is started\n");
    for (long i = 0; i < 5; i++)
    {
        a = pthread_create(&th[i], NULL, fun, (void *)i);
        if (a != 0)
        {
            printf("\nThread not created\n");
        }
        // pthread_join(th[i],NULL); //controlling the order of execution
    }
    sleep(20);
    printf("\nMain ends here\n");
    return (0);
}
