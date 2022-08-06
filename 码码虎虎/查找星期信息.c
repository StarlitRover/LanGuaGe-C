/*7-43 组织星期信息 (10分)
输入一个正整数repeat (0<repeat<10)，做repeat次下列运算：

定义一个指针数组将下面的星期信息组织起来，输入一个字符串，在表中查找，若存在，输出该字符串在表中的序号，否则输出-1。

Sunday Monday Tuesday Wednesday Thursday Friday Saturday

输入输出示例：括号内为说明，无需输入输出

输入样例 (repeat=3) :
3
Tuesday
Wednesday
year
输出样例:
3
4
-1*/
#include<stdio.h>
#include<string.h>
int main()
{
    char *s[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"}; //首次用到字符串数组
    int n,i,j;
    scanf("%d",&n);
    getchar();                      //一旦没有这个getchar，第一个字符串就会读入回车
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