//
//  main.c
//  c shiyan 2.2
//
//  Created by 林斌 on 2017/4/6.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i=1,n;
    long s=1;
    printf("Please enter n:");
    scanf("%d",&n);
    while (i<=n) {
        s*=i;
        i++;
    }
    printf("%d!=%d",n,s);
    putchar('\n');
    system("PAUSE");
    return 0;
}

