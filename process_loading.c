/**
 * @file process_loading.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 * Write program using C in Linux to create a process that loads another program as child process.
 * Modify this a with the following flexibilities -- i) the program name is user input & ii) the main
 * process will terminate if user input is "exit".
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

// Source code
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int s;
    char str1[20];
    printf("Enter the filename to be opened: -\n");
    for (int i = 0; i < 7; i++)
    {
        scanf("%c", &str1[i]);
    }
    char *path = "/home/student/";

    int id = fork();

    if (id = 0)
    {
        strcat(path, str1);
        execlp(path, str1, NULL);
    }
    else
    {
        wait(&s);
        printf("Child has executed with exit status: %d\n", WEXITSTATUS(s));
    }
}
