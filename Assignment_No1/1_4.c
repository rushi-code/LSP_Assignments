//////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept file name from user and print all information about the file**    
//                                                                       
/////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0


int main(int argc, char *argv[])
{
    struct stat sobj;


    if((argc != 2))
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H  \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);

        exit(FAILURE);
    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to display statistical information about file \n");
        exit(SUCCESS);
    }

    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_Of_Executable   File_Name\n");
        exit(SUCCESS);
    }

    stat(argv[1],&sobj);
    
    printf("File Name : %s\n",argv[1]);
    printf("File Size : %d\n",sobj.st_size);
    printf("Inode Number : %d\n",sobj.st_ino);
    printf("Device ID : %d\n",sobj.st_dev);
    printf("User ID : %d\n",sobj.st_uid);
    printf("Group ID : %d\n",sobj.st_gid);
    printf("Number of Blocks ; %d\n",sobj.st_blocks);
    printf("Block Size ; %d\n",sobj.st_blocks);
    printf("Number of links : %d\n",sobj.st_nlink);


    exit(EXIT_SUCCESS);
}