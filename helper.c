#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include <unistd.h>
#include "helper.h"

void run()
{
    char *list[] = {NULL};
    pid_t pid = execvp("ls", list);
}

bool StrMatch(char *a, const char *b, int length)
{
    int compare;
    compare = strncmp(a, b, length);
    if(compare == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
