///////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept directory name and file name from user 
//     and check whether that file is present in that directory or not**       
//                                                                       
//////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/dir.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0


typedef signed int SINT;

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    if((argc == 1)||(argc > 3))
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);

        exit(FAILURE);

    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to check file is present in directory or not\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_of_executable   Name_of_Directory   Name_of_File\n");
        exit(SUCCESS);
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        exit(FAILURE);
    }

    while((entry = readdir(dp))!=NULL)
    {
        if(strcmp(argv[2],entry->d_name)==0)
        {
            printf("File is present in that directory\n");
            break;
        }
    }

    if(entry == NULL)
    {
        printf("There is no such file in this directory\n");
        exit(FAILURE);
    }

    closedir(dp);

    exit(EXIT_SUCCESS);
}