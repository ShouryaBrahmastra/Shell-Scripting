/**
 * @file unamed_pipe_calculation.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 * Create an unnamed pipe to communicate between parent process and child process. Use the pipe to send 2 integers x & y (user input) from child process to its parent process. Calculate x^y in parent process & send it to child process. Print the result in child process.
 * Input :
 * 1st line is an integer which is the base (x).
 * 2nd line is an integer which is the power (y).
 * Output:
 * An integer (x^y)
 * Example:
 * Input :5
 * 3
 * Output:125
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

int main()
{
    int v, i, temp[3];
    temp[2] = 1;

    int fd[2];
    pipe(fd);

    printf("Enter the base : \n");
    scanf("%d", &temp[0]);
    printf("Enter the power : \n");
    scanf("%d", &temp[1]);

    v = fork();

    if (v == 0)
    {

        printf("Child Process: \n");
        write(fd[1], temp, sizeof(temp));
        sleep(5);
        read(fd[0], temp, sizeof(temp));
        printf("\nThe value is : %d \n ", temp[2]);
    }
    else
    {

        read(fd[0], temp, sizeof(temp));

        for (i = 1; i <= temp[1]; i++)
        {
            temp[2] = temp[2] * temp[0];
        }

        write(fd[1], temp, sizeof(temp));
    }

    return 0;
}
