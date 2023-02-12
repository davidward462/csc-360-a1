#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>             
#include <stdlib.h>             //exit(), etc 
#include <string.h>             // strok(), etc
#include <readline/readline.h>  // getting user input
#include <sys/types.h>

#include "linkedlist.h" // linked list
#include "helper.h"     // misc and debugging
#include "commands.h"   // bg, bglist, etc

// preprocessor definitions
#define MAX_TOKENS 10
#define MAX_CMD_LEN 80

int main()
{
    // input setup
	char *input; // from user
	const char *delimeter = " ";
	char *token;
	char *tokenList[MAX_TOKENS] = {""};
	int tokenCount = 0;

    // fill list
	for(int i = 0; i < MAX_TOKENS; i++)
	{
		tokenList[i] = "";
	}
	tokenCount = 0; 

	// commands
	const char *str_bg = "bg";
	const char *str_bglist = "bglist";
	const char *str_bgkill = "bgkill";
	const char *str_bgstop = "bgstop";
	const char *str_bgstart = "bgstart";
	const char *str_pstat = "pstat";
	const char *str_exit = "exit";

    // root process for pman
    pid_t pmanPid = getpid();
    
    // create linked list to hold process IDs
    struct node *head;
    head = CreateEmptyList();
    head = AddFront(head, pmanPid); // add root process

    // Main loop
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


        PrintCharArray(tokenList, MAX_TOKENS); 

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
            // not a known command, empty string, spance, or newline
            printf("%s: command not found\n", tokenList[0]);
		}

		
		//clear token list
		for(int i = 0; i < MAX_TOKENS; i++)
		{
			tokenList[i] = "";
		}
		tokenCount = 0; 
	}
	
	return 0;
}
