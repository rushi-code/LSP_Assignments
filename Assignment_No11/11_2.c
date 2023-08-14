//////////////////////////////////////////////////////////////////////////////////////
// 
//  **Write a program which creates multiple threads and sets its thread attributes accordingly**
//
/////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
    int *ID = (int*)ptr;
    
    printf("Thread %d is running\n",ID);
    pthread_exit(NULL);

}

int main()
{
    pthread_t Count[5];   //Total Threads
    pthread_t TNo[5];   //Thread Number 


    int ret = 0, iCnt = 0;

    for(int iCnt = 0;iCnt<5;iCnt++ )
    {
        TNo[iCnt] = iCnt;
    }

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    for(int iCnt = 0;iCnt<5;iCnt++ )
    {
        ret = pthread_create(&Count[iCnt],&attr,ThreadProc,TNo[iCnt]+1);
        if(ret != 0)
        {
            printf("Unable to create thread\n");
            return -1;
        }

        printf("Thread is created successfully with ID %d\n",Count[iCnt]);
    }

    pthread_attr_destroy(&attr);

    for(iCnt = 0; iCnt<5; iCnt++)
    {
        pthread_join(Count[iCnt],NULL);
    }

    printf("End of main thread\n");
    pthread_exit(NULL);


    
    return 0;
}
