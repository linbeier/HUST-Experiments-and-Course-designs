#include <stdio.h>
#include <memory.h>
#include <string>
#include <iostream>
#include <stdlib.h>

extern "C"
using namespace std;  
  
//#define currentpath="/Users/bin"

#define GENERAL 1  
#define DIRECTORY 2  
#define  NULL1 0  
  
struct FCB  
{  
    char fname[16]; //文件名  
    char type;      
    int size;    //文件大小  
    int fatherBlockNum;    //当前的父目录盘块号  
    int currentBlockNum;    //当前的盘块  
    int protect[3];     //protect[0]为读取权限
                        //protect[1]为写入权限
                        //protect[2]为运行权限，此处并没有使用到
  
    void initialize()  
    {  
        strcpy(fname,"\0");  
        type =  NULL1;  
        size =0;  
        fatherBlockNum = currentBlockNum = 0;  
        protect[0]=1;
        protect[1]=1;
        protect[2]=1;
    }  
};   
  
/*常量设置*/  
const char* FilePath = "/media/sf_ubuntushare/keshe/5/x.txt";  
const int BlockSize = 1024;       //盘块大小  
const int _OPEN_MAX = 5;          //openlist能打开最多的文件数  
const int BlockCount = 128;   //自己定的磁盘盘块数,不用动态分配  
const int DiskSize = BlockSize*BlockCount;    //磁盘大小  
const int BlockFcbCount = BlockSize/sizeof(FCB);//目录文件的最多FCB数  

/*-----------------文件打开表--------------*/  
int OpenFileCount = 0;  //
  
struct OPENLIST      //用户文件打开表  
{  
    int files;      //当前打开文件数  
    FCB f[_OPEN_MAX];    //FCB拷贝  
    OPENLIST()  
    {  
        files=0;  
        for(int i=0;i<_OPEN_MAX;i++){  
            f[i].fatherBlockNum=-1;//为分配打开  
            f[i].type=GENERAL;  
        }  
    }  
};  
  
/*-------------目录文件结构---------------*/  
struct dirFile  
{  
    struct FCB fcb[BlockFcbCount];  
    void init(int _FatherBlockNum,int _CurrentBlockNum,char *name)//父块号，当前块号，目录名  
    {  
        strcpy(fcb[0].fname,name); //本身的FCB  
        fcb[0].fatherBlockNum=_FatherBlockNum;  
        fcb[0].currentBlockNum=_CurrentBlockNum;  
        fcb[0].type=DIRECTORY;     //标记目录文件  
        for(int i=1;i<BlockFcbCount;i++){  
            fcb[i].fatherBlockNum=_CurrentBlockNum; //标记为子项  
            fcb[i].type= NULL1;    // 标记为空白项  
        }  
    }  
};  
  
/*---------------磁盘结构------------------*/  
struct DISK  
{  
    int FAT1[BlockCount];     //FAT1代表盘块是否被使用  
    int FAT2[BlockCount];     //FAT2  
    struct dirFile root;    //根目录  
//data 不包括前三块,防止误操
    char data[BlockCount-3][BlockSize];  
    void format()  
    {  
        memset(FAT1,0,BlockCount);     //FAT1  
        memset(FAT2,0,BlockCount);     //FAT2  
        FAT1[0]=FAT1[1]=FAT1[2]=-2; //0,1,2盘块号依次代表FAT1,FAT2,根目录区 
// 备份写得有问题,并没有实现
        FAT2[0]=FAT2[1]=FAT2[2]=-2;  //FAT作备份  
        root.init(2,2,"/Users/bin");//根目录区  
        memset(data,0,sizeof(data));//数据区  
    }  
};  
  
  
/*-----------------全局变量--------------------------*/  
FILE *fp;      //磁盘文件地址  
char * BaseAddr;    //虚拟磁盘空间基地址,把磁盘文件读到内存里,保存的时候再写回去  
string currentPath="/Users/bin";   //当前路径  
int current=2;    //当前目录的盘块号  
string cmd;      //输入指令  
struct DISK *osPoint;    //磁盘操作系统指针  
char command[16];    //文件名标识  
struct OPENLIST* openlist; //用户文件列表指针
char username[10];     //用户姓名 
const char *root="root"; 
  
