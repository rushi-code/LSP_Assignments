///////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which writes structures in file. Structure should
//      contains information of student**       
//                                                                       
//////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

#pragma pack(1)
typedef signed int SINT;

struct Student
{
    int RollNo;
    char Sname[20];
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{
    SINT fd = 0,ret = 0;
    struct Student sobj;

    sobj.RollNo = 11;
    sobj.Marks = 89.99f;
    sobj.Age = 25;
    strcpy(sobj.Sname,"Rushikesh");

    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);

        exit(FAILURE);

    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to write structure into file\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_of_executable   File_name\n");
        exit(SUCCESS);
    }
    
    fd = creat(argv[1],0777);

    if(fd == FAILURE)
    {
        printf("Unable to create the file\n");
        exit(FAILURE);
    }

    write(fd,&sobj,sizeof(sobj));

    exit(EXIT_SUCCESS);
    
}


