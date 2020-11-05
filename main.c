/***************
**�ļ�����main.c
**�����ˣ�������
**���ڣ�2020.10.27
**��ҵ��Ŀ��ѧ���ɼ�����ϵͳV3.0
**����ѡ��Χ�������뷶Χ��0-11
**����������ѧ������ϵͳ��������������ʵ�����򡢲�ֵȹ��ܣ����30��,�������(��������������
**�汾��c���ԣ�codeblock
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
    float Average[30];//��¼��ѧ�����ܷ�ƽ����
    long number[30];
    char name[30][12];//�����12ָ��������ַ���
    int KeepScore[30][6];
    long KeepNumber[30];
    int KeepAll[30];
    float KeepAverage[30];
    char KeepName[30][12];//Ϊ��ֹ�ڽ��в������ѧ�źͷ�����������������λ�øı䣬����Keep������
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
    //����ѡ��
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
    //����������ѧ�ţ�������������֪������У��˲���֤�û�������ѧ�������ɼ�
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
            }//��ֹ���ʳ��ޣ���֤ѧ��������30���ڣ�ѧ����6�����ڲ���ֹ�Ƿ��ַ�����
            int a,c;//aΪ��ѭ������ֵ����ֵ���ļ�����(���ж�ά��Ϊ�м���������cΪ��ά�м�����
            long int num;//��¼�û������ѧ��
            char nam[12];//��¼�û����������
            int en=0,gn=0,sn=0,pn=0,fn=0;//�ֱ�Ϊ���㣬���ã��еȣ����񣬲���������
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
                SelectionSort(score,AllScores,name,number,n,b,Descending);//������
                for(a=0; a<n; a++)
                {
                    if(num==number[a])
                    {
                        printf("The rank is %d.\n",a+1); //��������a+1��Ϊ����
                        for(c=0;c<b;c++)
                        {
                          printf("The subject %d is %d.\n",c+1,score[a][c]);
                        }
                        break;
                    }
                }
                if(a==n)
                {
                    printf("Not found!\n");//��ֹ����ѧ�Ŵ���
                }
                Choice(&i);
                break;
            case 9:
                printf("Please input the student's name:");
                scanf("%s",nam);
                SelectionSort(score,AllScores,name,number,n,b,Descending);//������
                for(a=0; a<n; a++)
                {
                    if(strcmp(nam,name[a])==0)
                    {
                        printf("The rank is %d.\n",a+1); //��������a+1��Ϊ����
                        for(c=0;c<b;c++)
                        {
                          printf("The subject %d is %d.\n",c+1,score[a][c]);
                        }
                        break;
                    }
                }
                if(a==n)
                {
                    printf("Not found!\n");//��ֹ�������ִ���
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
