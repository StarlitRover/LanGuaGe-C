/*7-27 兔子繁衍问题
一对兔子，从出生后第3个月起每个月都生一对兔子。小兔子长到第3个月后每个月又生一对兔子。
假如兔子都不死，请问第1个月出生的一对兔子，至少需要繁衍到第几个月时兔子总数才可以达到N对？

输入格式:
输入在一行中给出一个不超过10000的正整数N。

输出格式:
在一行中输出兔子总数达到N最少需要的月数。

输入样例:
30
输出样例:
9*/
//方案一：数组（其实没必要）
#include<stdio.h>
int main()
{
    int n[900];                    //这里取900其实是为了让数组的容量尽可能地大
    int N,i=2;
    n[1]=n[2]=1;
    scanf("%d",&N);
    if (N==1)printf("1");
    else{
    do{
        ++i;
        n[i]=n[i-1]+n[i-2];
    }while(n[i]<N);
    printf("%d",i);
    }
    return 0;
}
//方案二：
#include<stdio.h>
int main()
{
    int N,sum,st,nd,cnt;
    st=nd=cnt=1;
    sum=0;
    
    scanf("%d",&N);
    if (N!=1) 
    for(cnt=2;sum<N;cnt++)
    {
        sum=st+nd;
        st=nd;
        nd=sum;
    }
    printf("%d",cnt);
    return 0;
}
