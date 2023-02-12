#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>             
#include <stdlib.h>
#include <sys/types.h>
#include "linkedlist.h"
#include "helper.h"
#include "commands.h"

struct node *head;

// bg
// Create background process
void bg(struct node *head, char *args[]) // TODO: pass other arguments the user may have entered
{
    char *command = args[1]; // token after 'bg'
    
    // TODO: fix temp magic number 80
    if(StrMatch(command, "", 80)) // if no command
    {
       printf("please provide an executable or command\n");
       return;
    }
    
    char *list[] = {args[2], args[3], args[4], NULL}; // rest of the arguments
    
    pid_t pid_fork = fork(); // create child process
    if(pid_fork < 0) // fork failed
    {
        printf("error: fork failed\n");
        return;
    }   
    else if(pid_fork == 0) // child process
    {
        // execute background command
        execvp(command, list);
    }
    else // parent process
    {
        // might use different arguments later
        waitpid(-1, NULL, 0); // wait for child to terminate
        //wait(NULL);
    }

    head = AddFront(head, pid_fork); // where should this go?
    
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
