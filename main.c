/***************
**文件名：main.c
**创建人：刘雨萱
**日期：2020.10.27
**作业题目：学生成绩管理系统V3.0
**功能选择范围（即输入范围）0-11
**描述：这是学籍管理系统的主函数，可以实现排序、查分等功能，最多30人,最多六科(可以输入人名）
**版本：c语言，codeblock
**---------------
***************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TTotalAverage(int AllScores[],int n,float average[],char name[][12]);
void UTotalAverage(int score[][6],int n,int b);
void SelectionSort(int score[][6],int AllScores[],char name[][12],long number[],int n,int b,int(*compare)(int a,int b));
int Descending(int a,int b);
int Ascending(int a,int b);
void Input(long number[],char name[][12],int score[][6],int n,int j);
void Choice(int* p);
void NumberAscending(int AllScores[],long number[],char name[][12],int score[][6],int n,int b);
void Swap(int score[][6],long *c,long* d,char *e,char *f,int x,int y,int Allscores[],int b);
void Print(long number[],int AllScores[],int score[][6],char name[][12],int n,int b);
void NameDictionary(char name[][12],int AllScores[],int score[][6],long number[],int n,int b);
void PrintAver(long number[],int AllScores[],float KeepAverage[],int score[][6],char name[][12],int n,int b);

int main()
{
    int i,d;
    int score[30][6];
    int AllScores[30];
    float Average[30];//记录各学生的总分平均分
    long number[30];
    char name[30][12];//这里的12指姓名最多字符数
    int KeepScore[30][6];
    long KeepNumber[30];
    int KeepAll[30];
    float KeepAverage[30];
    char KeepName[30][12];//为防止在进行操作后各学号和分数和姓名在数组中位置改变，定义Keep来保持
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
    printf("Please enter your choice\n");
    scanf("%d",&i);
    //输入选项
    for(d=0;d<30;d++)
    {
        AllScores[d]=0;
        Average[d]=0;
    }
    while(i!=1&&i!=0)
    {
        printf("Please input 1 first.\n");
        scanf("%d",&i);
    }
    //各功能需在学号，姓名，分数已知情况进行，此步保证用户先输入学号姓名成绩
    if(i==0)
    {
        exit(0);
    }
    else
    {
        int n,b,ret;
        printf("Please input the student number and the number of subjects (0<student number<=30;0<subject number<=6):\n");
        ret=scanf("%d %d",&n,&b);
        getchar();
        while(i!=0)
        {
            while(ret==0)
            {
                while(getchar()!='\n');
                printf("Please input again (0<number<=30):\n");
                ret=scanf("%d %d",&n,&b);
                getchar();
            }
            while(n<=0||n>30||b<=0||b>6)
            {
                printf("Please input again (0<student number<=30;0<subject number<=6):\n");
                scanf("%d %d",&n,&b);
                getchar();
            }//防止访问超限，保证学生人数在30以内，学科在6课以内并防止非法字符输入
            int a,c;//a为各循环（赋值或找值）的计数器(如有二维则为行计数器），c为二维列计数器
            long int num;//记录用户输入的学号
            char nam[12];//记录用户输入的姓名
            int en=0,gn=0,sn=0,pn=0,fn=0;//分别为优秀，良好，中等，及格，不及格人数
            switch(i)
            {
            case 1:
                Input(number,name,score,n,b);
                for(a=0; a<n; a++)
                {
                    for(c=0;c<b;c++)
                    {
                        AllScores[a]+=score[a][c];
                        KeepScore[a][c]=score[a][c];
                    }
                    Average[a]=(float)AllScores[a]/b;
                    KeepNumber[a]=number[a];
                    strcpy(KeepName[a],name[a]);
                    KeepAll[a]=AllScores[a];
                    KeepAverage[a]=Average[a];
                }
                Choice(&i);
                break;
            case 2:
                UTotalAverage(score,n,b);
                Choice(&i);
                break;
            case 3:
                TTotalAverage(AllScores,n,Average,name);
                Choice(&i);
                break;
            case 4:
                SelectionSort(score,AllScores,name,number,n,b,Descending);
                Print(number,AllScores,score,name,n,b);
                Choice(&i);
                break;
            case 5:
                SelectionSort(score,AllScores,name,number,n,b,Ascending);
                Print(number,AllScores,score,name,n,b);
                Choice(&i);
                break;
            case 6:
                NumberAscending(AllScores,number,name,score,n,b);
                Print(number,AllScores,score,name,n,b);
                Choice(&i);
                break;
            case 7:
                NameDictionary(name,AllScores,score,number,n,b);
                Print(number,AllScores,score,name,n,b);
                Choice(&i);
                break;
            case 8:
                printf("Please input the student number:");
                scanf("%ld",&num);
                SelectionSort(score,AllScores,name,number,n,b,Descending);//先排序
                for(a=0; a<n; a++)
                {
                    if(num==number[a])
                    {
                        printf("The rank is %d.\n",a+1); //因已排序，a+1即为排名
                        for(c=0;c<b;c++)
                        {
                          printf("The subject %d is %d.\n",c+1,score[a][c]);
                        }
                        break;
                    }
                }
                if(a==n)
                {
                    printf("Not found!\n");//防止输入学号错误
                }
                Choice(&i);
                break;
            case 9:
                printf("Please input the student's name:");
                scanf("%s",nam);
                SelectionSort(score,AllScores,name,number,n,b,Descending);//先排序
                for(a=0; a<n; a++)
                {
                    if(strcmp(nam,name[a])==0)
                    {
                        printf("The rank is %d.\n",a+1); //因已排序，a+1即为排名
                        for(c=0;c<b;c++)
                        {
                          printf("The subject %d is %d.\n",c+1,score[a][c]);
                        }
                        break;
                    }
                }
                if(a==n)
                {
                    printf("Not found!\n");//防止输入名字错误
                }
                Choice(&i);
                break;
            case 10:
                for(c=0; c<b; c++)
                {
                    en=0;
                    gn=0;
                    sn=0;
                    pn=0;
                    fn=0;
                    for(a=0;a<n;a++)
                    {
                        if(score[a][c]>=90&&score[a][c]<=100)
                        en++;
                    else if(score[a][c]>=80&&score[a][c]<=89)
                        gn++;
                    else if(score[a][c]>=70&&score[a][c]<=79)
                        sn++;
                    else if(score[a][c]>=60&&score[a][c]<=69)
                        pn++;
                    else
                        fn++;
                    }
                printf("The analysis for subject %d.\n",c+1);
                printf("Excellent(90-100):%d people, %f percent.\n",en,100*((float)en/n));
                printf("Good(80-89):%d people, %f percent.\n",gn,100*((float)gn/n));
                printf("Secondary(70-79):%d people, %f percent.\n",sn,100*((float)sn/n));
                printf("Pass(60-69):%d people, %f percent.\n",pn,100*((float)pn/n));
                printf("Fail(0-59):%d people, %f percent.\n",fn,100*((float)fn/n));
                }
                Choice(&i);
                break;
            case 11:
                PrintAver(KeepNumber,KeepAll,KeepAverage,KeepScore,KeepName,n,b);
                Choice(&i);
                break;
            }
        }
    }
    return 0;
}
