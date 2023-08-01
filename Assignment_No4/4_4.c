/////////////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept directory name from user and copy first       
//      10 bytes from all regular files into newly created file named as Demo.txt
//                                                                
//////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>


#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

typedef signed int SINT;

int main(int argc, char *argv[])
{
    SINT fd = 0, fdnew = 0,Ret = 0;
    DIR *dp = NULL;
    char Buffer[20],name[20];
    struct stat sobj;
    struct dirent *entry = NULL;

    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H  \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);
        exit(FAILURE);
    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to copy first 10 bytes from all regular files into newly created file\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_Of_Executable   Name_of_Directory\n");
        exit(SUCCESS);
    }

    fdnew = creat("Demo.txt",0777);

    if(fdnew ==FAILURE)
    {
        printf("Unable to crate new file\n");
        exit(FAILURE);
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        exit(FAILURE);
    }

    while((entry = readdir(dp))!= NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);

        stat(name,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            fd = open(name,O_RDONLY);

            if(fd == FAILURE)
            {
                printf("Unable to open the file in the directory\n");
                break;
            }

            Ret = read(fd,Buffer,10);
            write(fdnew,Buffer,Ret);
            write(fdnew,"\n",1);
            memset(Buffer,0,sizeof(Buffer));

            close(fd);
        }
    }

    close(fdnew);
    closedir(dp);

    

    exit(EXIT_SUCCESS);
}


