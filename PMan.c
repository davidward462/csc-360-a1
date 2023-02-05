#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <stdbool.h>

#define MAX_TOKENS 10
#define MAX_CMD_LEN 80

// bg

// bglist

// bgkill

// bgstop

// bgstart

// pstat

int main()
{
	char *input; // from user
	const char *delimeter = " ";
	char *token;
	char *tokenList[MAX_TOKENS]; // array of pointers
	int tokenCount = 0;

	// commands
	const char *bg = "bg";
	const char *bglist = "bglist";
	const char *bgkill = "bgkill";
	const char *bgstop = "bgstop";
	const char *bgstart = "bgstart";
	const char *pstat = "pstat";
	const char *quit = "quit";

	
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
		if(strncmp(tokenList[0], quit, MAX_CMD_LEN) == 0)
		{
			exit(EXIT_SUCCESS);	
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