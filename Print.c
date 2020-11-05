#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************
**函数名：Print
**i,j---计数器
**功能描述：遍历传入的long型数组，int型数组，char型数组并将各元素打印出来
****************/
void Print(long number[],int AllScores[],int score[][6],char name[][12],int n,int b)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("%4d%12ld%12s\t",i+1,number[i],name[i]);
        for(j=0;j<b;j++)
        {
            printf("%d\t",score[i][j]);
        }
        printf("%d\n",AllScores[i]);
    }
}
/*****************
**函数名：PrintAver
**i,j---计数器
**功能描述：遍历传入的long型数组，int型数组，char型数组并姓名总分平均分各分数打印出来
****************/
void PrintAver(long number[],int AllScores[],float KeepAverage[],int score[][6],char name[][12],int n,int b)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("%4d%12ld%12s\t",i+1,number[i],name[i]);
        for(j=0;j<b;j++)
        {
            printf("%d\t",score[i][j]);
        }
        printf("%d\t%f\n",AllScores[i],KeepAverage[i]);
    }
}

/************
**函数名：Choice
**i--暂时储存选项，形参
**功能描述：将用户选项赋给传入指针所指处，使用户可以再选功能
************/
void Choice(int* p)
{
    int i;
    printf("    1.Input record\n\
    2.Calculate total and average score of every course\n\
    3.Calculate total and average score of every student\n\
    4.Sort in descending order by score of every student\n\
    5.Sort in ascending order by score of every student\n\
    6.Sort in ascending order by number\n\
    7.Sort in dictionary order by name\n\
    8.Search by number\n\
    9.Search by name\n\
    10.Statistic analysis for every course\n\
    11.List record\n\
    0.Exit\n");
    scanf("%d",&i);
    while(i>11||i<0)
    {
        printf("Please input a number from 0 to 11:");
        scanf("%d",&i);
    }//防止非法数据输入，使程序正常运行
    *p=i;
}
/************
**函数名：Swap
**temp1,temp2,temp3[12]，temp4--交换时的中间变量，形参
**功能描述：将传入的值在各数组中位置互换
************/
void Swap(int score[][6],long *c,long* d,char *e,char *f,int x,int y,int Allscores[],int b)
{
    int i;
    int temp1,temp4;
    long temp2;
    char temp3[12];
    temp4=Allscores[x];
    Allscores[x]=Allscores[y];
    Allscores[y]=temp4;
    for(i=0;i<b;i++)
    {
        temp1=score[x][i];
        score[x][i]=score[y][i];
        score[y][i]=temp1;
    }
    temp2=*c;
    *c=*d;
    *d=temp2;
    strcpy(temp3,e);
    strcpy(e,f);
    strcpy(f,temp3);
}
