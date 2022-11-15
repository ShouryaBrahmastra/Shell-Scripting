/**
 * @file receiver.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
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

int main(void)
{

    // creating the message queue
    int msgid = msgget((key_t)1228, 0666 | IPC_CREAT);

    // reading the message from the queue
    msgrcv(msgid, &message, sizeof(message), message.msg_type, 0);

    // printing the received message
    printf("\nData Received is : \n");
    for (int i = 0; i <= 5; i++)
    {
        printf("%c", message.msg[i]);
    }

    printf("\n\n");

    return (0);
}
