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

void PrintList(struct node *head)
{
    printf("head->");
    struct node *current = head;
    while(current->next !=NULL)
    {
        printf("n->");
        current = current->next;
    }
    if(current->next == NULL)
    {
        printf("NULL\n");
    }
}

struct node* CreateListHead(pid_t pid)
{
    //struct node head = {pid, NULL};
    struct node *head;
    head = malloc(sizeof(struct node));
    head->pid = pid;
    head->next = NULL;

    return head;
}

