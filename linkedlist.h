#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node
{
    pid_t pid;
    struct node *next;
};

struct node* CreateListHead(pid_t pid);

struct node AddFront(pid_t pid);

struct node RemoveNode(pid_t pid);



#endif
