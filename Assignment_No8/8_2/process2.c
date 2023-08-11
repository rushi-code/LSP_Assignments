
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("Inside Process2\n");
    printf("PID of parent process(process1) is %d\n",getppid());

    int Ret = 0;
    int cpid = 0;
    int Exit_status = 0;

    Ret = fork();

    if(Ret == 0)
    {
        execl("./process3","NULL","NULL");
    }
    else
    {
        printf("Process2 is running with PID : %d\n",getpid());
        cpid = wait(&Exit_status);
        printf("Process3 terminated having PID %d with exit status %d\n",cpid,Exit_status);

    }

    return 0;
}