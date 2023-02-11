#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>             
#include <stdlib.h>
#include <sys/types.h>
#include "commands.h"
#include "linkedlist.h"
#include "helper.h"

struct node *head;

// bg
// Create background process
void bg(struct node *head, char *args[]) // TODO: pass other arguments the user may have entered
{
    char *command = args[1]; // token after 'bg'
    printf("command:%s|<-", command); //for testing

    // TODO: fix temp magic number 80
    if(StrMatch(command, "", 80)) // TODO: fix seg fault on entry "bg "
    {
       printf("error: please provide a command\n");
       return;
    }
    char *list[] = {args[2], NULL}; // rest of the arguments

    // create background process
    pid_t pid = execvp(command, list);
    printf("execvp() = %d", pid);
    
    pid_t pid_fork = fork(); // create child process
    if(pid < 0) // fork failed
    {
        printf("error: fork failed\n");
        return;
    }

    if(pid != 0) // parent process
    {
        // might use different arguments later
        waitpid(-1, NULL, WNOHANG); // wait for child to terminate
    }

    head = AddFront(head, pid); // where should this go?
    
}

// bglist
void bglist(struct node *head)
{
    // temporary
    PrintList(head);
    //struct node *current = head;
} 

// bgkill
void bgkill()
{
	printf("\trun bgkill\n");
}

// bgstop
void bgstop()
{
	printf("\trun bgstop\n");
}

// bgstart
void bgstart()
{
	printf("\trun bgstart\n");
}

// pstat
void pstat()
{
	printf("\trun pstat\n");
}