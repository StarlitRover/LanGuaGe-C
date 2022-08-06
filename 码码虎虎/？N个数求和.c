/*7-79 N个数求和 (含螺旋未解大坑:要死人的测试点3)(20分)
本题的要求很简单，就是求N个数字的和。麻烦的是，这些数字是以有理数分子/分母的形式给出的，你输出的和也必须是有理数的形式。

输入格式：
输入第一行给出一个正整数N（≤100）。随后一行按格式a1/b1 a2/b2 ...给出N个有理数。题目保证所有分子和分母都在长整型范围内。另外，负数的符号一定出现在分子前面。

输出格式：
输出上述数字和的最简形式 ?? 即将结果写成整数部分 分数部分，其中分数部分写成分子/分母，要求分子小于分母，且它们没有公因子。如果结果的整数部分为0，则只输出分数部分。

输入样例1：
5
2/5 4/15 1/30 -2/60 8/3
输出样例1：
3 1/3
输入样例2：
2
4/3 2/3
输出样例2：
2
输入样例3：
3
1/3 -1/6 1/8
输出样例3：
7/24*/
//本人解法(可恶的测试点3)：
#include<stdio.h>
int gcd(int x,int y);
int lcm(int x,int y);
int main()
{
    int n;
    
    scanf("%d\n",&n);
    int a[n],b[n],product=1,sum=0,D,d,integer=0;      //rmd=remainder余数
    for(int i=0;i<n;++i)
    scanf("%d/%d",&a[i],&b[i]);
    for (int i=0;i<n;++i)
    {
        D=lcm(product,b[i]);
        sum*=(D/product);
        sum+=D/b[i]*a[i];
        product=lcm(product,b[i]);
        if(sum!=0) 
        {
            d=gcd(product,sum);
        sum/=d;product/=d;
        }
        else 
            product=1;
        integer+=sum/product;
        sum=sum%product;
    }
//     if (sum*product<0) printf ("-");           这两行直接决定了该程序测试点3能否通过:
//     sum=abs(sum);product=abs(product);         因此这是一个值得深思的问题
    if(sum==0) printf("%d",integer);
    else
    {
    if(integer==0&&sum) printf("%d/%d",sum,product);
    else printf("%d %d/%d",integer,sum,product);
    }
    return 0;
}
int lcm(int x,int y)
{
    return x*y/gcd(x,y);
}
int gcd(int x,int y)
{
    int q,s,cup,d;
    if(x<0) x*=-1;
    if(y<0) y*=-1;
    if(x<y){cup=x;x=y;y=cup;}
    s=y;
    q=x%y;
    if(q==0) d=y;
    else
    while(q>0){
        d=q;q=s%q;s=d;
    }
    return d;
}

//网友答案1:
#include <stdio.h>
int gcd(int a,int b)
{
	if(a==0)
	return 0;
	else
	return (b==0)?a:gcd(b,a%b);
}
int main()
{
	int N,i;
	int gong,a,b,c,d;
	scanf("%d",&N);
	scanf("%d/%d",&a,&b);
	int t=gcd(a,b);
	if(a)
	{
		a/=t;
		b/=t;
	}
	for(i=1;i<N;i++)
	{
		scanf("%d/%d",&c,&d);
		gong=b*d/gcd(b,d);
		a=a*gong/b+c*gong/d;
		b=gong;
		int t1=gcd(a,b);
		if(t1)
		{
			a/=t1;
			b/=t1;
		}
	}
	if(a&&a/b==0)
	printf("%d/%d\n",a%b,b);
	else if(a%b==0)
	printf("%d\n",a/b);
	else 
	printf("%d %d/%d\n",a/b,a%b,b);
	return 0;
}
//网友答案2：
#include<stdio.h>
int main()
{
	int n,i;
	long long int a,b,c,d,m1,m2,p;
	scanf("%d",&n);
	scanf("%lld/%lld",&a,&b);
	while(--n)
	{
		scanf("%lld/%lld",&c,&d);
		m1=a * d+b * c;
		m2=b * d;
		if(m1>m2) p=m2;
		else p=m1;
		if(p<0) p=-p;
		for(i=p;i>=1;i--)
		{
			if(m1%i==0&&m2%i==0)
			{
			  a=m1/i;
		    b=m2/i;
		    break;
			} 
		}
		if(i<1)//测试点五：当分子为零时没有最大公约数;
		{
			a=m1;
			b=m2;
		}
	}
	if(a>b) p=b;
	else p=a;
	for(i=p;i>=1;i--)
	{
		if(a%i==0&&b%i==0)
		{
			a/=i;
			b/=i;
			//测试点3不写break;方可通过; 
		}
	}
	if(a%b==0) printf("%lld",a/b);
	else if(a/b==0&&a!=0&&b!=0) printf("%lld/%lld",a%b,b);
	else printf("%lld %lld/%lld",a/b,a%b,b);
    return 0;
 } 
