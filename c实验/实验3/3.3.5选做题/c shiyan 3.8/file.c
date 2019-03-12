//
//  file.c
//  c shiyan 3.8
//
//  Created by 林斌 on 2017/4/13.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include "file.h"
#include"stdlib.h"
int x,y;
char ch;
int main(void)
{
    x=10;
    y=20;
    ch=getchar();
    printf("in file1 x=%d,y=%d,ch is %c\n",x,y,ch);
    func1();
    system("PAUSE");
    return 0;
}
