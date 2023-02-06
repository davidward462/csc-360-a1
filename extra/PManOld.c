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
	char buffer[80]; // for temporary string storage
	while (running)
	{
		input = readline("PMan: > ");
		printf("%s\n", input);

		/**
		if(strcmp(input, "\0"))
		{
			input = "";
		}**/

	    // tokenize input
        char *token =  strtok(input, delim); // get first token
        printf("token: %s", token);
        //strcpy(buffer, token); // seg fault
        //strcpy(tokenList[tokenListIndex], token); // causes seg fault

	    while(token != NULL)
	    { // while there is another token

			//strcpy(tokenList[tokenListIndex++], token); // store token
			
		    token = strtok(NULL, delim); // why?
	    }
	}
	
	return 0;
}

