//////////////////////////////////////////////////////////////////////////////////////
// 
//  **Write a program which is used to get thread id inside its thread function**
//      
/////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *ThreadProc1(void *ptr)
{
    printf("Inside thread\n");
    printf("Thread ID of the current thread is %ld\n",pthread_self());
}

int main()
{
    pthread_t TID1;

    int ret1 = 0;

    ret1 = pthread_create(&TID1,NULL,ThreadProc1,NULL);

    if(ret1!= 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread1 is succssfully created with TID : %ld\n",TID1);

     
    pthread_join(TID1,NULL);

    printf("End of main thread\n");    

    pthread_exit(NULL);

    return 0;
}