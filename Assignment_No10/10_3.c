//////////////////////////////////////////////////////////////////////////////////////
// 
//  **Write a program which creates single thread and we have to pass 
//    parameter to that thread from main thread**
//      
/////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *ThreadProc1(void *ptr)
{
    printf("The parameter received from main thread is %d\n",(int)ptr);
    
    pthread_exit(NULL);
}



int main()
{
    pthread_t TID1;

    int ret1 = 0;
    int no = 11;

    ret1 = pthread_create(&TID1,NULL,ThreadProc1,(int *)no);

    if(ret1!= 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread1 is succssfully created with TID : %d\n",TID1);

     
    pthread_join(TID1,NULL);
   
    printf("End of Main Thread\n");

    pthread_exit(NULL);

    return 0;
}