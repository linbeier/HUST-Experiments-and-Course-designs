//
//  main.c
//  cshiyan3.2
//
//  Created by 林斌 on 2017/4/13.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
long sum_fac(int n);
int main(void)
{
    int k;
    for(k=1;k<6;k++)
        printf("k=%d\tthe sum is %ld\n",k,sum_fac(k));
    system("PAUSE");
    return 0;
}
long sum_fac(int n)
{
    static long f=1;
    f*=n;
    return f;
}
