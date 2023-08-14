//////////////////////////////////////////////////////////////////////////////////////
// 
//  **Write a program which creates 2 threads by using pthread API, where one thread 
//    count capital characters and another count small characters from demo.txt file**
//
/////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>

void * ThreadProc1(void *ptr)
{
    int fd = 0, i = 0, iCnt = 0, iRet = 0;

    char Buffer[512];

    fd = open("Demo.txt",O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    while((iRet = read(fd,Buffer,sizeof(Buffer)))!= 0)
    {
        for(i = 0; i<iRet; i++)
        {
            if((Buffer[i]>='a')&&(Buffer[i]<='z'))
            {
                iCnt++;
            }
        }
    }

    printf("Number of small characters are %d\n",iCnt);
    close(fd);

    pthread_exit(NULL);
}

void * ThreadProc2(void *ptr)
{
    int fd = 0, i = 0, iCnt = 0, iRet = 0;

    char Buffer[512];

    fd = open("Demo.txt",O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    while((iRet = read(fd,Buffer,sizeof(Buffer)))!= 0)
    {
        for(i = 0; i<iRet; i++)
        {
            if((Buffer[i]>='A')&&(Buffer[i]<='Z'))
            {
                iCnt++;
            }
        }
    }

    printf("Number of capital characters are %d\n",iCnt);

    close(fd);
    
    pthread_exit(NULL);
}


int main()
{
    int ret1 = 0,ret2 = 0;
    pthread_t TID1,TID2;

    ret1 = pthread_create(&TID1,NULL,ThreadProc1,NULL);

    if(ret1!= 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Threads created successfully with ID %d\n",TID1);
    

    ret2 = pthread_create(&TID2,NULL,ThreadProc2,NULL);

    if(ret2!= 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Threads created successfully with ID %d\n",TID2);

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);

    pthread_exit(NULL);
    
    return 0;
}
