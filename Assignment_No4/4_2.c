/////////////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept directory name from user       
//      and create new directory of that name**
//                                                                
//////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>


#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

typedef signed int SINT;

int main(int argc, char *argv[])
{
    SINT fd = 0;

    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H  \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);
        exit(FAILURE);
    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to create new directory\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage 		: Name_Of_Executable   Name_of_Directory\n");
        exit(SUCCESS);
    }


    fd = mkdir(argv[1],0777);
    if(fd == FAILURE)
    {
        printf("Unable to create directory\n");
        exit(FAILURE);
    }
    else
    {
        printf("%s Directory Created Successfully\n",argv[1]);
    }



    exit(EXIT_SUCCESS);
}


