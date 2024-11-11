////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//         write a Program which is used to create shared library(.SO files) and that 
//         library should be loaded at run time by the other program.
//
//         That library should contains functions that accept two file names from user
//         and it will compare the contents of that file.
////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<stdbool.h>

int main(int argc, char *argv[])
{
    void *ptr = NULL;
    bool (*fptr)(char[],char[]);
    bool flag = false;

    if(argc != 3)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    ptr = dlopen("/media/rushi/New Volume/MARVELLOUS_LSP/LSP_Assignments/Assignment_No7/7_2/library.so",RTLD_LAZY);  

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"Compare");   

    if(fptr == NULL)
    {
        printf("Unable to load the address of function addition\n");
        return -1;
    } 

    flag = fptr(argv[1], argv[2]);

    if(flag == true)
    {
        printf("Files are same\n");
    }
    else
    {
        printf("Files are different\n");
    }

    return 0;
}

