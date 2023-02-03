#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <stdbool.h>

#define TOKEN_LEN 20

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
	char *tokenList[5][TOKEN_LEN];
	//char *tokenList[20];

	while(1)
	{
		input = readline("PMan: > ");

		printf("%s", input); // print input for debugging
		token = strtok(input, delimeter); //

		strncpy(*tokenList[0], token, TOKEN_LEN);
		
		printf("%s", *tokenList[0]);
	}
	
	return 0;
}

