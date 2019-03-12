//
//  main.c
//  c shiyan 2.5
//
//  Created by 林斌 on 2017/4/6.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    float x,m;
    printf("请输入您的工资金额:");
    scanf("%f",&x);
    if (x<1000)
        m=0;
    else if(x<2000)
        m=x*0.05;
    else if(x<3000)
        m=x*0.1;
    else if(x<4000)
        m=x*0.15;
    else if(x<5000)
        m=x*0.2;
    else m=x*0.25;
    printf("应收取税金额度：%f",m);
    putchar('\n');
    system("PAUSE");
    return 0;
}
