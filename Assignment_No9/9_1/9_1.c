//////////////////////////////////////////////////////////////////////////////////////////////
//
//      **Write a program which creates new process which is responsible to write all file names
//        which are present on desktop in demo file which should be created newly.** 
//
///////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int Ret = 0;
    int Exit_status = 0;

    Ret = fork();

    if(Ret == 0)
    {
        printf("Child process is running with PID %d\n",getpid());
        execl("./process","NULL",NULL);
    }
    
    wait(&Exit_status);
    return 0;
}