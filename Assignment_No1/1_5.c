//////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept file name and numebr of bytes from user and 
//      read that number of bytes from file**    
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

typedef signed int SINT;


int main(int argc, char *argv[])
{
    SINT fd = 0,Ret = 0, Size = 0;
    char *Buffer = NULL;

    if((argc == 1)||(argc > 3))
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H  \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);

        exit(FAILURE);
    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to read data from existing file\n");
        exit(SUCCESS);
    }

    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_Of_Executable   File_Name    No_of_Bytes\n");
        exit(SUCCESS);
    }

    fd = open(argv[1],O_RDWR);

    if(fd == FAILURE)
    {
        printf("Unable to open file\n");
        exit(FAILURE);
    }

    Size = atoi(argv[2]);

    Buffer = (char *)malloc(Size);

    Ret = read(fd,Buffer,atoi(argv[2]));

    if(Ret == 0)
    {
        printf("Unable to read\n");
        exit(FAILURE);
    }

    printf("Data from file is :\n");
    write(1,Buffer,Ret);

    close(fd);
    
    exit(EXIT_SUCCESS);
}