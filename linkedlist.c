#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "linkedlist.h"

int ListLength(struct node *head)
{
    return 0;
}

void PrintList(struct node *head)
{
    printf("----------\nhead\n");
    struct node *current = head; // address of current node
    while(current !=NULL) // there are other nodes in the list
    {
        printf("%d\n", current->pid);
        current = current->next; // increment
    }

    if(current == NULL)
    {
        printf("NULL\n----------\n");
    }
}

// create linked list with one node
// params: process id
// returns: address of head of new list
struct node* CreateList(pid_t pid)
{
    struct node *head; // declare 

    // allocate memory for struct
    head = malloc(sizeof(struct node));
    
    // assign data
    head->pid = pid;
    head->next = NULL;

    return head; // address to a struct
}

// create linked list with no nodes
struct node* CreateEmptyList()
{
    struct node *head;
    head = NULL;
    return head;
}

// params: process id, address of head of list
struct node* AddFront(struct node *head, pid_t pid)
{
    printf("add front\n");

    // head is not a node, its a pointer to the fist node
    struct node *listNext = head;

    struct node *n; // declare node to be inserted

    // allocate memory
    n = malloc(sizeof(struct node));

    // assign data
    n->pid = pid;
    n->next = listNext;

    head = n;

    return head; // head of list is updated
}

