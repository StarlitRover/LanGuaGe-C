/*7-17 最长对称子串 (25分)
对给定的字符串，本题要求你输出最长对称子串的长度。例如，给定Is PAT&TAP symmetric?，最长对称子串为s PAT&TAP s，于是你应该输出11。

输入格式：
输入在一行中给出长度不超过1000的非空字符串。
输出格式：
在一行中输出最长对称子串的长度。

输入样例：
Is PAT&TAP symmetric?
输出样例：
11*/
#include<stdio.h>
#include<string.h>
int main()
{
    char s[1001];
    gets(s);
    int n=strlen(s),max=1,cnt;
    for(int i=1;i<n-1;++i)                   //之所以循环的始末均不是数组的始末是防止查找奇对称时发生数组越界
    {
        if(s[i-1]==s[i+1])                   //奇对称
        {
            cnt=0;                           //cnt!=1原因:cnt=0是为了让cnt在检验成功后再+1且与实际意义相同，
            while(s[i-cnt-1]==s[i+cnt+1])    //(continued)而cnt!=1则是防止第一次while循环的条件检验发生数组越界
            {
                ++cnt;
                if(i+cnt+1>=n||i-cnt-1<0) break;
            }
            if(2*cnt+1>max) max=2*cnt+1;
        }
        if(s[i-1]==s[i])                    //偶对称
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
    if(max==1&&s[n-1]==s[n-2]) max=2;        //循环漏掉了检验最后两项是否为偶对称，此处补上
    printf("%d",max);
    return 0;
}
/*本题基本思路：
1.分为奇对称和偶对称两类考虑
2.以对称中心为起点寻找对称字符子串*/