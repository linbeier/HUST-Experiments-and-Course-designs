//
//  main.c
//  c shiyan 2.8
//
//  Created by 林斌 on 2017/4/6.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main(void){
    int i,j,c,m,n=10;
    for (i=0;i<n;i++)
    {
        for (m=0;m<=n-i;m++)
        { printf("  ");}
        for (j=0;j<=i;j++){
            if(j==0)c=1;
            else c=c*(i-j+1)/j;
            printf("%-4d",c);
        }
        printf("\n");
  }
    system("PAUSE");
    return 0;
}
