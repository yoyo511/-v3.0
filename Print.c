#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************
**��������Print
**i,j---������
**�������������������long�����飬int�����飬char�����鲢����Ԫ�ش�ӡ����
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
**��������PrintAver
**i,j---������
**�������������������long�����飬int�����飬char�����鲢�����ܷ�ƽ���ָ�������ӡ����
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
**��������Choice
**i--��ʱ����ѡ��β�
**�������������û�ѡ�������ָ����ָ����ʹ�û�������ѡ����
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
    }//��ֹ�Ƿ��������룬ʹ������������
    *p=i;
}
/************
**��������Swap
**temp1,temp2,temp3[12]��temp4--����ʱ���м�������β�
**�����������������ֵ�ڸ�������λ�û���
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
