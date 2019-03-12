//
//  main.c
//  c experiment 6.5
//
//  Created by 林斌 on 2017/5/24.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include"stdlib.h"
int main(void)
{
    long x,k;
    scanf("%ld",&x);
    char *p=(char *)&x;
    char uphalf,lowhalf;
    for (k=0; k<4; k++) {
        lowhalf=(*p)&0x0f;
        if(lowhalf<10)
            lowhalf+='0';
        else
            lowhalf=(lowhalf-10)+'A';
        uphalf=(*p>>4)&0x0f;
        if(uphalf<10)
            uphalf+='0';
        else
            uphalf=(uphalf-10)+'A';
        p++;
        printf("%c    %c    ",uphalf,lowhalf);
    }
    system("PAUSE");
    return 0;
}
