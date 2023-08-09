//////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which create hole of size 1kb at end of file**       
//                                                                       
//////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>

typedef signed int SINT;

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

int main(int argc, char *argv[])
{

    SINT fd = 0;
    char Buffer[1024] = {'\0'};
    struct stat sobj;
    
    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);

        exit(FAILURE);

    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to create hole of 1kb at end of file\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_of_executable   File_name\n");
        exit(SUCCESS);
    }

    fd = open(argv[1],O_WRONLY);

    if(fd == FAILURE)
    {
        printf("Unable to open the file\n");
        exit(FAILURE);
    }

    stat(argv[1],&sobj);

    printf("%d",sobj.st_size);

    lseek(fd, sobj.st_size, SEEK_SET);

    write(fd, Buffer, sizeof(Buffer));
   

    exit(EXIT_SUCCESS);
}