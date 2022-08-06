/*7-1 单链表的创建，遍历与销毁
从键盘输入任意多个正整数，输入以-1结束。逆序输出这些整数(不包括-1)。 提示： 1、逆序创建单链表。结点数据域是整型数。每输入一个整数，向链表中插入一个结点。当输入-1时结束链表的创建。 2、遍历链表，输出结点数据域的值。 3、遍历完成后，要求销毁该链表。

输入格式:
任意多的正整数，输入序列以-1结束。

输出格式:
逆序输出这些整数（不包括-1）。

输入样例:
3 8 2 9 7 4 -1
输出样例:
4 7 9 2 8 3*/
#include <stdio.h>
#include <stdlib.h>
typedef struct chain
{
    int num;
    struct chain *former;
} chain;
int main()
{
    int n;
    scanf("%d", &n);
    chain *former = NULL;
    while (n != -1)
    {
        chain *temp = (chain *)malloc(sizeof(chain));
        temp->num = n;
        if (former)
            temp->former = former;
        else
            temp->former = NULL;
        former = temp;
        scanf("%d", &n);
    }
    chain *p = NULL;
    while (former)
    {
        printf("%d", former->num);
        if (former->former)
            printf(" ");
        p = former;
        former = former->former;
        free(p);
    }
    return 0;
}
// 第一个链表作业，别说话，静静体会