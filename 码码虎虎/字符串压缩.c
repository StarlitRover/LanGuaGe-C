/*6-2 �ַ���ѹ�� (12��)
����Ҫ��ʵ��һ���ַ���ѹ���ļ򵥺�����ѹ�������ǣ����ĳ���ַ�x��������n��n>1���Σ�����n���ַ�x�滻Ϊnx����ʽ�����򱣳ֲ��䡣*/
#include <stdio.h>
#define MAXS ?

void zip( char *p );

int main()
{
    char s[MAXS];

    gets(s);
    zip(s);
    printf("%s\n", s);

    return 0;
}
void zip( char *p )
{
    int i=1,cnt=1,index=0;
    while(p[i])
    {
        if(p[i-1]==p[i])
            ++cnt;
        else
        {
            if(cnt!=1)
                p[index++]='0'+cnt;
            p[index++]=p[i-1];
            cnt=1;
        }
        ++i;
    }
    if(cnt!=1)
    {
        int fcnt=0;
        while(cnt)
        {
            fcnt=fcnt*10+cnt%10;
            cnt/=10;
        }
        while(fcnt)
        {
            p[index++]='0'+fcnt%10;
            fcnt/=10;
        }
    }
      p[index++]=p[i-1];
    p[index]='\0';
}