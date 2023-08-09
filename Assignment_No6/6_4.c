//////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept directory name and from user and      
//      delete all such files whose size is greater than 100 bytes**
//                                                                       
//////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<dirent.h>


#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

int main(int argc, char *argv[])
{

    DIR *dp  = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char name[25];

   
    if(argc!=2)
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H  \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);
        exit(FAILURE);
    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to delete files whose size is greater than 100 bytes\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_of_executable  Directory_Name\n");
        exit(SUCCESS);
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        exit(FAILURE);
    }

    while((entry = readdir(dp))!=NULL)
    {
        sprintf(name ,"%s/%s",argv[1],entry->d_name);

        stat(name,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size>100)
            {
                unlink(name);
            }
        }
    }

    exit(EXIT_SUCCESS);
}