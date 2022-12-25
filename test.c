#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main()
{
    printf("hello");
    fflush(stdout);
    write(1,"here",5);
}