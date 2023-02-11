#include <stdio.h>
#include <unistd.h>             
#include <stdlib.h>             //exit(), etc 
#include <string.h>             // strok(), etc
#include <readline/readline.h>  // getting user input
#include <stdbool.h>            // boolean types
#include <sys/types.h>
#include "linkedlist.h"

// preprocessor definitions
#define MAX_TOKENS 10
#define MAX_CMD_LEN 80

// for testing
void run()
{
    const char *a = "";
    char *list[] = {"", NULL};
    pid_t pid = execvp("ls", list);
}

// return true if the strings match, false otherwise.
bool StrMatch(char *a, const char *b)
{
    int compare;
    compare = strncmp(a, b, MAX_CMD_LEN);
    if(compare == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// bg
// Create background process
void bg(struct node *head, char *args[]) // TODO: pass other arguments the user may have entered
{
    char *command = args[1];
    char *list[] = {args[2], NULL};

    printf("\tcommand = %s\n\tlist[0] = %s\n", command, list[0]);

    // create background process
    pid_t pid = execvp(command, list);

    head = AddFront(head, pid);
    
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

    head = CreateEmptyList();

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
		if(StrMatch(tokenList[0], str_exit))
		{
			exit(EXIT_SUCCESS);	
		}
		else if(StrMatch(tokenList[0], str_bg)) // bg
		{
			bg(head, tokenList);
            //run();
		}
		else if(StrMatch(tokenList[0], str_bglist)) // bglist
		{
			bglist(head);
		}
		else if(StrMatch(tokenList[0], str_bgkill)) // bgkill
		{
			bgkill();
		}
		else if(StrMatch(tokenList[0], str_bgstop)) // bgstop
		{
			bgstop();
		}
		else if(StrMatch(tokenList[0], str_bgstart)) // bgstop
		{
			bgstart();
		}
		else if(StrMatch(tokenList[0], str_pstat))// bgstop
		{
			pstat();
		}
        else if((StrMatch(tokenList[0], "")) || (StrMatch(tokenList[0], " ")) || (StrMatch(tokenList[0], "\n")))
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
