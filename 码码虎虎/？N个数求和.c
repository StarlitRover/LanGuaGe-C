/*7-79 N������� (������δ����:Ҫ���˵Ĳ��Ե�3)(20��)
�����Ҫ��ܼ򵥣�������N�����ֵĺ͡��鷳���ǣ���Щ������������������/��ĸ����ʽ�����ģ�������ĺ�Ҳ����������������ʽ��

�����ʽ��
�����һ�и���һ��������N����100�������һ�а���ʽa1/b1 a2/b2 ...����N������������Ŀ��֤���з��Ӻͷ�ĸ���ڳ����ͷ�Χ�ڡ����⣬�����ķ���һ�������ڷ���ǰ�档

�����ʽ��
����������ֺ͵������ʽ ?? �������д���������� �������֣����з�������д�ɷ���/��ĸ��Ҫ�����С�ڷ�ĸ��������û�й����ӡ�����������������Ϊ0����ֻ����������֡�

��������1��
5
2/5 4/15 1/30 -2/60 8/3
�������1��
3 1/3
��������2��
2
4/3 2/3
�������2��
2
��������3��
3
1/3 -1/6 1/8
�������3��
7/24*/
//���˽ⷨ(�ɶ�Ĳ��Ե�3)��
#include<stdio.h>
int gcd(int x,int y);
int lcm(int x,int y);
int main()
{
    int n;
    
    scanf("%d\n",&n);
    int a[n],b[n],product=1,sum=0,D,d,integer=0;      //rmd=remainder����
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
//     if (sum*product<0) printf ("-");           ������ֱ�Ӿ����˸ó�����Ե�3�ܷ�ͨ��:
//     sum=abs(sum);product=abs(product);         �������һ��ֵ����˼������
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

//���Ѵ�1:
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
//���Ѵ�2��
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
		if(i<1)//���Ե��壺������Ϊ��ʱû�����Լ��;
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
			//���Ե�3��дbreak;����ͨ��; 
		}
	}
	if(a%b==0) printf("%lld",a/b);
	else if(a/b==0&&a!=0&&b!=0) printf("%lld/%lld",a%b,b);
	else printf("%lld %lld/%lld",a/b,a%b,b);
    return 0;
 } 
