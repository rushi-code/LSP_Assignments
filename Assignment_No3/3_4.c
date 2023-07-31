///////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which accept directory name from user delete  
//      all empty files from that directory**
//                                                                       
//////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/dir.h>
#include<sys/stat.h>


#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0


typedef signed int SINT;

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    struct stat sobj;
    
    char name[30];
    int iCnt = 0;

    if(argc !=2)
    {
        printf("Invalid Arguments\n");
        printf("Help : %s --h/--H \n",argv[0]);
        printf("Usage : %s --u/--U \n",argv[0]);

        exit(FAILURE);

    }

    if((strcmp(argv[1],"--H")==0)||(strcmp(argv[1],"--h")==0))
    {
        printf("Help : It is used to delete all empty files from directory\n");
        exit(SUCCESS);
    }


    else if((strcmp(argv[1],"--U")==0)||(strcmp(argv[1],"--u")==0))
    {
        printf("Usage : Name_of_executable   Name_of_SourceDirectory   Name_of_DestDirectory\n");
        exit(SUCCESS);
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        exit(FAILURE);
    }

    

    while((entry = readdir(dp))!=NULL)
    {
        
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size == 0)
            {
                remove(name);
                iCnt++;
            }
        
        }
        
    }
    if (iCnt == 0)
    {
        printf("There is no empty file in this directory\n");

    }
    else
    {
        printf("%d Empty files are successfully deleted from %s\n",iCnt,argv[1]);
    }

    closedir(dp);

    exit(EXIT_SUCCESS);
}
