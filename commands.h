#ifndef COMMANDS_H
#define COMMANDS_H

struct node *head;

void bg(struct node *head, char *args[]);

void bglist(struct node *head);

void bgkill(struct node *head, char *args[]);

void bgstop();

void bgstart();

void pstat();

#endif
