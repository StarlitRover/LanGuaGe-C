/*7-13 ɾ���ظ��ַ� (20��)
����Ҫ���д���򣬽������ַ���ȥ���ظ����ַ��󣬰����ַ�ASCII��˳���С��������������

�����ʽ��
������һ���Իس������ķǿ��ַ���������80���ַ�����
�����ʽ��
���ȥ�������Ľ���ַ�����

����������
ad2f3adjfeainzzzv
���������
23adefijnvz*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char arr[80];
    gets(arr);
    int max=0;
    for(int i=0;arr[i];++i)
        if(max<arr[i]) max=arr[i];
    int sign[max+1];
    for(int j=0;j<=max;++j)
        sign[j]=0;
    for(int j=0;arr[j];++j)
        sign[arr[j]]=1;
    for(int j=0;j<=max;++j)
        if(sign[j]) printf("%c",j);
    return 0;
}
//����˼��Ĺؼ�����ȫ���ַ�������������������,ͬʱ����������CountSort��˼��Ŷ