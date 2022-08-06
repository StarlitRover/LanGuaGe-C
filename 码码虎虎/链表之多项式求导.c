/*7-3 一元多项式求导
设计函数求一元多项式的导数。

输入格式:
以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:
以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。

输入样例:
3 4 -5 2 6 1 -2 0
输出样例:
12 3 -10 1 6 0*/
#include <stdio.h>
#include <stdlib.h>
typedef struct pol
{
    int num;
    int pow;
    struct pol *next;
} pol;
void creatlink(pol *p)                   //在函数中便实现了结点的串联
{
    pol *q = (pol *)malloc(sizeof(pol));
    q->next = NULL;
    p->next = q;
}
void freelink(pol *head)
{
    pol *p = head;
    while (p)
    {
        p = head->next;
        free(head);
        head = p;
    }
}
int main()
{
    pol *temp = (pol *)malloc(sizeof(pol));
    temp->next = NULL;
    pol *head = temp;
    while (scanf("%d%d", &temp->num, &temp->pow) != EOF)
    {
        creatlink(temp);
        temp = temp->next;
    }
    temp = head;
    while (temp->next)
    {
        if (temp->pow)
        {
            if (temp != head)
                printf(" ");
            printf("%d %d", temp->num * temp->pow, temp->pow - 1);
        }
        temp = temp->next;
    }
    if (head->pow == 0)
        printf("0 0");
    freelink(head);
    return 0;
}
//本题将链表的创建与释放函数化