int  format();  
int  mkdir(char *sonfname);  
int rmdir(char *sonfname);  
int create(char *name);  
int listshow();  
int delfile(char *name);  
int changePath(char *sonfname);  
int write(char *name);  
int exit();  
int open(char *file);  
int close(char *file);  
int  read(char *file); 
 
/*------------格式化-----------------------*/  
int format()  
{  
    current = 2;  
    currentPath="/Users/bin";   //当前路径  
    osPoint->format();  
    delete openlist;  
    openlist=new OPENLIST;  
      
    fp = fopen(FilePath,"w+");  
    fwrite(BaseAddr,sizeof(char),DiskSize,fp);  
    fclose(fp);  

    return 1;  
}  
  

int  mkdir(char *sonfname)  
{  
    
    int i,temp,iFAT;  
    struct dirFile *dir;     //当前目录的指针  
    if(current==2)  
        dir=&(osPoint->root);  
    else  
        dir=(struct dirFile *)(osPoint->data [current-3]);  
      
    for(i = 1;i<BlockFcbCount;i++)  
    {  
        if(dir->fcb[i].type==DIRECTORY && strcmp(dir->fcb[i].fname,sonfname)==0 )  
        {  
            printf("该文件夹下已经有同名的文件夹存在了!\n");  
            return 0;  
        }  
    }  
    //查找空白fcb序号  
    for(i=1;i<BlockFcbCount;i++)  
    {  
        if(dir->fcb[i].type== NULL1)  
            break;  
    }  
  
    if(i==BlockFcbCount)  
    {  
        printf("该目录已满!请选择新的目录下创建!\n");  
        return 0;  
    }  
  
    temp=i;  
  
    for(i = 3;i < BlockCount;i++)  
    {  
        if(osPoint->FAT1[i] == 0)  
            break;  
    }  
  
    if(i == BlockCount)  
    {  
        printf("磁盘已满!\n");  
        return 0;  
    }  
  
    iFAT=i;  
  
    osPoint->FAT1[iFAT]=osPoint->FAT2[iFAT] = 2;   //2表示分配给下级目录文件  

    strcpy(dir->fcb[temp].fname,sonfname);  
    dir->fcb[temp].type=DIRECTORY;  
    dir->fcb[temp].fatherBlockNum=current;  
    dir->fcb[temp].currentBlockNum=iFAT;  

    dir=(struct dirFile*)(osPoint->data [iFAT-3]);     
    dir->init (current,iFAT,sonfname);//iFAT是要分配的块号，这里的current用来指要分配的块的父块号  

    return 1;  
}  
  
    
int rmdir(char *sonfname)  
{  
  
    int i,temp,j;//确保当前目录下有该文件,并记录下该FCB下标  
    struct dirFile *dir;     //当前目录的指针  
    if(current==2)  
        dir=&(osPoint->root);  
    else  
        dir=(struct dirFile *)(osPoint->data [current-3]);  
  
    for(i=1;i<BlockFcbCount;i++)  
    {       
        if(dir->fcb[i].type==DIRECTORY && strcmp(dir->fcb[i].fname,sonfname)==0)  
        {  
            break;  
        }  
    }  
  
    temp=i;  
  
    if(i==BlockFcbCount)  
    {  
        printf("当前目录下不存在该子目录!\n");  
        return 0;  
    }  
  
    j = dir->fcb[temp].currentBlockNum; //文件夹所在磁盘块 
    struct dirFile *sonDir;     //该文件夹目录的指针  
    sonDir=(struct dirFile *)(osPoint->data [ j - 3]);  
  
    for(i=1;i<BlockFcbCount;i++)  //查找子目录是否为空目录  
    {  
        if(sonDir->fcb[i].type!= NULL1)  
        {  
            printf("该文件夹为非空文件夹,为确保安全，请清空后再删除!\n");  
            return 0;  
        }  
    }  
      
    osPoint->FAT1[j] = osPoint->FAT2[j]=0;     //fat清空  
    char *p=osPoint->data[j-3];      //格式化子目录  
    memset(p,0,BlockSize);  
    dir->fcb[temp].initialize();          //清空  

    return 1;  
}  
  

