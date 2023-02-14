#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>             
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

#include "linkedlist.h"
#include "helper.h"
#include "commands.h"

struct node *head;

// bg
// Create background process
struct node* bg(struct node *head, char *args[]) // TODO: pass other arguments the user may have entered
{
    char *command = args[1]; // token after 'bg'
    
    // TODO: fix temp magic number 80
    if(StrMatch(command, "", 80)) // if no command
    {
       printf("please provide an executable or command\n");
       return head;
    }
    
    char *list[] = {args[2], args[3], args[4], NULL}; // rest of the arguments

    pid_t pid_fork = fork(); // create child process

	// fork failed
    if(pid_fork < 0)
    {
        printf("error: fork failed\n");
        return head;
    }   
    else if(pid_fork == 0) // child process created, child gets pid of 0 from fork()
    {   
        // execute command
        if(execvp(command, list) < 0)
        {
            printf("execution of %s failed\n", command);
            exit(1);
        }
    }
    else // pid > 0, parent process, parent gets child's pid as pid from fork()
    {
        // add child process to list
        head = AddFront(head, pid_fork);
        DetailPrintList(head); // for testing
        sleep(1);
    }
    return head;
}

// bglist
void bglist(struct node *head)
{
    // check length
    int listLen = ListLength(head); 
    if(listLen == 0){
        printf("There are no background jobs\n");
        return;
    }

    DetailPrintList(head); // main print

    printf("Total background jobs: %d\n", listLen);
} 

// bgkill
void bgkill(struct node *head, pid_t pid)
{   
    //pid_t pid = atoi(args[1]);
    RemoveNode(head, pid);
    kill(pid, SIGTERM); // TODO: make this kill the pid that is passed
}

// bgstop
void bgstop()
{
}

// bgstart
void bgstart()
{
}

// pstat
void pstat()
{
}

void killall(struct node *head)
{
    // kill all processes in list
    pid_t pid;
    struct node *current = head;
    while(current != NULL)
    {
        pid = current->pid;
        kill(pid, SIGTERM);
        current = current->next;
    }

}
