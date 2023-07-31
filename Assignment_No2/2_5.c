///////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept directory name from user and print name of such file 
//      having largest size**       
//                                                                       
//////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char Name[50]= {'\0'};
    char NameCopy[50] = {'\0'};
    int iMax = 0;


    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);

        exit(FAILURE);

    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to display largest file from directory\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_of_executable   Name_of_Directory\n");
        exit(SUCCESS);
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        exit(FAILURE);
    }

    printf("-------------------------------------------------\n");
    printf("Entries from Directroy are\n");

    while((entry =readdir(dp))!=NULL)
    {
        sprintf(Name,"%s/%s",argv[1],entry->d_name);
        stat(Name,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            if(iMax<sobj.st_size)
            {
                iMax = sobj.st_size;
                strcpy(NameCopy,Name);
            }
        }
    }
    
    printf("Name of largest file is : %s with size %d bytes \n",NameCopy,iMax);
    closedir(dp);
    
    exit(EXIT_SUCCESS);
}