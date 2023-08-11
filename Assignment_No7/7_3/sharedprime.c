#include<stdio.h>
#include<stdbool.h>
#include"sharedfile.h"

bool ChkPrime(int iNo)
{
    int iCnt = 0;

    if(iNo<0)
    {
        iNo = -iNo;
    }

    for(iCnt = 2; iCnt<=(iNo/2);iCnt++)
    {
        if(iNo%iCnt == 0)
        {
            break;
        }
    }
    if(iCnt == (iNo/2)+1)
    {
        return true;
    }
    else
    {
        return false;
    }
}