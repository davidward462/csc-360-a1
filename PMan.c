#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>             
#include <stdlib.h>             //exit(), etc 
#include <string.h>             // strok(), etc
#include <readline/readline.h>  // getting user input
#include <stdbool.h>            // boolean types
#include <sys/types.h>

#include "linkedlist.h"
#include "helper.h"

// preprocessor definitions
#define MAX_TOKENS 10
#define MAX_CMD_LEN 80

// bg
// Create background process
void bg(struct node *head, char *args[]) // TODO: pass other arguments the user may have entered
{
    char *command = args[1]; // token after 'bg'
    char *list[] = {args[2], NULL}; // rest of the arguments

    // create background process
    pid_t pid = execvp(command, list);
    printf("execvp() = %d", pid);
    
    pid_t pid_fork = fork(); // create child process
    if(pid < 0) // fork failed
    {
        printf("error: fork failed\n");
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
    printf("\trun bglist\n");
    PrintList(head);
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

int main()
{
    // input setup
	char *input; // from user
	const char *delimeter = " ";
	char *token;
	char *tokenList[MAX_TOKENS] = {"",}; // initialize with empty string
	int tokenCount = 0;

	// commands
	const char *str_bg = "bg";
	const char *str_bglist = "bglist";
	const char *str_bgkill = "bgkill";
	const char *str_bgstop = "bgstop";
	const char *str_bgstart = "bgstart";
	const char *str_pstat = "pstat";
	const char *str_exit = "exit";

    // process management
    pid_t thisPid = getpid();
    
    // create linked list to hold process IDs
    struct node *head;

    head = CreateEmptyList(); // TODO: sort out list management 

    PrintList(head);

	while(1)
	{
		// read input
		input = readline("PMan: > ");
		if (input == NULL)
		{
			break;
		}

		// tokenize input
		for (token = strtok(input, delimeter); token && tokenCount < MAX_TOKENS; token = strtok(NULL, delimeter))
		{
			tokenList[tokenCount++] = token; // store in list
		}		
		// check command
		if(StrMatch(tokenList[0], str_exit, MAX_CMD_LEN))
		{
			exit(EXIT_SUCCESS);	
		}
		else if(StrMatch(tokenList[0], str_bg, MAX_CMD_LEN)) // bg
		{
			bg(head, tokenList);
            //run();
		}
		else if(StrMatch(tokenList[0], str_bglist, MAX_CMD_LEN)) // bglist
		{
			bglist(head);
		}
		else if(StrMatch(tokenList[0], str_bgkill, MAX_CMD_LEN)) // bgkill
		{
			bgkill();
		}
		else if(StrMatch(tokenList[0], str_bgstop, MAX_CMD_LEN)) // bgstop
		{
			bgstop();
		}
		else if(StrMatch(tokenList[0], str_bgstart, MAX_CMD_LEN)) // bgstop
		{
			bgstart();
		}
		else if(StrMatch(tokenList[0], str_pstat, MAX_CMD_LEN))// bgstop
		{
			pstat();
		}
        else if((StrMatch(tokenList[0], "", MAX_CMD_LEN)) || (StrMatch(tokenList[0], " ", MAX_CMD_LEN)) || (StrMatch(tokenList[0], "\n", MAX_CMD_LEN)))
        {
            ; // do nothing
        }
		else
		{   
            // not a known command, the empty string, or newline
            printf("%s: command not recognized.\n", tokenList[0]);
		}

		//clear token list
		for(int i = 0; i < MAX_TOKENS; i++)
		{
			tokenList[i] = "";
		}

		// reset token list
		tokenCount = 0; 
		
	}
	
	return 0;
}
