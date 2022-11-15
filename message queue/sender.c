/**
 * @file sender.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 * Write a C program in which the string is passed by the 1st program to the message queue & is read
 * by the second program to verify the content.
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */

// Source Code
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer
{
    char msg[5];
    int msg_type;
} message;

struct msg_buffer1
{
    char msg1[5];
    int msg_type1;
} message1;

int main(void)
{

    // creating the message queue
    int msgid = msgget((key_t)1228, 0666 | IPC_CREAT);

    // transfering the message
    message.msg_type = 1;

    printf("\nEnter the message: \n");
    for (int i = 0; i <= 5; i++)
    {
        scanf("%c", &message.msg[i]);
    }

    msgsnd(msgid, &message, sizeof(message), 0);

    // For 2nd message

    // creating the message queue
    int msgid1 = msgget((key_t)1222, 0666 | IPC_CREAT);

    // transfering the message 2
    message.msg_type = 2;

    printf("\nEnter the message: \n");
    for (int i = 0; i <= 6; i++)
    {
        scanf("%c", &message1.msg1[i]);
    }

    msgsnd(msgid1, &message1, sizeof(message1), 0);

    /*
    //Printing the message after taking it from the user
    printf("\nPrinting the message after taking it from the user: \n");
    for(int i=0;i<=5;i++)
    {
        printf("%c",message.msg[i]);
    }*/
    printf("\n");

    return (0);
}
