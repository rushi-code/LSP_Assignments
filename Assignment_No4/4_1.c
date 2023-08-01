/////////////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which is used to demonstration concept of I/O redirection**      
//                                                                       
//////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

int main(int argc, char *argv[])
{
    int iNo1 = 0, iNo2 = 0, iAns = 0;
    scanf("%d",&iNo1);
    scanf("%d",&iNo2);

    iAns = iNo1 + iNo2;

    printf("Addition is %d\n",iAns);    

    exit(EXIT_SUCCESS);
}


//To Run This Application
// Executable   <input_file    >output_file