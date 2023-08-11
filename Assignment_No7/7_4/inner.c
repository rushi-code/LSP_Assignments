#include"inner.h"

int Factorial(int iNo)
{
    int iMult = 1;

    while(iNo!=0)
    {
        iMult = iMult*iNo;
        iNo--;
    }
}