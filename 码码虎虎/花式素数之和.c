//第n~m个素数之和(a little 不简洁)
#include<stdio.h>
int main() {
    int n, m, sum, count;
    count=1;
    scanf("%d %d", &n, &m);
    if (n==1)sum=2;
    else sum=0;
    for(int i = 2; count < m; i++) {
        for(int j = i-1; j > 1; j--) {
            if(i%j == 0) break;
            if(j == 2) {              //一旦走到了这一步就意味着i必然为素数
                count++;
                if(count >= n)
                sum += i;
            }
        }
    }
        printf("%d", sum);
        return 0;
}

//M~N之间素数的个数与和
#include<stdio.h>
int main()
{
    int N,M,cnt,sum;
    scanf("%d %d",&M,&N);
    cnt=sum=0;
    for(int i=M;i<=N;++i)
    {
        for(int j=1;j<=i-1;++j)
        {
            if(i%j==0&&j!=1) break;
            if(j==i-1) {++cnt;sum+=i;}
        }
    }
    printf("%d %d",cnt,sum);
    return 0;
}
