#include <stdio.h>
#include <sys/types.h>
#include "linkedlist.h"

struct node {
    pid_t pid;
    struct node *next;
};

struct node* CreateListHead(pid_t pid)
{
    // create struct for head
    struct node head = {pid, NULL};
    // allocate memory with malloc somehow
    // assign data
    // return address to this new struct called head

    return &head;
}

