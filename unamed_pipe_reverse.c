/**
 * @file unamed_pipe_reverse.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 * 2 Create an unnamed pipe to communicate between parent process and child process. Accept a string (user input ) in child process and pass the string to parent process which will reverse that and send it back to child process and the child process will print it out.
 * Input is a string
 * Output is a string ( reverse to the given string )
 * Example:
 * Input : Operating_System
 * Output : metsyS_gnitarepO
 *
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
        printf("Child Process \n");
        write(fd[1], str, sizeof(str));
        sleep(5);
        read(fd[0], str, sizeof(str));
        printf("%s", str);
        close(fd[0]);
        printf("\n");
    }
    else // parent process
    {
        printf("\n");
        read(fd[0], str1, sizeof(str1));
        int i = 0, j = 17;
        while (i < j)
        {
            char temp = str1[i];
            str1[i] = str1[j];
            str1[j] = temp;
            i++;
            j--;
        }
        write(fd[1], str1, sizeof(str1));
        close(fd[1]);
        printf("\n");
    }
    return 0;
}
