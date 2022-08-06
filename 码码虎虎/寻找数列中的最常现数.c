/*7-5 求整数序列中出现次数最多的数 (10分)
本题要求统计一个整型序列中出现次数最多的整数及其出现次数。

输入格式：
输入在一行中给出序列中整数个数N（0<N≤1000），以及N个整数。数字间以空格分隔。

输出格式：
在一行中输出出现次数最多的整数及其出现次数，数字间以空格分隔。题目保证这样的数字是唯一的。

输入样例：
10 3 2 -1 5 3 4 3 0 3 2
输出样例：
3 4*/
#include<stdio.h>
void swap(int *x, int *y);
int main() 
{
    int n, max = 0, sign, cnt = 0;
    scanf("%d", &n);
    int s[n];
    for(int i = 0; i < n; ++i)
    scanf("%d", &s[i]);
    for(int i = 0; i < n; ++i)
    for(int j = n-1; j > i; --j)
    if(s[j] > s[j-1]) swap(&s[j], &s[j-1]);      //先将数组按从大到小的方式进行(冒泡)排序方便后续的统计
    for(int i = 0; i < n; ++i) 
    {
        ++cnt;
        if(i == n-1 || s[i+1]-s[i]) 
        {
            if(cnt > max) 
            {
                max = cnt;
                sign = s[i];
            }
            cnt = 0;
        }
    }
    printf("%d %d", sign, max);
}
void swap(int *x, int *y)                         //首次使用指针构造swap函数
{
    int cup;
    cup=*x;
    *x=*y;
    *y = cup;
}

//第二次做本题(忘记做过了):
//求整数序列中出现次数最多的数:(输入一个正整数n以及元素个数为n的一个整数数列)
#include<stdio.h>
void swap(int *p,int*q)
{
    int cup=*p;
    *p=*q;
    *q=cup;
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n+1];
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    arr[n]=0;                       //末尾添0是防止出现最多的那个数是数列中最大的数(填补for循环的漏洞)
    for(int i=1;i<n;++i)
    {
        int j=i,temp=arr[i];
		while(arr[--j]>temp)
		swap(&arr[j],&arr[j+1]);
    }                              //这里采用了插入排序(排序时已忽略末尾的0)再统计各个数出现的次数
    int cnt=1,max=0,idex;
    for(int i=1;i<=n;++i)
    {
        if(arr[i]==arr[i-1]) cnt++;
        else
        {
            if(max<cnt) 
            {
                max=cnt;
                idex=i-1;
            }
            cnt=1;
        }
    }
    printf("%d %d",arr[idex],max);
    return 0;
}
//P.s.由于本题的数列构成可能有负整数因此难以应用CountSort的思想