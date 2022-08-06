#include<stdio.h>
int main()
{
    int N,cnt;
    double a,b,sum;      //ATTENTION当N较大时int型变量a，b将无法承载!
    
    scanf("%d",&N);
    a=2;
    b=1;
    sum=cnt=0;
    while (cnt<N)
    {
        sum+=(a/b);
        a=a+b;            //这里的巧妙在于不需要第三个变量去存放先前的a,而是随机应变
        b=a-b;
        ++cnt;
    }
    printf("%.2f",sum);
    return 0;
}
