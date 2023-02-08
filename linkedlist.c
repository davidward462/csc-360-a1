#include <stdio.h>
#include <sys/types.h>
#include "linkedlist.h"

struct node {
    pid_t pid;
    struct node *next;
};

void checklink()
{
    printf("linkedlist.c is linked\n");
}

struct node* CreateListHead(pid_t pid)
{
    // create struct for head
    // allocate memory with malloc somehow
    // assign data
    // return address to this new struct called head

    return NULL;
}

