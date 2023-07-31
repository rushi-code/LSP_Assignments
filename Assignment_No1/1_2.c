//////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept file name from user and open that file in specified mode     
//                                                                       
//////////////////////////////////////////////////////////////////////////////////////////////

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
    SINT fd = 0;
    SINT mode = 0;

    

    if((argc == 1)||(argc > 3))
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H  \n",argv[0]);
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
        printf("Usage 		: Name_Of_Executable   File_Name   File_Mode\n");
		printf("File Modes	: Read,Write,Read_Write\n");	
        exit(SUCCESS);
    }

    if(strcmp(argv[2],"Read")== 0)
    {
        mode = O_RDONLY;
    }

    else if(strcmp(argv[2],"Write")== 0)
    {
        mode = O_WRONLY;
    }

    else
	{
		mode = O_RDWR;
	}
    

    fd = open(argv[1],O_RDONLY);

    if(fd == FAILURE)
    {
        printf("Unable to open file\n");
        exit(FAILURE);
    }
    else
    {
        printf("File Opened Successfully with fd %d in %s mode\n",fd,argv[2]);
        exit(SUCCESS);
    }

    close(fd);

    exit(EXIT_SUCCESS);
}