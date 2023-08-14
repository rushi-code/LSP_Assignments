//////////////////////////////////////////////////////////////////////////////////////
// 
//  **Write a program which is used to predict the problem due to lack of synchronnization**
//
/////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int No = 0;

void * ThreadProc(void *ptr)
{
    int i = 0;
    No++;
    printf("Thread Executed With Number %d\n",No);

    for(i =0; i<0XFFFFFFFF; i++);

    printf("Thread Completed With Number %d\n",No);

    pthread_exit(NULL);


}

int main()
{
    pthread_t TID1,TID2; 
    int ret = 0;

    ret = pthread_create(&TID1,NULL,ThreadProc,NULL);
    if(ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created successfully with ID %d\n",TID1);


    ret = pthread_create(&TID2,NULL,ThreadProc,NULL);
    if(ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created successfully with ID %d\n",TID2);

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);


    printf("End of main thread\n");
    pthread_exit(NULL);


    
    return 0;
}
