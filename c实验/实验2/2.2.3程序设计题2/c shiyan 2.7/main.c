//
//  main.c
//  c shiyan 2.7
//
//  Created by 林斌 on 2017/4/6.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
enum{copy,start,space};
int main(void)
{
    char c;
    int state=copy;
    printf("please input chars:\n");
    while ((c=getchar())!=EOF)
           switch(state) {
        case copy:
                   if(c==' ')state=start;
                   else putchar(c);
                   break;
        case start:
                   putchar(' ');
                   if(c==' ')state=space;
                   else {state=copy;
                       putchar(c);}
                   break;
        case space:
                   if (c!=' ') {
                       state=copy;
                       putchar(c);
                   }else state=space;
                   break;
    }
    system("PAUSE");
    return 0;
}
