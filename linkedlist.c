#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "linkedlist.h"

void PrintList(struct node *head)
{
    printf("head->");
    struct node *current = head; // address of current node
    while(current->next !=NULL) // there are other nodes in the list
    {
        printf("n->");
        current = current->next; // increment
    }
    if(current->next == NULL) // if there isn't a next
    {
        printf("NULL\n");
    }
}

// params: process id
// returns: address of head of new list
struct node* CreateListHead(pid_t pid)
{
    struct node *head; // declare 

    // allocate memory for struct
    head = malloc(sizeof(struct node));
    
    // assign data
    head->pid = pid;
    head->next = NULL;

    return head; // address to a struct
}

// params: process id, address of head of list
struct node* AddFront(struct node *head, pid_t pid)
{
    struct node *listNext = head->next;

    struct node *n; // declare node to be inserted

    // allocate memory
    n = malloc(sizeof(struct node));

    // assign data
    n->pid = pid;
    n->next = listNext;

    return n;
}