int create(char *name)  
{  
    int i,iFAT; 
    int emptyNum = 0,isFound = 0;          
    struct dirFile *dir;     //当前目录的指针  
    if(current==2)  
        dir=&(osPoint->root);  
    else  
        dir=(struct dirFile *)(osPoint->data [current-3]);  
  
    for(i=1;i<BlockFcbCount;i++)  
    {  
        if(dir->fcb[i].type ==  NULL1 && isFound == 0)  
        {  
            emptyNum = i;  
            isFound = 1;  
        }  
        else if(dir->fcb[i].type==GENERAL && strcmp(dir->fcb[i].fname,name)==0 )  
        {  
            printf("无法在同一目录下创建同名文件!\n");  
            return 0;  
        }  
    }  
  
    if(emptyNum == 0)  
    {  
        printf("已经达到目录项容纳上限，无法创建新目录!\n");  
        return 0;  
    }  
  
    //查找FAT表寻找空白块，用来分配磁盘块号j  
    for(i = 3;i<BlockCount;i++)  
    {  
        if(osPoint->FAT1[i]==0)  
            break;  
    }  
    if(i==BlockCount)  
    {  
        printf("磁盘已满!\n");  
        return 0;  
    }  
    iFAT=i;  
  
    osPoint->FAT1[iFAT] = osPoint->FAT2[iFAT] = 1;  

    //权限选择
    printf("该文件是否可读？（0：不可读 1：可读）：\n");
    scanf("%d",&(dir->fcb[emptyNum].protect[0]));
    printf("该文件是否可写？（0：不可写 1：可写）：\n");
    scanf("%d",&(dir->fcb[emptyNum].protect[1]));
    printf("该文件是否可执行？（0：不可执行 1：可执行）（不重要）：\n");
    scanf("%d",&(dir->fcb[emptyNum].protect[2]));
    strcpy(dir->fcb[emptyNum].fname,name);  
    dir->fcb[emptyNum].type=GENERAL;  
    dir->fcb[emptyNum].fatherBlockNum=current;  
    dir->fcb[emptyNum].currentBlockNum=iFAT;  
    dir->fcb[emptyNum].size =0;  
    char* p = osPoint->data[iFAT -3];  
    memset(p,4,BlockSize);  
  
    return 1;  
}  
  

