//////////////////////////////////////////////////////////////////////////////////////
// 
//  **Write a program which creates single thread and it accept one value from user 
//    and it retuns some value to the caller thread**
//      
/////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *ThreadProc1(void *ptr)
{

    int i = (int)ptr;
    
    pthread_exit(i*i*i);
}



int main()
{
    pthread_t TID1;

    int ret1 = 0;
    int no = 0;
    int value = 0;

    printf("Thread will do cube operation on that number\n");

    printf("Enter a value that you have to pass the thread\n");
    scanf("%d",&no);

    ret1 = pthread_create(&TID1,NULL,ThreadProc1,(int *)no);

    if(ret1!= 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread1 is succssfully created with TID : %d\n",TID1);

     
    pthread_join(TID1,&value);

    printf("The value received from thread is %d\n",value);
   
    printf("End of Main Thread\n");

    pthread_exit(NULL);

    return 0;
}