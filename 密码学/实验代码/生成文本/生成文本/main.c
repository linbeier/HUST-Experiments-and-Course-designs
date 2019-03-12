//
//  main.c
//  生成文本
//
//  Created by 林斌 on 2018/9/4.
//  Copyright © 2018年 林斌. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
#include "time.h"
#include "string.h"

#define T 80000

int main() {
    //int i,j;
    int x[128];
    char xx[128]={0};
    srand((unsigned)time(NULL));
    FILE *fp;
    fp = fopen("/Users/bin/Desktop/SPNnetwork/生成文本/生成文本/x.txt", "w+");
    for (int i=0; i<T; i++) {
        
        for (int j=0; j<128; j++) {
            //xx[j]=xx[j]&&0;
            fprintf(fp,"%c",xx[j]);
        }
    }
    fclose(fp);
    return 0;
}
