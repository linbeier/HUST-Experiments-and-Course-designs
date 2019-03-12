//
//  main.c
//  c experiment 6.1
//
//  Created by 林斌 on 2017/5/11.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include "stdio.h"
#include"stdlib.h"
void main(void)
{
    float i;
    float *p=&i;//指针悬浮
    scanf("%f",p);
    printf("%f\n",*p);
    system("PAUSE");
}
