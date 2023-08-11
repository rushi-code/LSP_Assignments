#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>
#include<stdbool.h>
#include "sharedfile.h"
#include<sys/stat.h>

bool Compare(char Fname1[], char Fname2[])
{
    int fd1 = 0, fd2 = 0, ret = 0, iCnt = 0;
    struct stat obj1, obj2;
    char Buffer1[1024];
    char Buffer2[1024];

    fd1 = open(Fname1, O_RDONLY);
    fd2 = open(Fname2, O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open the files\n");
        return -1;
    }

    fstat(fd1,&obj1);
    fstat(fd2,&obj2);

    if(obj1.st_size != obj2.st_size)
    {
        printf("Both files are different as sizes are different\n");
    }
    else
    {
        while((ret = read(fd1, Buffer1, sizeof(Buffer1))) != 0)
        {
            ret = read(fd2, Buffer2, sizeof(Buffer2));
            if(memcmp(Buffer1, Buffer2, ret) != 0)
            {
                break;
            }
        }

        if(ret == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    close(fd1);
    close(fd2);

    return 0;
}