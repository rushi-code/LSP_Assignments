///////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept directory name from user and write
//      information of all regular file in and then read the contents from that file**       
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


typedef signed int SINT;


int main(int argc, char *argv[])
{
    SINT fd = 0,ret = 0;
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char name[20],Buffer[MAXSIZE];

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
        exit(EXIT_SUCCESS);
    }

    fd = creat("FileInfo.txt",0777);
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
            printf("Information about the file is : \n");
            printf("File Name : %s\n",name);
            printf("File Size : %li\n",sobj.st_size);
            printf("Inode Number : %li\n",sobj.st_ino);
            printf("No of Blocks : %li\n",sobj.st_blocks);
            printf("No of links : %li\n",sobj.st_nlink);

            fd = open(name,O_RDONLY);
            if(fd == FAILURE)
            {
                printf("Unable to open file in directory\n");
                break;
            }

            printf("File contents are as follows\n");

            while((ret = read(fd,Buffer,sizeof(Buffer)))!=0)
            {
                write(1,Buffer,ret);
                memset(Buffer,0,sizeof(Buffer));
            }
            printf("\n");
        }
    }
    close(fd);
    closedir(dp);

    exit(EXIT_SUCCESS);
    
}


