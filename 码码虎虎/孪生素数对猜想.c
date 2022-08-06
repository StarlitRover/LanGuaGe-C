/*7-45 素数对猜想 (20分)
“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N(<10^5)，请计算不超过N的满足猜想的素数对的个数。

输入格式:
输入在一行给出正整数N。

输出格式:
在一行中输出不超过N的满足猜想的素数对的个数。

输入样例:
20
输出样例:
4*/
#include<stdio.h>
#include<math.h>
int judge(int x)
{
    int i,flag=0;
    for(i=2;i<=sqrt(x);++i)
        if(x%i==0) break;
    if(i>sqrt(x)) flag=1;
    return flag;
}
int main()
{
    int n;
    scanf("%d",&n);
    int cnt=0,pre=3,delta;
    for(int i=5;i<=n;++i)
        if(judge(i)) 
        {
            delta=i-pre;
            if(delta==2) ++cnt;
            pre=i;
        }
    printf("%d",cnt);
    return 0;
}