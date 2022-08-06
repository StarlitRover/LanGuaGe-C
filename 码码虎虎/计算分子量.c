/*计算分子量

Problem Description
化学式的相对分子质量（简称分子量）是化学式中各原子的原子量的总和,即同种元素的相对原子质量与其原子个数相乘，
不同原子的相对原子质量相加。例如：CO2, 碳是12, 氧是16, 那么，CO2分子量就是12＋16×2＝44 。
已知各化学分子式用到的元素原子量如下：

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

计算各分子式的分子量。
 
Input
输入有多行，每行是一个分子式。处理到文件结束。
分子式长度小于50

Output
对于每一个分子式，输出占一行，一个整数，即对应的分子量。
 
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
//一直未能通过可能是未考虑括号中有括号或是括号外无数字的情况