#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//typedef struct node node;

void checklink(); // remove later

struct node* CreateListHead(pid_t pid);

struct node AddFront(pid_t pid);

struct node RemoveNode(pid_t pid);



#endif
