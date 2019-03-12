//
//  main.c
//  c shiyan 4.5
//
//  Created by 林斌 on 2017/4/20.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include"stdlib.h"
#define s(a,b,c) (a+b+c)/2.0
#define area(s,a,b,c) sqrt((s)*((s)-(a))*((s)-(b))*((s)-(c)))
int main ()
{
    double a,b,c;
    printf("请输入三角形的三边：");
    scanf("%lf%lf%lf",&a,&b,&c);
    if (((a+b)>c)&&((b+c)>a)&&((a+c)>b))
        printf("s=%lf area=%lf\n",s(a,b,c),area(s(a, b, c), a, b, c));
    else printf("Error!\n");
    system("PAUSE");
    return 0;
}
