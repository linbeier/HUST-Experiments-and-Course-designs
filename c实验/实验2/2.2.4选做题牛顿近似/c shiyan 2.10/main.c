//
//  main.c
//  c shiyan 2.10
//
//  Created by 林斌 on 2017/4/6.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define a 1e-6

int main(void)
{
    double x,d;
    printf("input your initial root:\n");
    scanf("%lf",&x);
    do{
        d=-((((3*x-4)*x)-5)*x+13)/((9*x-8)*x-5);
        x+=d;
    }while (fabs(d)>a);
    printf("x=%f\n",x);
    system("PAUSE");
    return 0;
}
