/**
 * @file un_named_pipe.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 * Create an unnamed pipe to communicate between parent/child process. Accept a string (user input )
 * in the program such that the child process pass the string to parent process  will print it out to
 * verify the same.
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

// Source Code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    int fd[2]; // 2 end of the pipe
    pipe(fd);

    char str[50], str1[50];
    printf("Enter the String:\n");
    for (int i = 0; i < 18; i++)
    {
        scanf("%c", &str[i]);
    }

    int f = fork();

    if (f == 0) // child process
    {
        printf("\n");
        write(fd[1], str, sizeof(str));
        close(fd[0]);
        printf("\n");
    }
    else // parent process
    {
        printf("\n");
        printf("Parent Process\n");
        read(fd[0], str1, sizeof(str1));
        printf("%s", str1);
        close(fd[1]);
        printf("\n");
    }
    return 0;
}
