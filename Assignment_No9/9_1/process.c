#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

int main()
{
    DIR *dp = NULL;
    char Dirname[30],name[30];
    struct dirent *entry = NULL;
    int fd  = 0;
    struct stat sobj;

    strcpy(Dirname,"/home/rushi/Desktop");

    dp = opendir(Dirname);

    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }

    fd = creat("demo.txt",0777);

    if(fd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }

    while((entry = readdir(dp))!=NULL)
    {
        sprintf(name,"%s%s\n",Dirname,entry->d_name);
        fd = open("demo.txt",O_WRONLY| O_APPEND);

        write(fd,name,sizeof(name));
        memset(name,0,sizeof(name));
    }
    close(fd);

    return 0;
}