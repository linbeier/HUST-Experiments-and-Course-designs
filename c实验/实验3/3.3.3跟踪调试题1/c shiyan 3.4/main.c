//
//  main.c
//  c shiyan 3.4
//
//  Created by 林斌 on 2017/4/13.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
long fabonacci(int n);
int main(void)
{
    int i,k;
    long sum=0,*p=&sum;
    scanf("%d",&k);
    for(i=1;i<=k;i++){
        sum+=fabonacci(i);//fab循环之后的语句位置
        printf("i=%d\tthe sum is %ld\n",i,*p);
        }
    system("PAUSE");
    return 0;
}
long fabonacci(int n)
{
    if(n==1 || n==2)
        return 1;
    else
    return fabonacci(n-1)+fabonacci(n-2);
}
