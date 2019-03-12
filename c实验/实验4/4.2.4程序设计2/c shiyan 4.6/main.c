//
//  main.c
//  c shiyan 4.6
//
//  Created by 林斌 on 2017/4/20.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
#define change 0
int main (){
    char c;
    while ((c=getchar())!=EOF){
        if(change){
            if (c>='A'&&c<='Z') c=c+32;}
        printf("%c",c);
    }
    system("PAUSE");
return 0;
}
