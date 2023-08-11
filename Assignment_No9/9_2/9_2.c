/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    ** Write a program which creates  processes. Process 1 count number of capital charaecters from demo.txt.
//       Process 2 count number of capital charaecters from hello.txt.Both the processes writes its count in count.txt file **
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int Ret1 = 0, Ret2 = 0;
    int Exit_status1 = 0, Exit_status2 = 0;

    Ret1 = fork();

    if(Ret1 == 0)
    {
        execl("/media/rushi/New Volume/MARVELLOUS_LSP/LSP_Assignments/Assignment_No9/9_2/process1","NULL",NULL);
    }

    wait(&Exit_status1);

    Ret2 = fork();

    if(Ret2 == 0)
    {
        execl("/media/rushi/New Volume/MARVELLOUS_LSP/LSP_Assignments/Assignment_No9/9_2/process2","NULL",NULL);
    }

    wait(&Exit_status2);

    return 0;
}