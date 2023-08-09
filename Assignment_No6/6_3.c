//////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept directory name and file name from user       
//      create file in that directory**
//                                                                       
//////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<dirent.h>

typedef signed int SINT;

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

int main(int argc, char *argv[])
{

    SINT fd = 0;
    int dp = 0;
   
    if((argc==1)||(argc>3))
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H  \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);
        exit(FAILURE);
    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to create file in that directory\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_of_executable  Directory_Name  File_Name\n");
        exit(SUCCESS);
    }

    dp = chdir(argv[1]);
    if(dp == FAILURE)
    {
        printf("Unable to change the directory\n");
        exit(FAILURE);
    }

    fd = creat(argv[2],0777);

    if(fd ==FAILURE)
    {
        printf("Unable to create file in this directory\n");
        exit(FAILURE);    
    }
    else
    {
        printf("File is successfully created in the directory\n");
    }

    close(fd);

    exit(EXIT_SUCCESS);
}