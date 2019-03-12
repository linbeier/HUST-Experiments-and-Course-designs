//
//  main.c
//  cshiyan3.3
//
//  Created by 林斌 on 2017/4/13.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include"stdlib.h"
long sum_fac(int n);
int main(void)
{
    int k;
    double d,sum=0;
    for(k=1;k<6;k++){
        d=1.0/sum_fac(k);
        sum+=d;
        printf("k=%d\tthe sum is %lf\n",k,sum);
    }
    system("PAUSE");
    return 0;
}
long  sum_fac(int n)
{
    int i;
    long  f=1;
    for (i=1; i<=n; i++) f*=i;
    return f;
}