int listshow()  
{  
    int i,DirCount=0,FileCount=0;  

    struct dirFile *dir;     //当前目录的指针  
    if(current==2)  
        dir=&(osPoint->root);  
    else  
        dir=(struct dirFile *)(osPoint->data [current-3]);  
  
    for(i=1;i<BlockFcbCount;i++)  
    {  
        if(dir->fcb[i].type==GENERAL)  
        {     
            FileCount++;  
            printf("%s     文本文件.\n",dir->fcb[i].fname);  
        }  
        if(dir->fcb[i].type==DIRECTORY)  
        {     
            DirCount++;  
            printf("%s     文件夹.\n",dir->fcb[i].fname);  
        }  
    }  
    printf("\n该目录下共有 %d 个文本文件, %d 个文件夹\n\n",FileCount,DirCount);  
 
    return 1;  
}  
  
  
  
 
int delfile(char *name)  
{  
    int i,temp,j;  
      
    struct dirFile *dir;     //当前目录的指针  
    if(current==2)  
        dir=&(osPoint->root);  
    else  
        dir=(struct dirFile *)(osPoint->data [current-3]);  
  
    for(i=1;i<BlockFcbCount;i++) //查找该文件  
    {  
        if(dir->fcb[i].type==GENERAL && strcmp(dir->fcb[i].fname,name)==0)  
        {  
            break;  
        }  
    }  
  
    if(i==BlockFcbCount)  
    {  
        printf("当前目录下不存在该文件!\n");  
        return 0;  
    }  
  
    int k;  
    for(k=0;k<_OPEN_MAX;k++)  
    {  
        if((openlist->f [k].type = GENERAL)&&  
            (strcmp(openlist->f [k].fname,name)==0))  
        {  
            if(openlist->f[k].fatherBlockNum == current)  
            {  
                break;  
            }  
            else  
            {  
                printf("该文件未在当前目录下!\n");  
                return 0;  
            }  
        }  
    }  
  
    if(k!=_OPEN_MAX)  
    {  
        close(name);  
    }  
  
    //从打开列表中删除  
      
    temp=i;  
 
    j = dir->fcb [temp].currentBlockNum ;    //查找盘块号j  
    osPoint->FAT1[j]=osPoint->FAT2[j]=0;     //fat1,fat2表标记为空白  
    char *p=osPoint->data[j - 3];  
    memset(p,0,BlockSize); //清除原文本文件的内容  
    dir->fcb[temp].initialize();    //标记该目录项为空文件    
    return 1;  
}  
  
  
  
int changePath(char *sonfname)  
{  
    struct dirFile *dir;     //当前目录的指针  
    if(current==2)  
        dir=&(osPoint->root);  
    else  
        dir=(struct dirFile *)(osPoint->data [current-3]);  
    //回到父目录  
    if(strcmp(sonfname,"..")==0)  
    {  
        if(current==2)  
        {  
            printf("你现已经在根目录下!\n");  
            return 0;  
        }  
        current = dir->fcb[0].fatherBlockNum ;  
        currentPath = currentPath.substr(0,currentPath.size() - strlen(dir->fcb[0].fname )-1);  
        return 1;  
    }  
  
    int i,temp;  
    //确保当前目录下有该目录,并且记录下它的FCB下标  
    for(i = 1; i < BlockFcbCount; i++)  
    {      
        if(dir->fcb[i].type==DIRECTORY && strcmp(dir->fcb[i].fname,sonfname)==0 )  
        {  
            temp=i;  
            break;  
        }  
    }  
  
    if(i==BlockFcbCount)  
    {  
        printf("不存在该目录!\n");  
        return 0;  
    }  
  
    //修改当前文件信息  
    current=dir->fcb [temp].currentBlockNum ;  
    currentPath = currentPath+dir->fcb [temp].fname +"/";  

    return 1;  
}  
  
 
int exit()  
{  
  
    fp=fopen(FilePath,"w+");  
    fwrite(BaseAddr,sizeof(char),DiskSize,fp);  
    fclose(fp);  
    //释放内存上的虚拟磁盘  
    free(osPoint);  
    //释放用户打开文件表  
    delete openlist;  
    return 1;  
}  
  
 
int write(char *name)  
{  
    int i;  
    char *startPoint,*endPoint;  
    //在打开文件列表中查找 file(还需要考虑同名不同目录文件的情况!!!)  
    for(i=0;i<_OPEN_MAX;i++)  
    {  
        if(strcmp(openlist->f [i].fname,name)==0 )  
        {  
            if(openlist->f[i].fatherBlockNum ==current)  
            {  
                break;  
            }  
            else  
            {  
                printf("该文件处于打开列表中，本系统只能改写当前目录下文件!\n");  
                return 0;  
            }  
        }  
    }  
  
    if(i==_OPEN_MAX)  
    {  
        printf("该文件尚未打开,请先打开后写入信息!!\n");  
        return 0;  
    }  
  
    
    int active=i;  
    if(openlist->f[active].protect[1]!=1&&strcmp(username,root)!=0)
    {
        printf("您的权限不能修改该文件\n");
        return 0;
    }
    int fileStartNum = openlist->f[active].currentBlockNum - 3 ;  
    startPoint = osPoint->data[fileStartNum];  
    endPoint = osPoint->data[fileStartNum + 1];  
  
    printf("请输入文本以$号结束:\t");  
  
    char input;  
    while(((input=getchar())!='$'))  
    {  
        if(startPoint < endPoint-1)  
        {  
            *startPoint++ = input;  
        }  
        else  
        {  
            printf("达到单体文件最大容量！");  
            *startPoint++ = 4;  
            break;  
        }  
    }  
    return 1;  
}  
  
  
int  read(char *file)  
{  
    int i,fileStartNum;  
    char *startPoint,*endPoint;  
 
    //在打开文件列表中查找 file(还需要考虑同名不同目录文件的情况!!!)  
    for(i=0;i<_OPEN_MAX;i++)  
    {  
        if(strcmp(openlist->f [i].fname,file)==0 )  
        {  
            if(openlist->f[i].fatherBlockNum ==current)  
            {  
                break;  
            }  
            else  
            {  
                printf("该文件处于打开列表中，本系统只能阅读当前目录下文件!\n");  
                return 0;  
            }  
        }  
    }  
  
    if(i==_OPEN_MAX)  
    {  
        printf("该文件尚未打开,请先打开后读取信息!\n");  
        return 0;  
    }  
    int active=i;  
    if(openlist->f[active].protect[0]!=1&&strcmp(username,root)!=0)
    {
        printf("您的权限不能读取该文件\n");
        return 0;
    }
    //计算文件物理地址  
    fileStartNum = openlist->f[active].currentBlockNum - 3 ;  
    startPoint = osPoint->data[fileStartNum];  
    endPoint = osPoint->data[fileStartNum + 1];  
  
    printf("该文件的内容为:  ");  
    while((*startPoint)!=4&& (startPoint < endPoint))  
    {  
        putchar(*startPoint++);  
    }  
  
  
    printf("\n");  
    return 1;  
  
  
}  

