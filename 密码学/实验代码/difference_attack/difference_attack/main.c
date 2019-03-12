//
//  main.c
//  difference_attack
//
//  Created by 林斌 on 2018/8/31.
//  Copyright © 2018年 林斌. All rights reserved.
//

#include <stdio.h>
#include "math.h"
#include "stdlib.h"
#include <string.h>
#include <time.h>


#define T 8000


int K[5][16];
int s[16]={14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7};	//s盒
int s_1[16]={14,3,4,8,1,12,10,15,7,13,9,6,11,2,0,5};	//s盒的逆
int p[16]={0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15};	//p盒
int p_1[16]={0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15};  //p盒的逆
//int t[32]={0,0,1,1, 1,0,1,0, 1,0,0,1, 0,1,0,0, 1,1,0,1, 0,1,1,0, 0,0,1,1, 1,1,1,1};
int num_key = 0;

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
        for(i=0;i<8;i++)
            bit[i]=t[7-i];
    }
    else if(len<8){
        
        for (i=len; i<8; i++)
            t[i]=0;
        
        for(i=0;i<8;i++)
            bit[i]=t[7-i];
        
    }
    else printf("转化的十进制超过256\n");
}

void DecmicaltoBinary_24bits(int dec,int *bit){   //将一个十进制转化为24位2进制
    int len=0;
    int i,t[24];
    while(dec!=0)
    {
        t[len]=dec%2;
        len++;
        dec=dec/2;
    }
    if (len==24) {
        for(i=0;i<24;i++)
            bit[i]=t[23-i];
    }
    else if(len<24){
        
        for (i=len; i<24; i++)
            t[i]=0;
        
        for(i=0;i<24;i++)
            bit[i]=t[23-i];
        
    }
    else printf("转化的十进制超过2^24-1\n");
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

void SPNnetwork(int *x,int *y,int *key){    //输入为2进制的16位明文数组
    
    int u[4][16];
    
    //初始化密钥
    Key(key);
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


void Substitution_1(int u[]){      //置换16位输入数组u
    //int u[16]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};  //test
    int i;
    int temp[4];
    for (i=0; i<4;i++) {
        temp[i]=BinarytoDecmical(u+4*i, 4);
    }
    
    for (i=0; i<4; i++) {
        temp[i]=s_1[(temp[i])];
    }
    
    for (i=0; i<4; i++) {
        DecmicaltoBinary(temp[i], u+4*i);
    }
    /*for (i=0; i<16; i++) {
     printf(" %d",u[i]);
     }*/
}

void key_create_24(int key_rand[]){
    //将顺序生成的24位二进制数依次填入key的剩余位置
    int num[24];
    int j;
    
    DecmicaltoBinary_24bits(num_key, num);
    
    for (j=0; j<20; j++) {
        key_rand[j]=num[j];
    }
    
    for (j=24; j<28; j++) {
        key_rand[j]=num[j-4];
    }
    
    num_key++;
    
}


int difference_attack(int key[],int y_in[][16],int y_in_xing[][16]){
    int count=0;
    int v[16];
    int v_xing[16];
    int z_pie[16];
    int z=0,i,j,p;
    int module[4]={0,1,1,0};
    for (i=0; i<T; i++) {
        for (j=0; j<16; j++) {
            v[j]=key[j]^y_in[i][j];
            v_xing[j]=key[j]^y_in_xing[i][j];
        }
        Substitution_1(v);
        Substitution_1(v_xing);
        for (p=0; p<16; p++) {
            z_pie[p]=v[p]^v_xing[p];
        }
        for (j=4; j<8; j++) {
            if (!(z_pie[j]==module[j-4])) {
                z=1;
                break;
            }
        }
        for (j=12; j<16; j++) {
            if (!(z_pie[j]==module[j-12])) {
                z=1;
                break;
            }
        }
        if (!z) {
            count++;
        }
        //重新初始化z
        z=0;
    }
    return count;
}


void readfromFile(int plaintext[][16],FILE *fp,int len){
    char c;
    if (fp==NULL) {
        printf("cannot open the file !");
    }
    for (int i=0; i<len; i++) {
        for (int j=0; j<16; j++) {
            fscanf(fp, "%c",&c);
            plaintext[i][j]=atoi(&c);
            //fprintf(fp, "1");
        }
        fgetc(fp);
    }
    
}
int  same(int *y1,int *y2){
    for (int i=0; i<16; i++) {
        if (y1[i]!=y2[i]) return 0;
    }
    return 1;
}


int main() {
    
    FILE *fp_x;
    FILE *fp_y;
    FILE *fp_key;
    
    fp_x = fopen("/Users/bin/Desktop/SPNnetwork/originalSPNnetwork/originalSPNnetwork/x.txt","r+");
    fp_y = fopen("/Users/bin/Desktop/SPNnetwork/originalSPNnetwork/originalSPNnetwork/y.txt","r+");
    fp_key = fopen("/Users/bin/Desktop/SPNnetwork/originalSPNnetwork/originalSPNnetwork/key.txt", "r+");
    
    int count[256];
    int count_max = 0;
    int flag = 0;
    long int bit24 = pow(2,24);
    int flag_findkey=0;
    int original_key[32]={0,0,1,1, 1,0,1,0, 1,0,0,1, 0,1,0,0, 1,1,0,1, 0,1,1,0, 0,0,1,1, 1,1,1,1};
    
    int x_pie[16]={0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0};
    int x_rand[T][16];
    int x_xing[T][16];
    int y_rand[T][16];
    int y_xing[T][16];
    int key_rand[256][16]={0};
    int key_count[32];
    int y_test[16];
    int y_randtest[T][16];
    clock_t start,end;
    
    
    //读取文件中的xy
    readfromFile(x_rand, fp_x, T);
    readfromFile(y_rand, fp_y, T);
    readfromFile(key_rand, fp_key, 256);
    
    //从x中产生x_*
    for (int i=0; i<T; i++) {
        for (int j=0; j<16; j++) {
            x_xing[i][j]=x_pie[j]^x_rand[i][j];
        }
    }
    //将x*加密为y*
    for (int i=0; i<T; i++) {
        SPNnetwork(x_xing[i], y_xing[i], original_key);
    }
    
    //差分攻击
    start=clock();
    for (int i=0; i<256; i++) {
        count[i]=difference_attack(key_rand[i], y_rand, y_xing);
    }
    for (int i=0; i<256; i++) {
        if (count[i]>count_max) {
            count_max=count[i];
            flag=i;
        }
    }
    for (int i=0; i<16; i++) {
        key_count[i+16]=key_rand[flag][i];
    }
    end=clock();
    printf("差分分析用时：%g\n",(double)(end-start)/CLOCKS_PER_SEC);
    //穷举攻击
    start=clock();
    for (int i=0; i<bit24; i++) {
        
        //将剩余24位填入key_count中，每次调用key_create_24会让填充的数字加1
        key_create_24(key_count);
        //将32位密钥中填入线性攻击得出的密钥
        for (int j=0; j<32; j++) {
            
            if ((j<32&&j>=28)||(j<24&&j>=20)) {
                key_count[j]=key_rand[flag][j-16];
            }
            //if (j<24&&j>=20) {
            //    key_count[j]=key_rand[flag][j-16];
            //}
        }
        SPNnetwork(x_rand[0], y_test, key_count);
        
        if (same(y_test, y_rand[0])) {
            SPNnetwork(x_rand[1], y_test, key_count);
            
            if (same(y_test, y_rand[1])) {
                SPNnetwork(x_rand[2], y_test, key_count);
                
                if (same(y_test,y_rand[2])) break;
            }
        }
    }
    end=clock();
    printf("穷举剩余24位用时：%g\n",(double)(end-start)/CLOCKS_PER_SEC);
    //对照全部y
    for (int i=0; i<T; i++) {
        SPNnetwork(x_rand[i],y_randtest[i], key_count);
    }
    for (int i=0; i<T; i++) {
        if(!same(y_randtest[i], y_rand[i])){
            flag_findkey=1;
            break;
        }
    }
    //输出破解出的密钥
    if (flag_findkey==0) {
        for (int i=0; i<32; i++) {
            printf(" %d",key_count[i]);
        }
    }
    else printf("cann't find the flag\n");
    
    fclose(fp_x);
    fclose(fp_y);
    fclose(fp_key);
    return 0;
}
