///////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept directory name from user and combine
//      all contents from that directory into one file named as AllCombine
//                                                                       
//////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/dir.h>
#include<sys/stat.h>

#define MAXSIZE 1024
#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

#pragma pack(1)


typedef signed int SINT;

struct FileInfo
{
    char FileName[20];
    int FileSize;
};


int main(int argc, char *argv[])
{
    SINT fd = 0,ret = 0;
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    struct FileInfo obj;
    char name[30];

    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);

        exit(FAILURE);

    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to read all content of structure file\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_of_executable   File_name\n");
        exit(SUCCESS);
    }
    
    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        close(fd);
        exit(EXIT_SUCCESS);
    }

    fd = creat("AllCombine.txt",0777);
    if(fd == FAILURE)
    {
        printf("Unable to create new file\n");
    }


    while((entry = readdir(dp))!=NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            obj.FileSize = sobj.st_size;
            strcpy(obj.FileName,entry->d_name);
            write(fd,&obj,sizeof(obj));
            printf("%s\n",entry->d_name);
        }
        
        
    }
    closedir(dp);

    exit(EXIT_SUCCESS);
    
}


