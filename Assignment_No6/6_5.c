//////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept file name from user and offset,      
//      remove all data from that offset**
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

int main(int argc, char *argv[])
{
    SINT fd = 0;
    int offset = 0;

    
   
    if(argc!=2)
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H  \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);
        exit(FAILURE);
    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to remove data from given offset\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_of_executable  File_name \n");
        exit(SUCCESS);
    }

    printf("Enter the offset from where you want to remove all data\n");
    scanf("%d",&offset);

    fd = open(argv[1],O_WRONLY);
    if(fd == FAILURE)
    {
        printf("Unable to open the file \n");
        exit(FAILURE);
    }

    if(lseek(fd,offset,SEEK_SET)==-1)
    {
        printf("Unable to set the file offset\n");
        close(fd);
        exit(FAILURE);
    }

    if(ftruncate(fd,offset)== FAILURE)
    {
        printf("Failed to remove data from the file \n");
        close(fd);
        exit(FAILURE);
    }

    close(fd);
    printf("Data remove from offset %d in the file %s\n",offset,argv[1]);


    exit(EXIT_SUCCESS);
}