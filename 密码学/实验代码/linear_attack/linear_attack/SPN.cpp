//
//  main.cpp
//  originalSPNnetwork
//
//  Created by 林斌 on 2018/8/7.
//  Copyright © 2018年 林斌. All rights reserved.
//

#include "math.h"
#include "stdlib.h"
#include <stdio.h>
#include <string.h>
#include "time.h"


#define T 8000

int K[5][16];
int s[16]={14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7};	//s盒
int s_1[16]={14,3,4,8,1,12,10,15,7,13,9,6,11,2,0,5};	//s盒的逆
int p[16]={0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15};	//p盒
int p_1[16]={0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15};  //p盒的逆
int t[32]={0,0,1,1, 1,0,1,0, 1,0,0,1, 0,1,0,0, 1,1,0,1, 0,1,1,0, 0,0,1,1, 1,1,1,1};


void Key(int *t)	//密钥
{
    int i,j;
    for(i=0;i<5;i++)
        for(j=0;j<16;j++)
            K[i][j]=t[i*4+j];
}

int BinarytoDecmical(int b[],int len){    //将4位2进制转化为十进制
    int i=0,s=0;
    while(i<len)
    {
        s=s*2+b[i];
        i++;
    }
    return s;
    
}
void DecmicaltoBinary(int dec,int *bit){   //将一个十进制转化为4位2进制
    int len=0;
    int i,t[4];
    while(dec!=0)
    {
        t[len]=dec%2;
        len++;
        dec=dec/2;
    }
    if (len==4) {
        for(i=0;i<4;i++)
            bit[i]=t[3-i];
    }
    else if(len<4){
        
        for (i=len; i<4; i++)
            t[i]=0;
        
        for(i=0;i<4;i++)
            bit[i]=t[3-i];

    }
    else printf("转化的十进制超过16\n");
}

void DecmicaltoBinary_8bits(int dec,int *bit){   //将一个十进制转化为8位2进制
    int len=0;
    int i,t[8];
    while(dec!=0)
    {
        t[len]=dec%2;
        len++;
        dec=dec/2;
    }
    if (len==8) {
        for(i=0;i<4;i++)
            bit[i]=t[7-i];
    }
    else if(len<8){
        
        for (i=len; i<8; i++)
            t[i]=0;
        
        for(i=0;i<8;i++)
            bit[i]=t[7-i];
        
    }
    else printf("转化的十进制超过16\n");
}


void whitening(int *w,int *k,int *u){    //此处输入中原w为10进制数组，密钥k为16位2进制数组，u是白化后输出的2进制数组（16位）
    int i;
    int bitw[16];
    //int bitu[16];
    for (i=0; i<4; i++) {
        DecmicaltoBinary(w[i],bitw+4*i);
    }
    
    for (i=0; i<16; i++) {
        u[i]=bitw[i]^k[i];
    }
    
}
void key_create(int key_rand[][16]){
    //将顺序生成的8位二进制数依次填入key的第二盒和第四盒
    int num[8];
    int i,j;
    
    for (i=0; i<256; i++) {
        DecmicaltoBinary_8bits(i, num);
        for (j=4; j<8; j++) {
            key_rand[i][j]=num[j-4];
        }
        for (j=12; j<16; j++) {
            key_rand[i][j]=num[j-8];
        }
    }
    
}
void Substitution(int u[]){      //置换16位输入数组u
    //int u[16]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};  //test
    int i;
    int temp[4];
    for (i=0; i<4;i++) {
        temp[i]=BinarytoDecmical(u+4*i, 4);
    }
    for (i=0; i<4; i++) {
        temp[i]=s[(temp[i])];
    }
    for (i=0; i<4; i++) {
        DecmicaltoBinary(temp[i], u+4*i);
    }
    /*for (i=0; i<16; i++) {
        printf(" %d",u[i]);
    }*/
}


