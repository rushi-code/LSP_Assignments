#include<stdio.h>
#include "sharedfile.h"

int Addition(int a, int b)
{
    return a+b;
}

int Subtraction(int a, int b)
{
    return a-b;
}

int Multiplication(int a, int b)
{
    return a*b;
}

int Division (int a, int b)
{
    if(b!=0)
    {
        return a/b;
    }
    else
    {
        return 0;
    }
}

