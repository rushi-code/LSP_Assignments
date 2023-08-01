///////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept file name from user which contain
//      information of employee, we have read all contents of that file**       
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

    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);

        exit(FAILURE);

    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to read all content of structure file\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_of_executable   File_name\n");
        exit(SUCCESS);
    }
    
    fd = open(argv[1],O_RDONLY);

    read(fd,&sobj,sizeof(sobj));

    printf("Name : %s\n",sobj.Sname);
    printf("Roll No : %d\n",sobj.RollNo);
    printf("Marks : %f\n",sobj.Marks);
    printf("Age : %d\n",sobj.Age);

    write(fd,&sobj,sizeof(sobj));

    exit(EXIT_SUCCESS);
    
}


