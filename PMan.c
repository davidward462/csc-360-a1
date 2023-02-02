#include <stdio.h>
#include <string.h>
#include <readline/readline.h>

int main()
{
        char *inpt;
        int i = 0;
        while ( i < 10 )
        {
        	inpt = readline("Enter text: ");
        	printf("%s", inpt);
			printf("\n");
			++i;
        }
        return 0;
}

