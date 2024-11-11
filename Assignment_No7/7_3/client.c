///////////////////////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which is used to create 2 shared library(.SO files) and that 
//          library should be loaded at run time by the other program.
//
//          First library should contains function to check whether the input number is 
//          prime or not 
//          Second library should contains function to check whether the input number is perfect or not
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<stdbool.h>

int main(int argc, char *argv[])
{
    void *ptr1 = NULL;
    void *ptr2 = NULL;
    bool (*fptr1)(int);
    bool(*fptr2)(int);

    bool bFlag = false;

    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    ptr1 = dlopen("/media/rushi/New Volume/MARVELLOUS_LSP/LSP_Assignments/Assignment_No7/7_3/library.so",RTLD_LAZY);  

    if(ptr1 == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr1 = dlsym(ptr1,"ChkPrime");   

    if(fptr1 == NULL)
    {
        printf("Unable to load the address of function addition\n");
        return -1;
    } 

    bFlag = fptr1(atoi(argv[1]));

    if(bFlag == true)
    {
        printf("Given number is prime\n");
    }
    else
    {
        printf("Given number is not prime\n");
    }


    ptr1 = dlopen("/media/rushi/New Volume/MARVELLOUS_LSP/LSP_Assignments/Assignment_No7/7_3/library.so",RTLD_LAZY);  

    if(ptr1 == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr2 = dlsym(ptr1,"ChkPerfect");   

    if(fptr2 == NULL)
    {
        printf("Unable to load the address of function addition\n");
        return -1;
    } 

    bFlag = fptr2(atoi(argv[1]));

    if(bFlag == true)
    {
        printf("Given number is perfect\n");
    }
    else
    {
        printf("Given number is not perfect\n");
    }

    return 0;
}

