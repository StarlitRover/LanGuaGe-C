/*7-5 �����������г��ִ��������� (10��)
����Ҫ��ͳ��һ�����������г��ִ�����������������ִ�����

�����ʽ��
������һ���и�����������������N��0<N��1000�����Լ�N�����������ּ��Կո�ָ���

�����ʽ��
��һ����������ִ�����������������ִ��������ּ��Կո�ָ�����Ŀ��֤������������Ψһ�ġ�

����������
10 3 2 -1 5 3 4 3 0 3 2
���������
3 4*/
#include<stdio.h>
void swap(int *x, int *y);
int main() 
{
    int n, max = 0, sign, cnt = 0;
    scanf("%d", &n);
    int s[n];
    for(int i = 0; i < n; ++i)
    scanf("%d", &s[i]);
    for(int i = 0; i < n; ++i)
    for(int j = n-1; j > i; --j)
    if(s[j] > s[j-1]) swap(&s[j], &s[j-1]);      //�Ƚ����鰴�Ӵ�С�ķ�ʽ����(ð��)���򷽱������ͳ��
    for(int i = 0; i < n; ++i) 
    {
        ++cnt;
        if(i == n-1 || s[i+1]-s[i]) 
        {
            if(cnt > max) 
            {
                max = cnt;
                sign = s[i];
            }
            cnt = 0;
        }
    }
    printf("%d %d", sign, max);
}
void swap(int *x, int *y)                         //�״�ʹ��ָ�빹��swap����
{
    int cup;
    cup=*x;
    *x=*y;
    *y = cup;
}

//�ڶ���������(����������):
//�����������г��ִ���������:(����һ��������n�Լ�Ԫ�ظ���Ϊn��һ����������)
#include<stdio.h>
void swap(int *p,int*q)
{
    int cup=*p;
    *p=*q;
    *q=cup;
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n+1];
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    arr[n]=0;                       //ĩβ��0�Ƿ�ֹ���������Ǹ�����������������(�forѭ����©��)
    for(int i=1;i<n;++i)
    {
        int j=i,temp=arr[i];
		while(arr[--j]>temp)
		swap(&arr[j],&arr[j+1]);
    }                              //��������˲�������(����ʱ�Ѻ���ĩβ��0)��ͳ�Ƹ��������ֵĴ���
    int cnt=1,max=0,idex;
    for(int i=1;i<=n;++i)
    {
        if(arr[i]==arr[i-1]) cnt++;
        else
        {
            if(max<cnt) 
            {
                max=cnt;
                idex=i-1;
            }
            cnt=1;
        }
    }
    printf("%d %d",arr[idex],max);
    return 0;
}
//P.s.���ڱ�������й��ɿ����и������������Ӧ��CountSort��˼��