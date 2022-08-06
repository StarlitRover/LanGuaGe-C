/*7-5 特殊约瑟夫问题 (25分)
编号为1…N的N个小朋友玩游戏，他们按编号顺时针围成一圈，从第一个人开始按逆时针次序报数，报到第M个人出列；然后再从下个人开始按顺时针次序报数，报到第K个人出列；再从下一个人开始按逆时针次序报数，报到第M个人出列；再从下个人开始按顺时针次序报数，报到第K个人出列……以此类推不断循环，直至最后一人出列。请编写程序按顺序输出出列人的编号。

pic.jpg

输入格式:
输入为3个正整数，分别表示N、M、K，均不超过1000。

输出格式:
输出为一行整数，为出列人的编号。每个整数后一个空格。

输入样例:
6 3 5
输出样例:
5 3 1 2 4 6 */
#include <stdio.h>
#include <stdlib.h>
typedef struct knot
{
    struct knot *p;
    int n;
    struct knot *q;
} knot;
/*void cirlinkfree(knot *p, int n)
{
    knot *tmp = p;
    for (int i = 0; i < n; ++i)
    {
        tmp = tmp->q;
        free(p);
        p = tmp;
    }
}*/           //由于结点的不断丢失而难以一起free
int main()
{
    int m, n, k;
    scanf("%d%d%d", &k, &m, &n);
    knot *head, *tail;
    for (int i = 0; i < k; ++i)
    {
        knot *tmp = (knot *)malloc(sizeof(knot));
        tmp->n = i + 1;
        if (!i)
            tail = head = tmp;
        else
        {
            tmp->p = tail;
            tail = tail->q = tmp;
        }
    }
    tail->q = head;
    head->p = tail;                   //首尾相连形成闭环
    int flag = 1, cnt;
    while (k--)
    {
        if (flag)
        {
            cnt = m;
            while (--cnt)
                head = head->p;
            printf("%d ", head->n);
            head->q->p = head->p;     //删除结点
            head->p->q = head->q;
			tail=head;                //借用tail来free该结点
            head = head->p;
			free(tail)
            flag = 0;
        }
        else
        {
            cnt = n;
            while (--cnt)
                head = head->q;
            printf("%d ", head->n);
            head->p->q = head->q;
            head->q->p = head->p;
            head = head->q;
            flag = 1;
        }
    }
	return 0;
}