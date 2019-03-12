//
//  main.c
//  c experiment 5.8
//
//  Created by 林斌 on 2017/6/4.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "stdlib.h"
#define max 8
int i,a[max],sum=0;
void show(){
    int i;
    for (i=0; i<max; i++) {
        printf("(%d,%d) ",i,a[i]);
    }
    printf("\n");
    sum++;
}
int check(int n){
    int i;
    for (i=0; i<n; i++) {
        if ((a[i]==a[n])||(abs(a[i]-a[n])==(n-i))) return 1;
    }
    return 0;
}
void put(int n){
    int i;
    for (i=0; i<max; i++)
    {
        a[n]=i;
        if (!check(n))
        {
            if (n==max-1) show();
            else put(n+1);
        }
    }
}
int main() {
    put(0);
    printf("\n%d\n",sum);
    return 0;
}
