//
//  file2.c
//  c shiyan 3.8
//
//  Created by 林斌 on 2017/4/13.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include "file.h"
extern int x,y; /* 外部变量的引用性说明 */
extern char ch; /* 外部变量的引用性说明 */
void func1(void)
{
    x++;
    y++;
    ch++;
    printf("in file2 x=%d,y=%d,ch is %c\n",x,y,ch);
}
