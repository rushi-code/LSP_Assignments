#include"sharedfile.h"
#include<stdbool.h>

bool ChkPerfect(int iNo)
{
    int iCnt = 0, iAns = 0, iSum = 0;

    if(iNo<0)
    {
        iNo = -iNo;
    }

    for(iCnt = 1; iCnt<=(iNo/2);iCnt++)
    {
        if(iNo%iCnt == 0)
        {
            iSum = iSum +iCnt;
        }
    }

    if(iSum == iNo)
    {
        return true;
    }
    else
    {
        return false;
    }
   
}