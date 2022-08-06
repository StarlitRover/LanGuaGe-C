/*7-39 天梯赛座位分配 (20分)
天梯赛每年有大量参赛队员，要保证同一所学校的所有队员都不能相邻，分配座位就成为一件比较麻烦的事情。为此我们制定如下策略：
假设某赛场有 N 所学校参赛，第 i 所学校有 M[i] 支队伍，每队 10 位参赛选手。令每校选手排成一列纵队，第 i+1 队的选手排在
第 i 队选手之后。从第 1 所学校开始，各校的第 1 位队员顺次入座，然后是各校的第 2 位队员…… 以此类推。如果最后只剩下 1 所
学校的队伍还没有分配座位，则需要安排他们的队员隔位就坐。本题就要求你编写程序，自动为各校生成队员的座位号，从 1 开始编号。

输入格式：
输入在一行中给出参赛的高校数 N （不超过100的正整数）；第二行给出 N 个不超过10的正整数，其中第 i 个数对应第 i 所高校的参赛队伍数，数字间以空格分隔。

输出格式：
从第 1 所高校的第 1 支队伍开始，顺次输出队员的座位号。每队占一行，座位号间以 1 个空格分隔，行首尾不得有多余空格。
另外，每所高校的第一行按“#X”输出该校的编号X，从 1 开始。

输入样例：
3
3 4 2

输出样例：
#1
1 4 7 10 13 16 19 22 25 28
31 34 37 40 43 46 49 52 55 58
61 63 65 67 69 71 73 75 77 79
#2
2 5 8 11 14 17 20 23 26 29
32 35 38 41 44 47 50 53 56 59
62 64 66 68 70 72 74 76 78 80
82 84 86 88 90 92 94 96 98 100
#3
3 6 9 12 15 18 21 24 27 30
33 36 39 42 45 48 51 54 57 60*/
#include <stdio.h>
int main()
{
    int n, cnt = 1, sign = -1;                             //sign用来判断该队伍是否是最后一所学校的最后一支队伍
    scanf("%d", &n);
    int school[n], max = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &school[i]);
        if (max < school[i])
            max = school[i];
    }
    int sum = (n - 1) * 100 + max * 10 + 10;
    int num[sum], group, idvd;                              //这里没有开9999的数组是为了尽量地减少空间的浪费,而sum是所有可能下标的最大值
    for (int index = 0; index < max * 10; ++index)          //index表示的是当前轮到每组的第几位同学编号了(每个循环每组已编号的学生个数都是相等的)
    {
        group = index / 10;
        idvd = index % 10;
        for (int i = 0; i < n; ++i)
            if (group < school[i])
            {
                if (sign == i)                              //如果sign与之前的i相等意味着只剩下一所学校了，因此需要隔位编号(即cnt+2)
                    cnt += 1;
                num[i * 100 + group * 10 + idvd] = cnt++;
                sign = i;
            }
    }
    for (int i = 0; i < n; ++i)
    {
        printf("#%d\n", i + 1);
        for (int j = 0; j < school[i]; j++)
        {
            for (int k = 0; k < 10; ++k)
            {
                printf("%d", num[i * 100 + j * 10 + k]);
                if (k != 9)
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}

//本来这道题我的思路是使用三维数组(因为是最早写的，因此与题目要求还存在一些矛盾，但思路已体现):
#include<stdio.h>
int main()
{
    int n,cnt=1;
    scanf("%d",&n);
    int school[n],max=0,sum=0;
    for(int i=0;i<n;++i)
    {
        scanf("%d",&school[i]);
        if(max<school[i]) max=school [i];
        sum+=school[i];
    }
    int num[n][max][10]={0},group,idvd;
    for(int index=0;index<max*10;++index)
    {
        group=index/10;
        idvd=index%10;
        for(int i=0;i<n;++i)
            if(group<school[i])
                num[i][group][idvd]=cnt++;
    }
    for(int i=0;i<n;++i)
    {
        printf("#%d\n",i+1);
        for(int j=0;j<school[i];j++)
        {
            for(int k=0;k<10;++k)
                printf("%d ",num[i][j][k]);
            printf("\n");
        }
    }
    return 0;
}
/*但可恶的是不能用变量定义三维数组,需要动态分配空间,而且需要为其构造专门的malloc和free函数,真是太麻烦了:(
冰雪聪明的我自然不会被其束缚,于是我将将一维数组改造了一下来表示三维数组:这里一共有三个变量----学校、队伍、个人,
由于学校个数<100,一所学校队伍个数<10,一支队伍人数固定为10,于是这三个变量可以被放进一个四位数中,其中各位表示个
人,十位表示队伍,百千位表示学校,那么就可以当成三维数组使用了-->num[i][j][k]=num[i*100+j*10+k].
事实上所有关于该数组操作都与三维数组一致*/