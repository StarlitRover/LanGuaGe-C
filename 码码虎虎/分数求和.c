#include<stdio.h>
int main()
{
    int N,cnt;
    double a,b,sum;      //ATTENTION��N�ϴ�ʱint�ͱ���a��b���޷�����!
    
    scanf("%d",&N);
    a=2;
    b=1;
    sum=cnt=0;
    while (cnt<N)
    {
        sum+=(a/b);
        a=a+b;            //������������ڲ���Ҫ����������ȥ�����ǰ��a,�������Ӧ��
        b=a-b;
        ++cnt;
    }
    printf("%.2f",sum);
    return 0;
}
