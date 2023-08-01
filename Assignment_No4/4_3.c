/////////////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept two filenames from user and check whether      
//      content of that two files are equal or not**
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
    SINT fd1 = 0, fd2 = 0, Ret = 0;
    struct stat sobj1,sobj2;
    char Buffer1[1024] = {'\0'};
    char Buffer2[1024] = {'\0'};

    if((argc==1)||(argc>3))
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H  \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);
        exit(FAILURE);
    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to check two files are equal or not\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_Of_Executable   Name_of_First_File    Name_of_Second_File\n");
        exit(SUCCESS);
    }

    fd1 =open(argv[1],O_RDONLY);
    fd2 =open(argv[2],O_RDONLY);

    if(fd1 == FAILURE || fd2 == FAILURE)
    {
        printf("Unable to open file\n");
        exit(FAILURE);
    }

    fstat(fd1,&sobj1);
    fstat(fd2,&sobj2);

    if(sobj1.st_size != sobj2.st_size)
    {
        printf("Files are different as sizes are different\n");
        exit(FAILURE);
    }

    while(Ret = read(fd1,Buffer1,sizeof(Buffer1))!=0)
    {
        Ret = read(fd2,Buffer2,sizeof(Buffer2));

        if(memcmp(Buffer1,Buffer2,Ret)!=0)
        {
            break;
        }
    }

    if(Ret == 0)
    {
        printf("%s and %s both files are identical\n",argv[1],argv[2]);
        exit(SUCCESS);

    }
    else
    {
        printf("%s and %s both files are different\n",argv[1],argv[2]);

    }

    close(fd1);
    close(fd2);


    

    exit(EXIT_SUCCESS);
}


