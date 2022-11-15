/**
 * @file ctrlC.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 * Write a program in C that prints a message whenever Ctrl + C is pressed
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
    printf("\nCtrl+C\n");
    fflush(stdout);
}

int main()
{
    signal(SIGINT, fun);
    for (;;)
    {
        pause();
    }
    return (0);
}
