/*7-13 删除重复字符 (20分)
本题要求编写程序，将给定字符串去掉重复的字符后，按照字符ASCII码顺序从小到大排序后输出。

输入格式：
输入是一个以回车结束的非空字符串（少于80个字符）。
输出格式：
输出去重排序后的结果字符串。

输入样例：
ad2f3adjfeainzzzv
输出样例：
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
//本题思想的关键是完全把字符当成了整数进行运算,同时本题运用了CountSort的思想哦