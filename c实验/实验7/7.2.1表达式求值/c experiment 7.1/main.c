//
//  main.c
//  c experiment 7.1
//
//  Created by 林斌 on 2017/6/1.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include"stdlib.h"
int main(void) {
    char u[]="UVWXYZ";
    char v[]="xyz";
    struct T{
        int x;
        char c;
        char *t;
    }a[]={{11,'A',u},{100,'B',v}},*p=a;
    //printf("%d\n",(++p)->x);
    //printf("%c\n",(p++,p->c));
    //printf("%c\n",(*p++->t,*p->t));
    //printf("%c\n",*(++p)->t);
    //printf("%c\n",*++p->t);
    printf("%c\n",++*p->t);
    system("PAUSE");
    return 0;
}
