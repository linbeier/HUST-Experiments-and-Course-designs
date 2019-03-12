//
//  main.c
//  c experiment 5.5
//
//  Created by 林斌 on 2017/4/27.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include"stdlib.h"
int main(void) {
    unsigned a;
    int j,i,b[20];
    printf("Please input an unsigned integer:\n");
    scanf("%u",&a);
    for (i=0; i<20; i++) {
        b[i]=a&(0x0001);
        a>>=1;
    }
    for (j=19;j>=0; j--) {
        printf("%d",b[j]);
        
    }
    system("pause");
    return 0;
}
