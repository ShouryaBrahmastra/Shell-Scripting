/**
 * @file thread_roundrobin.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 * Write a program in C in which 2 threads are created and different values are called on
 * created thread. Set the scheduling policies as Round-Robin. For each thread called, it prints
 * and increments the value of the counter infinite number of times. Check the output and try to
 * synchronize.
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
#include <stdlib.h>
#include <semaphore.h>
int c = 10, counter = 0, c1, c2;
int tmp1, tmp2;
sem_t mutex;
int sem_tupe = 0, sm = 1;

void *fun(void *p)
{
    while (1)
    {
        counter++;
        sem_wait(&mutex);
        tmp1 = rand();
        c1 = tmp1 + c;
        c2 = tmp1 - c;
        sem_post(&mutex);
        if (c1 - c2 != 2 * c)
            break;

        printf("\nThread %d in CS, c1 = %d c2 = %d \n", *(int *)p, c1, c2);
    }
    printf("\nLoop breaks in iteration %d c1 = %d c2 = %d \n", counter, c1, c2);
}

int main()
{
    pthread_t th1, th2;
    int a = 1, b = -1;
    pthread_attr_t att;
    pthread_attr_init(&att);
    pthread_attr_setschedpolicy(&att, SCHED_RR);
    sem_init(&mutex, sem_type, sm);
    pthread_create(&th1, &att, (void *)fun, (void *)&a);
    pthread_create(&th2, &att, (void *)fun, (void *)&b);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    sem_destroy(&mutex);
    return (0);
}
