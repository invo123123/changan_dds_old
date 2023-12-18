#include "changan/business_util.h"
#include <stdio.h>

bool BussinessUtil::isEventType(int32_t funId)
{
    int i =0;
    char str[20];
    for (int i = 0;i<20 ; i++)
    {
        str[i] = 'x';
    }
    sprintf(str,"%x",funId);
    for(;i< 19 ;i++)
    {
        if(str[i+1] == 'x')
        {
        break;
        }	
    }
    // 8=event,0/2=method
    return i>3 && str[i-4] == '8';
}