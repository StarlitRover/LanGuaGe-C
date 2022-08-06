#include<stdio.h>
#include<math.h>
int main()
{
    long int x;
    int sign=0;
    scanf("%ld",&x);
    long int cup=x;
    printf("%ld=",x);
    for(int i=2;i<=sqrt(x);++i)
    {
        if(cup%i==0)
        {
            int cnt=1;
            cup/=i;
            while(cup%i==0)
            {
                ++cnt;
                cup/=i;
            }
            if(sign) printf("*");
            if(cnt-1) printf("%d^%d",i,cnt);
            else printf("%d",i);
            sign=1;
        }
        if(cup==1) break;
    }
    if(sign&&cup-1) printf("*%ld",cup);
    if(!sign) printf("%ld",x);
    return 0;
}
//该算法可以进一步改进