int open(char *file) 
{  
    int i,FcbIndex;  
     
    for(i=0;i<_OPEN_MAX;i++)  
    {  
        if(openlist->f[i].type ==GENERAL && strcmp(openlist->f [i].fname,file)==0 &&openlist->f[i].fatherBlockNum == current)  
        {  
            printf("该文件已经被打开!\n");  
            return 0;  
        }  
    }  
  
     
    if(openlist->files == _OPEN_MAX)  
    {  
        printf("打开文件数目达到上限!无法再打开新文件.\n");  
        return 0;  
    }  
  
    //确保当前目录下有该文件,并且记录下它的FCB下标  
    struct dirFile *dir;      
    if(current==2)  
        dir=&(osPoint->root);  
    else  
        dir=(struct dirFile *)(osPoint->data [current-3]);  
  
    for(i = 1;i< BlockFcbCount;i++)  
    {       
        if(dir->fcb[i].type==GENERAL && strcmp(dir->fcb[i].fname,file)==0 )  
        {  
            FcbIndex=i;  
            break;  
        }  
    }  
  
    if(i==BlockFcbCount)  
    {  
        printf("当前目录下不存在该文件!\n");  
        return 0;  
    }  
  
    //装载新文件进入打开文件列表,(FCB信息，文件数++)   
    openlist->f[OpenFileCount] = dir->fcb[FcbIndex]; //FCB拷贝  
    openlist->files ++;  
    printf("文件打开成功!\n");  
    OpenFileCount++;  
    return 1;  
}  
  
