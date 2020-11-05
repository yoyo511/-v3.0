#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Swap(int score[][6],long *c,long* d,char *e,char *f,int x,int y,int Allscores[],int b);

/************
**函数名：Input
**i,a---计数器
**功能描述：记录用户输入的学号姓名和成绩
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
**函数名：TTotalAverage
**i---计数器
**功能描述：计算传入数组的总和和平均数（学生）
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
**函数名：UTotalAverage
**i，j---计数器
**功能描述：计算传入数组的总和和平均数（学科）
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
**函数名：SelectionSort
**形参i---计数器遍历到数组n-1个元素
**形参j---计数器遍历第i+1个元素之后
**形参k---记录想要元素的位置
**功能描述：根据某种返回值是int的函数的返回值是否为0，按某种规律排序
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
**函数名：NumberAscending
**形参i---计数器遍历到数组n-1个元素
**形参j---计数器遍历第i+1个元素之后
**形参k---记录想要元素的位置
**功能描述：按学号升序排列成绩打印
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
**函数名:NameDictionary
**形参j---计数器遍历第i+1个元素之后
**形参k---从头开始遍历数组
**形参temp1,temp2,temp[12]---交换数组元素的中间变量
**功能描述：按姓名升序排列成绩打印
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
