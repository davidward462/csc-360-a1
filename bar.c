#include <stdio.h>
#include <unistd.h>

int main()
{
    int count = 0;
    int maxTime = 60;
    while(count < maxTime)
    {
        count++;
        sleep(1);
    }
}
