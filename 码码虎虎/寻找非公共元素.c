/*7-46 找出不是两个数组共有的元素 (20分)
给定两个整型数组，本题要求找出不是两者共有的元素。

输入格式:
输入分别在两行中给出两个整型数组，每行先给出正整数N（≤20），随后是N个整数，其间以空格分隔。

输出格式:
在一行中按照数字给出的顺序输出不是两数组共有的元素，数字间以空格分隔，但行末不得有多余的空格。题目保证至少存在一个这样的数字。同一数字不重复输出。

输入样例:
10 3 -5 2 8 0 3 5 -15 9 100
11 6 4 8 2 6 -5 9 0 100 8 1
输出样例:
3 5 -15 6 4 1*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n, i, j, cnta = 0, cntb = 0, temp, flag = 0;
    scanf("%d", &m);
    int *a = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; ++i)
    {
        scanf("%d", &temp);
        for (j = 0; j < cnta; ++j)
            if (a[j] == temp)                //一开始就将同一组中重复的元素删去了
                break;
        if (j == cnta)
            a[cnta++] = temp;
    }
    scanf("%d", &n);
    int *b = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &temp);
        for (j = 0; j < cntb; ++j)
            if (b[j] == temp)
                break;
        if (j == cntb)
            b[cntb++] = temp;
    }
    for (i = 0; i < cnta; ++i)
    {
        for (j = 0; j < cntb; ++j)
            if (a[i] == b[j])
                break;
        if (j == cntb)
        {
            if (flag)
                printf(" ");
            printf("%d", a[i]);
            flag = 1;
        }
    }
    for (i = 0; i < cntb; ++i)
    {
        for (j = 0; j < cnta; ++j)
            if (a[j] == b[i])
                break;
        if (j == cnta)
        {
            if (flag)
                printf(" ");
            printf("%d", b[i]);
            flag = 1;
        }
    }
    free(a);
    free(b);
    return 0;
}
//没什么高深的思想，但题目本身细节很多，需要考虑全面
//该算法有点冗长，优化余地较大