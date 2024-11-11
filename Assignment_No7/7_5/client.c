///////////////////////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          Write a program which create static library which  takes file name from user and displays the 
//          information of that file.
//
//          
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include"sharedfile.h"
#include<fcntl.h>
#include<string.h>


int main(int argc, char *argv[])
{
    
    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);

        return -1;

    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to display information of file using static library \n");
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_of_executable   Name_of_file\n");
    }

    void *ptr = NULL;
    void(*fptr)(int);

    int fd = 0;
    
    fd = open(argv[1],O_RDONLY);

    DisplayInfo(fd);

    return 0;
}
