/*7-84 连续因子 (20分)
一个正整数 N 的因子中可能存在若干连续的数字。例如 630 可以分解为 3×5×6×7，其中 5、6、7 就是 3 个连续的数字。
给定任一正整数 N，要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。

输入格式：
输入在一行中给出一个正整数 N（1<N<2^31）。

输出格式：
首先在第 1 行输出最长连续因子的个数；然后在第 2 行中按 因子1*因子2*……*因子k 的格式输出最小的连续因子序列，
其中因子按递增顺序输出，1 不算在内。

输入样例：
630
输出样例：
3
5*6*7
*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n,m,j,first=1,cup,max=0;
    
    scanf("%d",&n);
    for(int i=2;i<=sqrt(n);++i)
    {
        cup=0;
        m=n;
        j=i;
            while(m%j==0)
            {
                m/=j;
                cup+=1;
                ++j;
        }
        if(max<cup) {max=cup;first=i;}
    }
    if(max==0) {first=n;max=1;}
    printf("%d\n%d",max,first);
    for(int i=1;i<max;++i)
        printf("*%d",first+i);
        return 0;
}
/*ATTENTION
这题需要极度谨慎(主要是是因为测试点没有提示，我真的一点都不想骂人)，需注意以下几点:
1.质数的完全平方数 
2.for循环中i不可跳跃循环(每次只能+1)
