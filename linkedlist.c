#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "linkedlist.h"

/**
struct node {
    pid_t pid;
    struct node *next;
};
**/

struct node* CreateListHead(pid_t pid)
{
    //struct node head = {pid, NULL};
    struct node *head;
    head = malloc(sizeof(struct node));
    head->pid = pid;
    head->next = NULL;

    return head;
}

