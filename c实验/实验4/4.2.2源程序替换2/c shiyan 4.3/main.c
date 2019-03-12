//
//  main.c
//  c shiyan 4.3
//
//  Created by 林斌 on 2017/4/20.
//  Copyright © 2017年 林斌. All rights reserved.
//
#include "stdio.h"
#include "stdlib.h"
#define max(x,y,z)(x)<(y)?((y)<(z)?(z):(y)):((x)<(z)?(z):(x))

double sum(double  x, double y);
int main(void)
{
    int a, b, c;
    double d, e;
    printf("Enter three integers:");
    scanf("%d%d%d",&a,&b,&c);
    printf("\nthe maximum of them is %d\n",max(a,b,c));
    printf("Enter two floating point numbers:");
    scanf("%lf %lf",&d,&e);
    printf("\nthe sum of them is  %f\n",sum(d,e));
    system("PAUSE");
    return 0;
}

double sum(double  x, double y)
{
    return x+y;
}
