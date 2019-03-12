//
//  main.c
//  c shiyan 3.1
//
//  Created by 林斌 on 2017/4/13.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include "stdio.h"
#include "stdlib.h"
long sum_fac(int n);//先声明函数，否则函数无法使用
int  main(void)
{
    int k;
    for(k=1;k<6;k++)
        printf("k=%d\tthe sum is %ld\n",k,sum_fac(k));
    system("pause");
    return 0;//return 0应该在函数内
}
long sum_fac(int n)
{
    long s=0;
    int i;
    long fac=1;//为fac赋初值，防止计算出错
    for(i=1;i<=n;i++)
    {
    fac*=i;
    s+=fac;//该语句应该在循环体里面
    }
    return s;
}
