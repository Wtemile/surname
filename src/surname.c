#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define Maxrand 504
#define Max2 60

int count=0;

int menu();
void arand();
void lrand();
void closepro();
void wind_cmd_support_utf8(void);

int main()
{
    wind_cmd_support_utf8();
    int choice=0;
    srand((unsigned int)time(NULL));
    printf("嗨嗨~这里是随机姓氏工具!\n");
    while(1)
    {
        menu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: arand();break;
            case 2: lrand();break;
            case 3: closepro();return 0;
            default:printf("诶诶？我迷路啦......再告诉我一次可以吗？\n");
        }
    }
}

void closepro()
{
    printf("拜拜啦~\n");
    int i=3;
    for(;i>0;i--)
    {
        printf("程序将在%d秒后关闭",i);
        Sleep(1000);
        printf("\r");
    }
    return;
}

void wind_cmd_support_utf8(void)
{
#ifdef WIN32
    system("chcp 65001 & cls"); //cls 用来清除 chcp 的输出               !!!!!!神迹！！！！！
#endif
}

int menu()
{
    printf("-------------------------------\n");
    printf("输入1后回车来生成一个随机姓氏！\n");
    printf("输入2后回车来生成一个随机复姓！\n");
    printf("输入3后回车退出程序\n");
    printf("-------------------------------\n");
    return 0;
}

void lrand()
{
    while(getchar()!='\n');
    while(1)
    {
        int position=rand()%Max2;
        char result[9]={0};
        FILE *fa=fopen("./data/lbjx.txt","r");
        ++count;
        if(!fa) {printf("Warning:Open the file failed!\n"); return;}
        for(int i=1;i<=position;i++)
        fgets(result,9,fa);
        printf("-------------------------------\n");
        printf("第%d次生成结果：《百家姓》中第%d个姓为：%s",count,position,result);
        printf("-------------------------------\n");
        fclose(fa);
        printf("回车继续生成，或输入任一字符返回上一级");
        if(getchar()=='\n') continue;
        else break;
    }
    while(getchar()!='\n'); //清理缓冲区，避免用户输入多字符后被主函数中新的getchar接收
    return;
}

void arand()
{
    while(getchar()!='\n');
    while(1)
    {
        int position=rand()%Maxrand;
        while(!position) position=rand()%Maxrand;  //避免结果为0导致错误
        char result[9]={0};
        FILE *fa=fopen("./data/bjx.txt","r");
        ++count;
        if(!fa) {printf("Warning:Open the file failed!\n"); return;}
        for(int i=1;i<=position;i++)
        fgets(result,9,fa);
        printf("-------------------------------\n");
        printf("第%d次生成结果：《百家姓》中第%d个姓为：%s",count,position,result);
        printf("-------------------------------\n");
        fclose(fa);
        printf("回车继续生成，或输入任一字符返回上一级");
        if(getchar()=='\n') continue;
        else break;
    }
    while(getchar()!='\n'); //清理缓冲区，避免用户输入多字符后被主函数中新的getchar接收
    return;
}
