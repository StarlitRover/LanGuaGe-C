/*7-2 通讯录排序 (20分)
输入n个朋友的信息，包括姓名、生日、电话号码，本题要求编写程序，按照年龄从大到小的顺序依次输出通讯录。题目保证所有人的生日均不相同。

输入格式:
输入第一行给出正整数n（<10）。随后n行，每行按照“姓名 生日 电话号码”的格式给出一位朋友的信息，其中“姓名”是长度不超过10的英文字母组成的字符串，“生日”是yyyymmdd格式的日期，“电话号码”是不超过17位的数字及+、-组成的字符串。

输出格式:
按照年龄从大到小输出朋友的信息，格式同输出。

输入样例:
3
zhang 19850403 13912345678
wang 19821020 +86-0571-88018448
qian 19840619 13609876543
输出样例:
wang 19821020 +86-0571-88018448
qian 19840619 13609876543
zhang 19850403 13912345678*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    getchar();            //!
    int *bir = (int *)malloc(n * sizeof(int));
    char *s[n];
    for (int i = 0; i < n; ++i)
    {
        s[i] = (char *)malloc(50);
        gets(s[i]);
        int k = 0;
        while (!(s[i][k] >= '0' && s[i][k] <= '9'))
            ++k;
        bir[i] = 0;
        for (int j = 0; j < 8; ++j)
            bir[i] = bir[i] * 10 + (s[i][k + j] - '0'); //将生日转换为整数
    }
    int min, index;
    for (int i = 0; i < n; ++i)
    {
        min = (int)9e7;
        for (int j = 0; j < n; ++j)
        {
            if (bir[j] && bir[j] < min)
            {
                index = j;
                min = bir[j];
            }
        }
        puts(s[index]);
        bir[index] = 0;        //puts()遇'\0'直接换行
    }
    for (int i = 0; i < n; ++i)
        free(s[i]);
    free(bir);
    return 0;
}
//本题不难但小烦