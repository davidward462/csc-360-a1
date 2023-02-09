#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node
{
    pid_t pid;
    struct node *next;
};

void PrintList(struct node *head);

struct node* CreateListHead(pid_t pid);

struct node* AddFront(struct node *head, pid_t pid);

struct node RemoveNode(pid_t pid);



#endif
