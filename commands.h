#ifndef COMMANDS_H
#define COMMANDS_H

//struct node *head;

struct node* bg(struct node *head, char *args[]);

void bglist(struct node *head);

void bgkill(struct node *head, pid_t pid);

void bgstop();

void bgstart();

void pstat();

void killall(struct node *head);

#endif