void Permutation(int *v){  //输入为16位2进制数组
    //int v[16]={0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,1};  //test
    int temp[16];
    for (int i=0; i<16; i++) {
        temp[(p[i])]=v[i];
    }
    for (int i=0; i<16; i++) {
        v[i]=temp[i];
    }
    //for (int i=0; i<16; i++)
    //   printf(" %d",v[i]);
}
void Permutation_1(int *v){  //输入为16位2进制数组
    //int v[16]={0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,1};  //test
    int temp[16];
    for (int i=0; i<16; i++) {
        temp[(p_1[i])]=v[i];
    }
    for (int i=0; i<16; i++) {
        v[i]=temp[i];
    }
    //for (int i=0; i<16; i++)
    //   printf(" %d",v[i]);
}

void SPNnetwork(int *x,int *y){    //输入为2进制的16位明文数组
    
    int u[4][16];
    
    //初始化密钥
    Key(t);
    for (int i=0; i<16; i++) {
        u[0][i] = x[i];
    }
    //此处i表示不同的轮数
    for (int i=0; i<4; i++) {
        
        if (i>0&&i<4) {
            for (int j=0; j<16; j++) {
                u[i][j]=u[i-1][j];
            }
        }
        //此处为白化操作
        for (int j=0; j<16; j++)
            u[i][j] = u[i][j]^K[i][j];
        //此处为代换操作
        Substitution(u[i]);
        //此处为置换操作,若此时为第4轮则不进行置换操作
        if(i<3) Permutation(u[i]);
        
        
    }
    
    //最后一轮输出密文
    for (int i=0; i<16; i++) {
        y[i] = u[3][i]^K[4][i];
    }
    
}

void x_create(int x_rand[T][16]){
    
    int i,j;
    srand((unsigned)time(NULL));
    for (i=0; i<T; i++) {
        for (j=0; j<16; j++) {
            x_rand[i][j]=rand()%2;
        }
    }
}


void writeintoFile(int plaintext[][16],FILE *fp,int len){
    
    if (fp==NULL) {
        printf("cannot open the file !");
    }
    for (int i=0; i<len; i++) {
        for (int j=0; j<16; j++) {
            fprintf(fp,"%d",plaintext[i][j]);
            //fprintf(fp, "1");
        }
        fprintf(fp, "\n");
    }
    //fprintf(fp, "\n\n\n");
}


int main_1() {
    FILE *fp_x;
    FILE *fp_y;
    FILE *fp_key;
    
    fp_x = fopen("/Users/bin/Desktop/SPNnetwork/originalSPNnetwork/originalSPNnetwork/x.txt","w+");
    fp_y = fopen("/Users/bin/Desktop/SPNnetwork/originalSPNnetwork/originalSPNnetwork/y.txt","w+");
    fp_key = fopen("/Users/bin/Desktop/SPNnetwork/originalSPNnetwork/originalSPNnetwork/key.txt", "w+");
    
    int x[16]={0,0,1,0,0,1,1,0,1,0,1,1,0,1,1,1};
    int y[16];
    //int count[256];
    //int count_max = 0;
    //int flag = 0;
    
    int x_rand[T][16];
    int y_rand[T][16];
    int key_rand[256][16]={0};
    
    x_create(x_rand);
    key_create(key_rand);
    
    
    //将明文加密
    for (int i=0; i<T; i++) {
        SPNnetwork(x_rand[i], y_rand[i]);
    }
    
    
    //写入文件
    writeintoFile(key_rand, fp_key,256);
    writeintoFile(x_rand,fp_x,T);
    writeintoFile(y_rand,fp_y,T);
    
    //教材基本SPN演示
    SPNnetwork(x, y);
    printf("\n教材SPN网络演示：\n");
    printf("x:");
    for (int i=0; i<16; i++) {
        printf(" %d",x[i]);
    }
    printf("\ny:");
    for (int i=0; i<16; i++) {
        printf(" %d",y[i]);
    }

    fclose(fp_x);
    fclose(fp_y);
    fclose(fp_key);
    return 0;
}

