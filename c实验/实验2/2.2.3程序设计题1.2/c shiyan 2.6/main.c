//
//  main.c
//  c shiyan 2.6
//
//  Created by 林斌 on 2017/4/6.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
int main(void)
{
    float x,m;
    printf("输入工资金额:");
    scanf("%f",&x);
    switch ((int)(x/1000)) {
        case 0:m=0;break;
        case 1:m=x*0.05;break;
        case 2:m=x*0.1;break;
        case 3:m=x*0.15;break;
        case 4:m=x*0.2;break;
        default:m=x*0.25;
            break;
    }
    printf("应收取税金额:%f",m);
    putchar('\n');
    system("PAUSE");
    return 0;
}
