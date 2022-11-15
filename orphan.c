/**
 * @file orphan.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 * Write a program in C that depicts an orphan process .
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

void ChildProcess(void);  /* child process prototype  */
void ParentProcess(void); /* parent process prototype */

void main(void)
{
    int pid;

    pid = fork();
    if (pid == 0)
        ChildProcess();
    else
        ParentProcess();
}

void ChildProcess(void)
{
    printf("\n");
    sleep(10);
    printf("This is child process");
    printf("PID : %d\n", getpid());
    printf("PPID : %d\n", getppid());
    printf("\n");
}

void ParentProcess(void)
{
    printf("\n");
    printf("This is parent process");
    printf("PID : %d\n", getpid());
    printf("PPID : %d\n", getppid());
    printf("\n");
}
