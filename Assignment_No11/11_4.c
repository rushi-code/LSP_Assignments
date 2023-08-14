//////////////////////////////////////////////////////////////////////////////////////
// 
//  **Write a program which creates two thread and by using appropriate
//    synchronization technique avoid the scheduling problem**
//
/////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int No = 0;

pthread_mutex_t lock;

void * ThreadProc(void *ptr)
{
    pthread_mutex_lock (&lock);
    int i = 0;
    No++;
    printf("Thread Executed With Number %d\n",No);

    for(i =0; i<0XFFFFFFFF; i++);

    printf("Thread Completed With Number %d\n",No);

    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);


}

int main()
{
    pthread_t TID1,TID2; 
    int ret = 0;

    pthread_mutex_init(&lock,NULL);

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

    pthread_mutex_destroy(&lock);


    printf("End of main thread\n");
    pthread_exit(NULL);


    
    return 0;
}
