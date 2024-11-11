/////////////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which is used to create shared library and that library     
//      should be loaded at run time by other program
//      That library should contains functions to perform the arithmetic operations
//      like addition, subtraction, Division and multiplication.**   
//                                                              
/////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    int (*fptr)(int, int);
    int a = 20, b = 5;

    ptr = dlopen("/media/rushi/New Volume/MARVELLOUS_LSP/LSP_Assignments/Assignment_No7/7_1/library.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"Addition");
    if(fptr == NULL)
    {
        printf("Unable to load the address of fucntion\n");
        return -1;
    }
    else
    {
        printf("Addition is %d\n",fptr(a,b));
    }
    
    fptr = dlsym(ptr,"Subtraction");
    if(fptr == NULL)
    {
        printf("Unable to load the address of fucntion\n");
        return -1;
    }
    else
    {
        printf("Subtraction is %d\n",fptr(a,b));
    }
    

    fptr = dlsym(ptr,"Multiplication");
    if(fptr == NULL)
    {
        printf("Unable to load the address of fucntion\n");
        return -1;
    }
    else
    {
        printf("Multiplication is %d\n",fptr(a,b));
    }

    fptr = dlsym(ptr,"Division");
    if(fptr == NULL)
    {
        printf("Unable to load the address of fucntion\n");
        return -1;
    }
    else
    {
        printf("Division is %d\n",fptr(a,b));
    }


    return 0;
}