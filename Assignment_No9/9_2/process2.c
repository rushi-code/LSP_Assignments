#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main()
{
    int fd = 0, iCnt = 0, iRet = 0, i = 0;
    char Buffer[512], Data[50];

    fd = open("hello.txt",O_RDONLY);

    if(fd == -1)
    {
        printf("unable to open file\n");
        return -1;
    }

    while((iRet = read(fd,Buffer,sizeof(Buffer)))!=0)
    {
        for(i = 0; i<iRet; i++)
        {
            if((Buffer[i]>='A')&&(Buffer[i]<='Z'))
            {
                iCnt++;
            }
        }
    }

    
    close(fd);

    fd = open("count.txt",O_WRONLY |O_APPEND,0644);

    if(fd == -1)
    {
        printf("Unable to open count.txt file\n");
        return -1;
    }

    sprintf(Data,"No of Capital Characters in hello.txt are %d\n",iCnt);

    write(fd,Data,strlen(Data));

    printf("%d capital letters written in count.txt file\n",iCnt);

    close(fd);
    
    return 0;
}