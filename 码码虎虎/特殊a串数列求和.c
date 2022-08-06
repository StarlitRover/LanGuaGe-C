/*7-92 特殊a串数列求和 (20分)
给定两个均不超过9的正整数a和n，要求编写程序求a+aa+aaa++?+aa?a（n个a）之和。

输入格式：
输入在一行中给出不超过9的正整数a和n。

输出格式：
在一行中按照“s = 对应的和”的格式输出。

输入样例：
2 3
输出样例：
s = 246*/
1:
#include<stdio.h>
int a;
int f(void)
{
    static int y=0;
    y=10*y+a;
    return y;
}
int main()
{
    int n,s=0;
    scanf("%d %d",&a,&n);
    for(int i=0;i<n;++i)
        s+=f();
    printf("s = %d",s);
    return 0;
}

2:
#include<stdio.h>
int main()
{
    int a,n,x=0,s=0;
    scanf("%d %d",&a,&n);
    for(int i=0;i<n;++i)
    {
        x=10*x+a;
        s+=x;
    }
    printf("s = %d",s);
    return 0;
}
//事实上函数中的静态变量往往可以被主函数中的一般变量给取代
//静态变量似乎在C语言开发环境(在线编译器)中无法实现
//本例题目并不难，但是是静态变量与全局变量的一次尝试.