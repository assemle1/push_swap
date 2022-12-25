#include <stdio.h>

int main()
{
    printf("[hello]");
     fpurge(stdout);
    write(1,"here",5);
}