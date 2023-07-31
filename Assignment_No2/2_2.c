//////////////////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept file name from user and write string in that file**       
//                                                                       
////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0


typedef signed int SINT;

int main(int argc, char *argv[])
{
    SINT fd = 0,ret = 0;

    char Buffer[100]={'\0'};


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

    
    fd = open(argv[1],O_RDWR);

    if(fd == FAILURE)
    {
        printf("Unable to open file\n");
        exit(FAILURE);
    }
    
    else
    {
        printf("File is successfully opened with fd %d\n",fd);
    }

    printf("Enter string\n");
    scanf(" %[^\n]s",Buffer);

    ret = write(fd,Buffer,strlen(Buffer));
    printf("%d bytes get successfully return in the %s file\n",ret,argv[1]);
    close(fd);
    
    exit(EXIT_SUCCESS);
}