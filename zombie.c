/**
 * @file zombie.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 * Write a program in C that depicts a child process to be a zombie process.
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

// Source Code
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int s;

void main(void)
{
    int pid;

    pid = fork();
    if (pid == 0)
    {
        printf("\n");
        printf("This is child process");
        printf("PID : %d\n", getpid());
        printf("PPID : %d\n", getppid());
        exit(10);
        printf("\n");
    }
    else
    {
        printf("\n");
        sleep(10);
        wait(&s);
        printf("This is parent process");
        printf("PID : %d\n", getpid());
        printf("PPID : %d\n", getppid());
        printf("Child has exited with status: %d", WEXITSTATUS(s));
        printf("\n");
    }
}
