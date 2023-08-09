//////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept directory name from user and create hole in file       
//      if size is less than 1kb & if it is greater than 1kb then truncate the remaining data**
//                                                                       
//////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

typedef signed int SINT;

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

#define BLOCK 1024

int main(int argc, char *argv[])
{
    SINT fd = 0;
    
    if(argc!=2)
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H  \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);
        exit(FAILURE);
    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to create hole if size< 1kb and truncate if size>1kb\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_of_executable  File_name \n");
        exit(SUCCESS);
    }

    fd = open(argv[1],O_RDWR);
    if(fd == FAILURE)
    {
        printf("Unable to open the file\n");
        exit(FAILURE);
    }


    int size = lseek(fd,BLOCK,SEEK_END);

    if(size < BLOCK)
    {
        if(lseek(fd,BLOCK,SEEK_END)== FAILURE)
        {
            printf("Unable to create hole in the file\n");
            close(fd);
            exit(FAILURE);
        }
    }

    else 
    {
        if(ftruncate(fd,BLOCK)==-1)
        {
            printf("Unable to truncate file\n");
            close(fd);
            exit(FAILURE);
        }
    }

    close(fd);

    printf("Completed Successfully\n");
      

    exit(EXIT_SUCCESS);
}