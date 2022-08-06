/*7-23 IP地址转换 (20分)
一个IP地址是用四个字节（每个字节8个位）的二进制码组成。请将32位二进制码表示的IP地址转换为十进制格式表示的IP地址输出。

输入格式：
输入在一行中给出32位二进制字符串。
输出格式：
在一行中输出十进制格式的IP地址，其由4个十进制数组成（分别对应4个8位的二进制数），中间用“.”分隔开。

输入样例：
11001100100101000001010101110010
输出样例：
204.148.21.114*/
#include<stdio.h>
long long int power(int y)
{
    long long int product=1;
    for(int i=0;i<y;++i)
        product*=2;
    return product;
}
int main()
{
    char s[33];
    gets(s);
    long long int n=0;
    for(int i=31;i>=0;--i)
        if(s[i]=='1') n+=power(31-i);
    for(int i=3;i>=0;--i)
    {
        if(3-i) printf(".");
        long long int x=power(8*i);
        printf("%d",n/x);
        n=n%x;
    }
}
//直接将地址转换为整数再进行操作(二进制转十进制)