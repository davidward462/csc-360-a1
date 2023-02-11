#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "helper.h"

void run()
{
    char *list[] = {NULL};
    pid_t pid = execvp("ls", list);
}

void PrintCharArray(char *a[], int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%s ", a[i]); // can cause indexOutOfBounds error 
    }
    printf("\n");
}

int StrMatch(char *a, const char *b, int length)
{
    int compare;
    compare = strncmp(a, b, length);
    if(compare == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
