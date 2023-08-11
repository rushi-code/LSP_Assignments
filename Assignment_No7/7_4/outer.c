#include"outer.h"
#include<stdio.h>
#include<stdlib.h>


void Outer()
{
    void *ptr = NULL;

    int(*fptr)(int);

    unsigned long int Resullt = 0;
    int No = 0;

    ptr = dlopen("/media/rushi/New Volume/MARVELLOUS_LSP/LSP_Assignments/Assignment_No7/7_4/inner.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return ;
    }

    fptr = dlsym(ptr,"Factorial");
    if(fptr == NULL)
    {
        printf("Unable to load address of function\n");
        return ;
    }

    printf("Enter number whose factorial you want\n");
    scanf("%d",&No);

    Resullt = fptr(No);

    printf("Factorial of %d is %lu\n",No, Resullt);




}