#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node
{
    pid_t pid;  // process id number
    long state; // process state
    struct node *next;
};

int ListLength(struct node *head);

void PrintList(struct node *head);

struct node* CreateList(pid_t pid);

struct node* CreateEmptyList();

struct node* AddFront(struct node *head, pid_t pid);

struct node RemoveNode(pid_t pid);

#endif
