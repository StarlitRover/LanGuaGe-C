#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main ()
{
srand(time(0));
int a=rand();           //ע����������ĸ�ʽ
int b=rand();
int c=rand();
int d,n;

scanf("%d",&n);
a=a%(n+1);
b=b%(n+1-a);
c=c%(n+1-a-b);
d=n-a-b-c;
printf("%d=%d+%d+%d+%d",n,a,b,c,d);
    return 0;
}