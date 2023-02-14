#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "linkedlist.h"

// return the number of nodes in a linked list pointed to by head
int ListLength(struct node *head)
{
    struct node *current = head;
    int count = 0;
    while(current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void PrintList(struct node *head)
{
    printf("head-> ");
    struct node *current = head; // address of current node
    while(current !=NULL) // while we have not finished the list
    {
        printf("%d-> ", current->pid);
        current = current->next; // increment
    }

    if(current == NULL) // end of list
    {
        printf("NULL\n");
    }
}

// this will produce most of the output for bglist
void DetailPrintList(struct node *head)
{
    struct node *current = head;
    while(current != NULL) // while we have not finished the list
    {
        printf("%d: ", current->pid);
        current = current->next;
    }

    // if current is NULL, we are done
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

struct node* AddFront(struct node *head, pid_t pid)
{
    //printf("add front\n");

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

struct node* RemoveNode(struct node *head, pid_t pid)
{
    pid_t pidCurr;
    struct node *current = head;
    struct node *prev = head;

    while(current != NULL)
    {
        pidCurr = current->pid; // get pid
        if(pidCurr == pid) // if found
        {
            prev->next = current->next; // rewire
            free(current);
        }
	}
            
    return head;
}

