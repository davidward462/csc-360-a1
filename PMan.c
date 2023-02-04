#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <stdbool.h>

#define MAX_TOKENS 10

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
	//char *tokenList[20];

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

		// print list
		for(int i = 0; i < tokenCount; ++i)
		{
			printf("[%d]: %s\n", i, tokenList[i]);
		}
	}
	
	return 0;
}

