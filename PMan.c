#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <stdbool.h>

// bg

// bglist

// bgkill

// bgstop

// bgstart

// pstat

int main()
{
	char *input;
	bool running = true;
	const char delim[1] = " ";
	char *tokenList[80]; // array of addresses to chars
	int tokenListIndex = 0;
	while (running)
	{
		input = readline("PMan: > ");
		printf("%s\n", input);

	    // tokenize input
        char *token =  strtok(input, delim); // get first token
        strcpy(tokenList[tokenListIndex], token);// store first token (the main command) here

	    while(token != NULL)
	    { // while there is another token

		    //printf("in while");
		    printf("%s\n", token);
		    token = strtok(NULL, delim); // why?
	    }
	}
	
	return 0;
}

