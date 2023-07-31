///////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept directory name and file name from user 
//     and move all files from source directory to destination directory**       
//                                                                       
//////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/dir.h>
#include<sys/stat.h>


#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0


typedef signed int SINT;

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char oldname[50] = {'\0'};
    char newname[50] = {'\0'};
    struct stat sobj;
    int iCnt = 0;

    if((argc == 1)||(argc > 3))
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);

        exit(FAILURE);

    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to move all files from one directory to another directory\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_of_executable   Name_of_SourceDirectory   Name_of_DestDirectory\n");
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
        
        sprintf(oldname,"%s/%s",argv[1],entry->d_name);
        sprintf(newname,"%s/%s",argv[2],entry->d_name);
        
        rename(oldname,newname);
        
    }
    printf("files are successfully transferred from %s to %s \n",argv[1],argv[2]);


    closedir(dp);

    exit(EXIT_SUCCESS);
}