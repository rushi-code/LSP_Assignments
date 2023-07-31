//////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept file name and mode and that program check whether our
//       process can access that file in accepted mode or not**    
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
        printf("Help : It is used to check that file have access or not\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage 		: Name_Of_Executable   File_Name   File_Mode\n");
		printf("File Modes	: Read, Write, Execute\n");	
        exit(SUCCESS);
    }

    if(strcmp(argv[2],"Read")== 0)
    {
        mode = R_OK;
    }

    else if(strcmp(argv[2],"Write")== 0)
    {
        mode = W_OK;
    }

    else if(strcmp(argv[2],"Execute")== 0)
    {
        mode = X_OK;
    }

    if(access(argv[1],mode)<0)
    {
        printf("Unable to access %s file in %s mode\n",argv[1],argv[2]);
        exit(FAILURE);
    }
    else
    {
        printf("You can access %s file in %s mode\n",argv[1],argv[2]);
        exit(SUCCESS);
    }

    exit(EXIT_SUCCESS);
}