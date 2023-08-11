//////////////////////////////////////////////////////////////////////////////////////
// 
//  **// Write a program which create three level process hierarchy where process 1 creates process 2 
//       and it internally creates process 3.**
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
        execl("./process2","NULL",NULL);
    }
    else
    {
        printf("Process1 is running with PID : %d\n",getpid());
        pid = wait(&Exit_status);
        printf("Process2 terminated having PID %d with exit status %d\n",pid,Exit_status);
    }
    return 0;
}