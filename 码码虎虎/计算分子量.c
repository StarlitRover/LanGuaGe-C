/*���������

Problem Description
��ѧʽ����Է�����������Ʒ��������ǻ�ѧʽ�и�ԭ�ӵ�ԭ�������ܺ�,��ͬ��Ԫ�ص����ԭ����������ԭ�Ӹ�����ˣ�
��ͬԭ�ӵ����ԭ��������ӡ����磺CO2, ̼��12, ����16, ��ô��CO2����������12��16��2��44 ��
��֪����ѧ����ʽ�õ���Ԫ��ԭ�������£�

N:14
C:12
O:16
Cl:35
S:32
H:1
Al:27
Ca:40
Zn:65
Na:23

���������ʽ�ķ�������
 
Input
�����ж��У�ÿ����һ������ʽ�������ļ�������
����ʽ����С��50

Output
����ÿһ������ʽ�����ռһ�У�һ������������Ӧ�ķ�������
 
Sample Input
CO2
H2Na2SO4
N(NO2)3
(NH4)2SO4
 
Sample Output
44
144
152
132*/
#include<stdio.h>
int m(char* c)
{
    int value;
    if(*c=='N') value=14;
    else if(*c=='n') value=65; 
    else if(*c=='H') value=1; 
    else if(*c=='S') value=32; 
    else if(*c=='a')
    {
        if(*(c-1)=='N') value=23;
        else value=40;
    } 
    else if(*c=='l')
    {
        if(*(c-1)=='C') value=35;
        else value=27;
    } 
    else if(*c=='O') value=16; 
    else if(*c=='C') value=12; 
    return value;
}
int main()
{
    char s[51];
    while(scanf("%s",s)!=EOF)
    {
        int sum=0,i=0,cnt,temp,k;
        do
        {
            if(i&&s[i]<='Z'&&s[i]>='A'||s[i]==0)
            {
                if(s[i-1]<'0'||s[i-1]>'9'&&s[i]!='('&&s[i]!=')')
                    sum+=m(&s[i-1]);
            }
            else if(s[i]>='0'&&s[i]<='9')
            {
                k=i;
                cnt=0;
                while(s[i]>='0'&&s[i]<='9')
                {
                    cnt=10*cnt+s[i]-'0';
                    ++i;
                }
                sum+=m(&s[k-1])*cnt;
                if(s[i]) i-=1;
            }
            else if(s[i]=='(')
            {
                if(i&&(s[i-1]<'0'||s[i-1]>'9')) sum+=m(&s[i-1]);
                temp=0;
                while(s[i++]!=')')
                {
                    if(s[i-1]!='('&&s[i]<='Z'&&s[i]>='A'||s[i]==')')
                   {
                        if(s[i-1]<'0'||s[i-1]>'9')
                        temp+=m(&s[i-1]);
                   }
                    else if(s[i]>'0'&&s[i]<='9')
                   {
                        k=i;
                        cnt=0;
                        while(s[i]>='0'&&s[i]<='9')
                        {
                            cnt=10*cnt+s[i]-'0';
                            ++i;
                        }
                        temp+=m(&s[k-1])*cnt;
                        if(s[i]!=')') i-=1;
                   }
                }
                k=i;
                cnt=0;
                while(s[i]>='0'&&s[i]<='9')
                {
                    cnt=10*cnt+s[i]-'0';
                    ++i;
                }
                sum+=temp*cnt;
                if(s[i]) i-=1;
            }
        }while(s[i++]);
        printf("%d\n",sum);
    }
    return 0;
}
//һֱδ��ͨ��������δ���������������Ż��������������ֵ����