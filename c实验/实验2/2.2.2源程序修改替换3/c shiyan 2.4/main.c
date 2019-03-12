//
//  main.c
//  c shiyan 2.4
//
//  Created by 林斌 on 2017/4/6.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>

int main()
{
    int i,n=0;
    long s1=1,s2;
    printf("Please enter s:");
    scanf("%d",&s2);
    for (i=1; s1<s2; i++) {
        s1*=i;
        n++;
    }
    printf("满足n!>=s的最小整数n=%d",n);
    putchar('\n');
    system("PAUSE");
    return 0;
}
