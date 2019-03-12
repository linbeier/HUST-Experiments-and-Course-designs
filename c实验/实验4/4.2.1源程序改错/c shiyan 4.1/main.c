//
//  main.c
//  c shiyan 4.1
//
//  Created by 林斌 on 2017/4/20.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include "stdio.h"
#include"stdlib.h"
#define SUM ((a)+(b))//
#define DIF ((a)-(b))
#define SWAP(a,b)  a+=b,b=a-b,a-=b//
int main()
{
    int a,b;//
    printf("Input two integers a, b:");
    scanf("%d%d", &a,&b);//
    printf("\nSUM=%d\n the difference between square of a and square of b is:%d",SUM, SUM*DIF);
    SWAP(a,b);
    printf("\nNow a=%d,b=%d\n",a,b);
    system("PAUSE");
    return 0;//
}
