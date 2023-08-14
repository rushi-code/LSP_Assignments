//////////////////////////////////////////////////////////////////////////////////////
// 
//  **Write a program which creates 4 number of threads and our main
//    threads waits till all the thread terminates**
//
/////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
    printf("Thread1\n");
    pthread_exit(NULL);

}

void * ThreadProc2(void *ptr)
{
    printf("Thread2\n");
    pthread_exit(NULL);
}

void * ThreadProc3(void *ptr)
{
    printf("Thread3\n");
    pthread_exit(NULL);
}

void * ThreadProc4(void *ptr)
{   
    printf("Thread4\n");
    pthread_exit(NULL);
}

int main()
{
    int ret = 0, iCnt = 0;
    pthread_t TID[4];

    void (*fp[4])(void *)={ThreadProc1,ThreadProc2,ThreadProc3,ThreadProc4};

    for(iCnt = 0; iCnt<=3; iCnt++)
    {
        ret = pthread_create(&TID[iCnt],NULL,fp[iCnt],NULL);

        if(ret != 0)
        {
            printf("Unable to create thread\n");
            return -1;
        }

        printf("Thread is created successfully with ID %d\n",TID[iCnt]);
    }


    for(iCnt = 0; iCnt<=3; iCnt++)
    {
        pthread_join(TID[iCnt],NULL);
    }

    printf("End of main thread\n");
    pthread_exit(NULL);

    
    return 0;
}
