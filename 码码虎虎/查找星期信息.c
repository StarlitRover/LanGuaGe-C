/*7-43 ��֯������Ϣ (10��)
����һ��������repeat (0<repeat<10)����repeat���������㣺

����һ��ָ�����齫�����������Ϣ��֯����������һ���ַ������ڱ��в��ң������ڣ�������ַ����ڱ��е���ţ��������-1��

Sunday Monday Tuesday Wednesday Thursday Friday Saturday

�������ʾ����������Ϊ˵���������������

�������� (repeat=3) :
3
Tuesday
Wednesday
year
�������:
3
4
-1*/
#include<stdio.h>
#include<string.h>
int main()
{
    char *s[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"}; //�״��õ��ַ�������
    int n,i,j;
    scanf("%d",&n);
    getchar();                      //һ��û�����getchar����һ���ַ����ͻ����س�
    char t[20];
    for(i=0;i<n;++i)
    {
        gets(t);
        for(j=0;j<7;++j)
            if(!strcmp(s[j],t))
            {
                printf("%d\n",j+1);
                break;
            }
        if(j==7) printf("-1\n");
    }
    return 0;
}