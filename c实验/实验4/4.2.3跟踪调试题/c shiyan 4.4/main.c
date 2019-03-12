//
//  main.c
//  c shiyan 4.4
//
//  Created by 林斌 on 2017/4/20.
//  Copyright © 2017年 林斌. All rights reserved.
//
#include "stdio.h"//
#include "assert.h"//
#include "stdlib.h"
#define  R
long int integer_fraction(float x);//
int  main(void)//
{
    float  r, s;
    long int s_integer=0;
    printf("input a number:");
    scanf("%f",&r);
#ifdef  R
    s=3.14159*r*r;
    printf("area of round is: %f\n",s);
    s_integer= integer_fraction(s);
    printf("the integer fraction of area is %ld\n", s_integer);
    assert((s-s_integer)<1.0);
#endif
    system("PAUSE");
    return 0;
}

long int integer_fraction(float x)
{
    long int i=x;//i==0--i==28
    return i;
}
