/////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                  
//    **Write a program which create shared library which internally loads other     
//      share library
//      The inner shared library provides the function to calculate the factorial 
//      of number. Also write program which will load that shared library and call the function**   
//                                                              
//////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<stdbool.h>

int main(int argc, char *argv[])
{
    void *ptr = NULL;
    void(*fptr)();

    ptr = dlopen("/media/rushi/New Volume/MARVELLOUS_LSP/LSP_Assignments/Assignment_No7/7_4/outer.so",RTLD_LAZY);


    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"Outer");

    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    fptr();
    return 0;
}

