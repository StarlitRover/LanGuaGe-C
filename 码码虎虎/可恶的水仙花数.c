/*7-93 ˮ�ɻ��� (20��)
ˮ�ɻ�����ָһ��Nλ��������N��3��������ÿ��λ�ϵ����ֵ�N����֮�͵������������磺153=1^3+5^3+3^3.
����Ҫ���д����,��������Nλˮ�ɻ�����

�����ʽ:
������һ���и���һ��������N��3��N��7����

�����ʽ:
������˳���������Nλˮ�ɻ�����ÿ������ռһ�С�

��������:
3
�������:
153
370
371
407*/
#include<stdio.h>
int p(int a, int b)                //�������¶���/�����ݺ������������������ʱ��,���ɶ�����˷����ҵĴ��ʱ��!!!
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
