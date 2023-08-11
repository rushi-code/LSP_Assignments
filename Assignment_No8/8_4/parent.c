////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//         **Write a program which creates two processes as process2 and process3 and our parent process
//         terminates till both the processes terminates.**
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
    int Ret1 = 0, Ret2 = 0;
    int cpid = 0;
    int Exit_status = 0;

    Ret1 = fork();

    if(Ret1 == 0)
    {
        execl("./process2","NULL",NULL);
    }
    else
    {
        printf("Parent process is running with PID : %d\n",getpid());
        cpid = wait(&Exit_status);
        printf("Process2 is terminated having PID %d with exit status %d\n",cpid,Exit_status);
    }

    Ret2 = fork();

    if(Ret2 == 0)
    {
        execl("./process3","NULL",NULL);
    }
    else
    {
        printf("Parent process is running with PID : %d\n",getpid());
        cpid = wait(&Exit_status);
        printf("Process3 is terminated having PID %d with exit status %d\n",cpid,Exit_status);
    }

    
    return 0;
}

