/*7-45 �����Բ��� (20��)
�������Բ��롱��Ϊ�����������������Ҳ�Ϊ2����������

�ָ�������������N(<10^5)������㲻����N���������������Եĸ�����

�����ʽ:
������һ�и���������N��

�����ʽ:
��һ�������������N���������������Եĸ�����

��������:
20
�������:
4*/
#include<stdio.h>
#include<math.h>
int judge(int x)
{
    int i,flag=0;
    for(i=2;i<=sqrt(x);++i)
        if(x%i==0) break;
    if(i>sqrt(x)) flag=1;
    return flag;
}
int main()
{
    int n;
    scanf("%d",&n);
    int cnt=0,pre=3,delta;
    for(int i=5;i<=n;++i)
        if(judge(i)) 
        {
            delta=i-pre;
            if(delta==2) ++cnt;
            pre=i;
        }
    printf("%d",cnt);
    return 0;
}