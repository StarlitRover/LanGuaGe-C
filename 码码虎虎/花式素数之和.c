//��n~m������֮��(a little �����)
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
            if(j == 2) {              //һ���ߵ�����һ������ζ��i��ȻΪ����
                count++;
                if(count >= n)
                sum += i;
            }
        }
    }
        printf("%d", sum);
        return 0;
}

//M~N֮�������ĸ������
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
