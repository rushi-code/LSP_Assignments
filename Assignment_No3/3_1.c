///////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept two file names from user and copy the 
//      contents of an existing file into newly created file**       
//                                                                       
//////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0
#define BLOCKSIZE 1024


typedef signed int SINT;

int main(int argc, char *argv[])
{
    SINT fdSource = 0,fdDest = 0, ret = 0;

    char Buffer[BLOCKSIZE]={'\0'};


    if((argc == 1)||(argc > 3))
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);

        exit(FAILURE);

    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to copy contents of existing file into new file\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_of_executable   Name_of_file   Name_of_New_File\n");
        exit(SUCCESS);
    }

    
    fdSource = open(argv[1],O_RDONLY);

    if(fdSource == FAILURE)
    {
        printf("Unable to open file\n");
        exit(FAILURE);
    }

    fdDest = creat(argv[2],0777);

    if(fdDest == FAILURE)
    {
        printf("Unable to create new file\n");
        close(fdSource);
        exit(FAILURE);
    }

    
    while((ret = read(fdSource,Buffer,sizeof(Buffer)))!= 0)
    {
        write(fdDest,Buffer,ret);
        memset(Buffer,0,sizeof(Buffer)); //Avoiding Garbage
    }

    close(fdSource);
    close(fdDest);

    exit(EXIT_SUCCESS);
}