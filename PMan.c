#include <stdio.h>
#include <unistd.h>             
#include <stdlib.h>             //exit(), etc 
#include <string.h>             // strok(), etc
#include <readline/readline.h>  // getting user input
#include <stdbool.h>            // boolean types
#include <sys/types.h>

// files needed for linked list
#include "linkedlist.h"

#define MAX_TOKENS 10
#define MAX_CMD_LEN 80

// ---- functions just for testing ----
// remove later

bool IsNullTerminated(char* s)
{
    return false;
}

// ------------------------------

// bg
void bg()
{
	printf("\trun bg\n");
}

// bglist
void bglist()
{
	printf("\trun bglist\n");
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
	char *tokenList[MAX_TOKENS]; // array of pointers
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
    //struct node *head = malloc(sizeof(struct node));
    //head = malloc(sizeof(struct node));

    head = CreateListHead(thisPid);

    PrintList(head);

	while(1)
	{
        printf("BEGIN\n\n");
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
		if(strncmp(tokenList[0], str_exit, MAX_CMD_LEN) == 0) // exit
		{
			exit(EXIT_SUCCESS);	
		}
		else if(strncmp(tokenList[0], str_bg, MAX_CMD_LEN) == 0) // bg
		{
			bg();
		}
		else if(strncmp(tokenList[0], str_bglist, MAX_CMD_LEN) == 0) // bglist
		{
			bglist();
		}
		else if(strncmp(tokenList[0], str_bgkill, MAX_CMD_LEN) == 0) // bgkill
		{
			bgkill();
		}
		else if(strncmp(tokenList[0], str_bgstop, MAX_CMD_LEN) == 0) // bgstop
		{
			bgstop();
		}
		else if(strncmp(tokenList[0], str_bgstart, MAX_CMD_LEN) == 0) // bgstop
		{
			bgstart();
		}
		else if(strncmp(tokenList[0], str_pstat, MAX_CMD_LEN) == 0) // bgstop
		{
			pstat();
		}
		else
		{
			printf("command not recognized.\n");
		}


		// print list
		for(int i = 0; i < tokenCount; ++i)
		{
			printf("\t[%d]: %s\n", i, tokenList[i]);
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
