/**
 * @file receiver2.c
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

struct msg_buffer1
{
    char msg1[5];
    int msg_type2;
} message1;

int main(void)
{

    // creating the message queue
    int msgid1 = msgget((key_t)1222, 0666 | IPC_CREAT);

    // reading the message from the queue
    msgrcv(msgid1, &message1, sizeof(message1), message1.msg_type2, 0);

    // printing the received message
    printf("\nData Received is : \n");
    for (int i = 0; i <= 6; i++)
    {
        printf("%c", message1.msg1[i]);
    }

    printf("\n\n");

    return (0);
}
