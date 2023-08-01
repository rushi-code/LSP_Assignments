/////////////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a application which accept file name and position from user and 
//      read 20 bytes from that position**
//                                                                
//////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

typedef signed int SINT;

int main(int argc, char *argv[])
{
    SINT fd = 0,Ret = 0;
    char Arr[20];
    

    if((argc == 1) || (argc > 3))
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H  \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);
        exit(FAILURE);
    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to read 20 bytes from position\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_Of_Executable   Name_of_File   Position_of_Offset\n");
        exit(SUCCESS);
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == FAILURE)
    {
        printf("Unable to open file\n");
        exit(FAILURE);
    }

    lseek(fd,atoi(argv[2]),0);

    Ret = read(fd,Arr,20);
    write(1,Arr,Ret);

    exit(EXIT_SUCCESS);
}


