///////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept file name from user and read whole file**       
//                                                                       
//////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0
#define BLOCKSIZE 1024

typedef signed int SINT;

int main(int argc, char *argv[])
{
    SINT fd = 0,ret = 0;

    char Buffer[BLOCKSIZE];


    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);

        exit(FAILURE);

    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to open an existing file\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_of_executable   Name_of_file\n");
        exit(SUCCESS);
    }

    
    fd = open(argv[1],O_RDONLY);

    if(fd == FAILURE)
    {
        printf("Unable to open file\n");
        exit(FAILURE);
    }
    
    while((ret = read(fd,Buffer,sizeof(Buffer)))!= 0)
    {
        write(1,Buffer,ret);
    }

    close(fd);

    exit(EXIT_SUCCESS);
}