int close(char *file)  
{  
    
    int i;  
    //在打开文件列表中查找 file(还需要考虑同名不同目录文件的情况!!!)  
    for(i=0;i<_OPEN_MAX;i++)  
    {  
        if((openlist->f [i].type = GENERAL)&&  
            (strcmp(openlist->f [i].fname,file)==0))  
        {  
            if(openlist->f[i].fatherBlockNum == current)  
            {  
                break;  
            }  
            else  
            {  
                printf("该文件已打开，但未在当前目录下，无法关闭!\n");  
                return 0;  
            }  
        }  
    }  
  
    if(i==_OPEN_MAX)  
    {  
        printf("该文件未在打开列表中!\n");  
        return 0;  
    }  
  
    int active=i;  
    openlist->files --;  
    openlist->f[active].initialize();  
    OpenFileCount--;  
    printf("该文件已关闭!\n");  
    return 1;  
}  
  
int main()  
{  
    
    printf("-----Welcome To My Operate System Of File-----\n");   
    printf("请您登陆：");
    scanf("%s",username);
    //printf("%s",username);
    system("clear");
    printf("您好，用户%s\n",username);
    printf("\n  以下是使用说明书：\n");  
    printf("--------------------------------------------------------------\n");  
    printf("|| format :对磁盘格式化.                           || \n");  
    printf("|| exit   :安全退出该文件系统,保存信息.            || \n");  
    printf("|| mkdir dirname :创建子目录.                      || \n");  
    printf("|| rmdir dirname :删除子目录.                      || \n");  
    printf("|| ls    dirname :显示当前目录下信息.              || \n");  
    printf("|| cd     dirname :更改当前目录.                   || \n");  
    printf("|| create filename :创建一个新文件,并且打开.       || \n");  
    printf("|| write filename :选择一个打开的文件写入信息      || \n");  
    printf("|| read   filename :选择一个打开的文件读取信息.    || \n");  
    printf("|| rm     filename :删除文件.                      || \n");  
    printf("|| open   filename :打开文件.                      || \n");  
    printf("|| close filename :关闭文件.                       || \n");  
    printf("-------------------------------------------------------------\n\n");  
    //创建用户文件打开表  
    openlist=new OPENLIST;  
    //申请虚拟空间并且初始化  
    BaseAddr=(char *)malloc(DiskSize);  
    //虚拟磁盘初始化  
    osPoint=(struct DISK *)(BaseAddr);  
    //加载磁盘文件  
    if((fp=fopen(FilePath,"r"))!= NULL){  
        fread(BaseAddr,sizeof(char),DiskSize,fp);  
        printf("加载磁盘文件( %s )成功,现在可以进行操作了!\n\n",FilePath);  
    }  
    else{  
        printf("这是你第一次使用该文件管理系统!\t正在初始化...\n");  
        format();  
        printf("初始化已经完成,现在可以进行操作了!\n\n");  
    }  

    while(1){  
        cout<<currentPath;  
        cin>>cmd;  
        if(cmd=="format"){  
            format();  
        }  
        else if(cmd=="mkdir"){  
            cin>>command;  
            mkdir(command);  
        }  
        else if(cmd=="rmdir"){  
            cin>>command;  
            rmdir(command);  
        }  
        else if(cmd=="ls"){  
            listshow();  
        }  
        else if(cmd=="cd"){  
            cin>>command;  
            changePath(command);  
        }  
        else if(cmd=="create"){  
            cin>>command;  
            create(command);  
        }  
  
        else if(cmd=="write"){  
            cin>>command;  
            write(command);  
        }  
        else if(cmd=="read"){  
            cin>>command;  
            read(command);  
        }  
        else if(cmd=="rm"){  
            cin>>command;  
            delfile(command);  
        }  
        else if(cmd=="open"){  
            cin>>command;  
            open(command);  
        }  
        else if(cmd=="close"){  
            cin>>command;  
            close(command);  
        }  
        else if(cmd=="exit"){  
            exit();  
            break;  
        }  
        else cout<<"无效指令,请重新输入:"<<endl;  
    }  
    printf("Thank you for using my file system!\n");  
    return 0;
}  
