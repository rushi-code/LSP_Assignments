//////////////////////////////////////////////////////////////////////////////////////
// 
//  **Write a program which is used to create simple thread using pthread library**
//      
/////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *ThreadProc(void *ptr)
{
    printf("Inside Thread\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID;

    int ret = 0;

    ret = pthread_create(&TID,NULL,ThreadProc,NULL);

    if(ret!= 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is succssfully created with TID : %d\n",TID);

    pthread_join(TID,NULL);

    printf("End of Main Thread\n");

    pthread_exit(NULL);

    return 0;
}