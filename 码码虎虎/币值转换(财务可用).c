/*7-83 币值转换 (20分)
输入一个整数（位数不超过9位）代表一个人民币值（单位为元），请转换成财务要求的大写中文格式。如23108元，转换后变成“贰万叁仟壹百零捌”元。
为了简化输出，用小写英文字母a-j顺序代表大写数字0-9，用S、B、Q、W、Y分别代表拾、百、仟、万、亿。于是23108元应被转换输出为“cWdQbBai”元。

输入格式：
输入在一行中给出一个不超过9位的非负整数。

输出格式：
在一行中输出转换后的结果。注意“零”的用法必须符合中文习惯。

输入样例1：
813227345
输出样例1：
iYbQdBcScWhQdBeSf
输入样例2：
6900
输出样例2：
gQjB*/
#include<stdio.h>
int main() 
{
    int n, cnt = 0, fn = 0, x, flag = 0;
    char s = 'a';

    scanf("%d", &n);
    if(n == 0) printf("a");
    while(n > 0) 
    {
        fn = 10*fn+n%10;
        n /= 10;
        ++cnt;
    }
    for(int i = cnt; i > 0; --i) 
    {
        x = fn%10;
        if(x) flag = i;                               //为检测(个十百千)万位上是否存在非零数做准备
        fn /= 10;
        if(x != 0 || fn%10 != 0) printf("%c", s+x);   
        if (x != 0 || i == 5 && flag < 9 && flag > 4) //右条件检测(个十百千)万位上是否存在非零数
        switch(i) {
            case 1: break;
            case 2: case 6: printf("S"); break;
            case 3: case 7: printf("B"); break;
            case 4: case 8: printf("Q"); break;
            case 5: printf("W"); break;
            case 9: printf("Y"); break;
        }
    }
    return 0;
}