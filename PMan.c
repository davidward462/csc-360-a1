#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <stdbool.h>

int main()
{
	char *inpt;
	bool running = true;
	while (running)
	{
		inpt = readline("PMan: > ");
		printf("%s", inpt);
		printf("\n");
	}
	return 0;
}

