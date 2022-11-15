/**
 * @file signal_behaviour.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 * Write a program in C to show the behaviour of different signals SIGINT,SIGTERM and SIGKILL
 * and execute in handler externally from the command prompt.
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

// Source Code
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void fun(int s)
{
    if (s == SIGINT)
    {
        printf("\nSIGINT is called\n");
    }
    if (s == SIGTERM)
    {
        printf("\n SIGTERM is called\n");
    }
    if (s == SIGKILL)
    {
        printf("\n SIGKILL  is called\n");
    }
    fflush(stdout);
}

int main()
{
    signal(SIGINT, fun);
    signal(SIGTERM, fun);
    signal(SIGKILL, fun);
    for (;;)
        pause();
    return 0;
}

/**
 * Output:-
 * Terminal 1:-
 * ~$ gcc signal_behaviour.c -o signal3.out
 * ~$ ./signal3.out
 * Terminal 2:-
 * ~$ ps -e| grep "signal3.out"
 * 41508 pts/0 00:00:00 signal3.out
 * ~$ kill -s SIGINT 41508
 */