/*7-93 水仙花数 (20分)
水仙花数是指一个N位正整数（N≥3），它的每个位上的数字的N次幂之和等于它本身。例如：153=1^3+5^3+3^3.
本题要求编写程序,计算所有N位水仙花数。

输入格式:
输入在一行中给出一个正整数N（3≤N≤7）。

输出格式:
按递增顺序输出所有N位水仙花数，每个数字占一行。

输入样例:
3
输出样例:
153
370
371
407*/
#include<stdio.h>
int p(int a, int b)                //这里重新定义/简化了幂函数，大大缩短了运行时间,但可恶的是浪费了我的大好时间!!!
{
    int pow = 1, j;
    for(j = 1; j <= b; j++) {
        pow = pow*a;
    }
    return pow;
}
int main()
{
    int n,sbt,sum,m,flag=0;
    scanf("%d",&n);
    sbt=n;
    for(int i=p(10,n-1);i<p(10,n);++i)
    {
        sum=0;
        m=i;
        while(m)
        {
            sum+=p(m%10,n);
            if(sum>i) break;
            m/=10;
        }
        if(sum==i) 
        {
            if(flag) printf("\n");
            printf("%d",i);
            flag=1;
        }
    }
    return 0;
} 


#include<stdio.h>
#include<math.h>
int main()
{
    int n,cnt,w,sum,m,flag=0;
    scanf("%d",&n);
    for(int i=pow(10,n-1);i<pow(10,n);++i)
    {
        sum=0;
        m=i;
        cnt=1;
        while(m)
        {
            w=pow(10,n-cnt);
            sum+=pow(m/w,n);
            if(sum>i) break;
            m%=w;
            ++cnt;
        }
        if (m) {i=(i/(10*w)+1)*10*w;continue;}
        if(sum==i) 
        {
            if(flag) printf("\n");
            printf("%d",i);
            flag=1;
        }
    }
    return 0;
}
