#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("Process4 (PID: %d) is running with PID of parent process %d\n",getpid(),getppid());
    return 0;
}