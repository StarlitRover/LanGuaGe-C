/*7-17 ��Գ��Ӵ� (25��)
�Ը������ַ���������Ҫ���������Գ��Ӵ��ĳ��ȡ����磬����Is PAT&TAP symmetric?����Գ��Ӵ�Ϊs PAT&TAP s��������Ӧ�����11��

�����ʽ��
������һ���и������Ȳ�����1000�ķǿ��ַ�����
�����ʽ��
��һ���������Գ��Ӵ��ĳ��ȡ�

����������
Is PAT&TAP symmetric?
���������
11*/
#include<stdio.h>
#include<string.h>
int main()
{
    char s[1001];
    gets(s);
    int n=strlen(s),max=1,cnt;
    for(int i=1;i<n-1;++i)                   //֮����ѭ����ʼĩ�����������ʼĩ�Ƿ�ֹ������Գ�ʱ��������Խ��
    {
        if(s[i-1]==s[i+1])                   //��Գ�
        {
            cnt=0;                           //cnt!=1ԭ��:cnt=0��Ϊ����cnt�ڼ���ɹ�����+1����ʵ��������ͬ��
            while(s[i-cnt-1]==s[i+cnt+1])    //(continued)��cnt!=1���Ƿ�ֹ��һ��whileѭ�����������鷢������Խ��
            {
                ++cnt;
                if(i+cnt+1>=n||i-cnt-1<0) break;
            }
            if(2*cnt+1>max) max=2*cnt+1;
        }
        if(s[i-1]==s[i])                    //ż�Գ�
        {
            cnt=0;
            while(s[i-1-cnt]==s[i+cnt])
            {
                ++cnt;
                if(i-1-cnt<0||i+cnt>=n) break;
            }
            if(2*cnt>max) max=2*cnt;
        }
    }
    if(max==1&&s[n-1]==s[n-2]) max=2;        //ѭ��©���˼�����������Ƿ�Ϊż�Գƣ��˴�����
    printf("%d",max);
    return 0;
}
/*�������˼·��
1.��Ϊ��Գƺ�ż�Գ����࿼��
2.�ԶԳ�����Ϊ���Ѱ�ҶԳ��ַ��Ӵ�*/