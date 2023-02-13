#include <stdio.h>
#include <unistd.h>

int main()
{
    int run = 1;
    int count = 0;
    while(run)
    {
        if(count == 10) {
            count = 0;
        }
        count++;
    }
}
