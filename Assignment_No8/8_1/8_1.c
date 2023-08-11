//////////////////////////////////////////////////////////////////////////////////////
// 
//  **Write a program in which parent process waits till its child process terminates**
//
/////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;
    int pid = 0;
    int Exit_status = 0;

    Ret = fork();

    if(Ret == 0)
    {
        printf("Child process is running with PID %d\n",getpid());
        execl("./Childprocess","Childprocess",NULL);
    }
    else
    {
        printf("Parent is running with PID %d\n",getpid());
        pid = wait(&Exit_status);
        printf("Child process terminated having PID %d with exit status %d\n",pid,Exit_status);
    }
    return 0;
}