/**
 * @file alarm_msg.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 * Write a program in C that gives an alarm message after every two nano seconds and will give
 * these messages untill the counter reaches 10.
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

// Source code
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void fun(int signum)
{
    printf("\nAlarm\n");
    alarm(2);
    fflush(stdout);
}

int main()
{
    int count = 0;
    signal(SIGALRM, fun);
    alarm(2);
    while (1)
    {
        count++;
        pause();
        printf("count= %d\n", count);
        if (count >= 10)
        {
            break;
        }
    } // while ends
    return (0);
}
