#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Swap(int score[][6],long *c,long* d,char *e,char *f,int x,int y,int Allscores[],int b);

/************
**��������Input
**i,a---������
**������������¼�û������ѧ�������ͳɼ�
************/
void Input(long number[],char name[][12],int score[][6],int n,int j)
{
    int i,a;
    for(i=0;i<n;i++)
    {
        printf("Please input student's name:");
        gets(name[i]);
        printf("Please input student's number:");
        scanf("%ld",&number[i]);
        printf("Please input the score(s) of this student:\n");
        for(a=0;a<j;a++)
        {
            scanf("%d",&score[i][a]);
        }
        while(getchar()!='\n');
    }
}
/************
**��������TTotalAverage
**i---������
**�������������㴫��������ܺͺ�ƽ������ѧ����
************/
void TTotalAverage(int AllScores[],int n,float average[],char name[][12])
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%s 's total mark is %d, the average mark is %f.\n",name[i],AllScores[i],average[i]);
    }
}
/************
**��������UTotalAverage
**i��j---������
**�������������㴫��������ܺͺ�ƽ������ѧ�ƣ�
************/
void UTotalAverage(int score[][6],int n,int b)
{
    int i,j;
    int total=0;
    float average=0;
    for(j=0;j<b;j++)
    {
        total=0;
        for(i=0;i<n;i++)
       {
           total+=score[i][j];
        }
    average=(float)total/n;
    printf("The subject %d 's total mark is %d, the average mark is %f.\n",j+1,total,average);
    }
}

/************
**��������SelectionSort
**�β�i---����������������n-1��Ԫ��
**�β�j---������������i+1��Ԫ��֮��
**�β�k---��¼��ҪԪ�ص�λ��
**��������������ĳ�ַ���ֵ��int�ĺ����ķ���ֵ�Ƿ�Ϊ0����ĳ�ֹ�������
************/
void SelectionSort(int score[][6],int AllScores[],char name[][12],long number[],int n,int b,int(*compare)(int a,int b))
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if((*compare)(AllScores[j],AllScores[k]))
            {
                k=j;
            }
        }
        if(k!=i)
        {
           Swap(score,&number[k],&number[i],name[k],name[i],k,i,AllScores,b);
        }
    }
}
int Descending(int a,int b)
{
    return a>b;
}
int Ascending(int a,int b)
{
    return a<b;
}
/************
**��������NumberAscending
**�β�i---����������������n-1��Ԫ��
**�β�j---������������i+1��Ԫ��֮��
**�β�k---��¼��ҪԪ�ص�λ��
**������������ѧ���������гɼ���ӡ
************/
void NumberAscending(int AllScores[],long number[],char name[][12],int score[][6],int n,int b)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(number[j]<number[k])
            {
                k=j;
            }
        }
        if(k!=i)
        {
           Swap(score,&number[k],&number[i],name[k],name[i],k,i,AllScores,b);
        }
    }
}
/************
**������:NameDictionary
**�β�j---������������i+1��Ԫ��֮��
**�β�k---��ͷ��ʼ��������
**�β�temp1,temp2,temp[12]---��������Ԫ�ص��м����
**�����������������������гɼ���ӡ
************/
void NameDictionary(char name[][12],int AllScores[],int score[][6],long number[],int n,int b)
{
    int k,j,i;
    int temp1,temp3;
    long temp2;
    char temp[12];
    for(k=0;k<n-1;k++)
    {
        for(j=k+1;j<n;j++)
        {
            if(strcmp(name[j],name[k])<0)
            {
                strcpy(temp,name[j]);
                strcpy(name[j],name[k]);
                strcpy(name[k],temp);
                temp3=AllScores[k];
                AllScores[k]=AllScores[j];
                AllScores[j]=temp3;
                for(i=0;i<b;i++)
                {
                    temp1=score[k][i];
                    score[k][i]=score[j][i];
                    score[j][i]=temp1;
                }
                temp2=number[k];
                number[k]=number[j];
                number[j]=temp2;
            }
        }
    }
}
