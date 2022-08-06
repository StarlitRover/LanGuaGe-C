/*7-4 还是求集合交集 (25分)
给定两个整数集合（每个集合中没有重复元素），集合元素个数<=100000，求两集合交集，并按非降序输出。

输入格式:
第一行是n和m，表示两个集合的元素个数； 接下来是n个数和m个数。

输出格式:
第一行输出交集元素个数； 第二行按非降序输出交集元素，元素之间以空格分隔，最后一个元素后面没有空格。

输入样例:
5 6
8 6 0 3 1
1 8 9 0 4 5
输出样例:
3
0 1 8*/
#include <stdio.h>
#include <stdlib.h>
int cnt = 0;                               //全局变量cnt使计数在排序中便完成了
typedef struct linklist
{
    int n;
    struct linklist *next;
} single;
void creatlink(single **phead, int n)
{
    single *q = (single *)malloc(sizeof(single));
    scanf("%d", &q->n);
    q->next = NULL;
    single *temp = *phead = q;
    for (int i = 0; i < n - 1; ++i)
    {
        q = (single *)malloc(sizeof(single));
        scanf("%d", &q->n);
        q->next = NULL;
        temp = temp->next = q;             //这种赋值方式简便有效，不仅生成结点同时使temp下移一位
    }
}
single *linkMerge(single *lhead, single *rhead, single **phead)
{
    single *tmp, *tail;
    if (lhead->n > rhead->n)
    {
        *phead = rhead;
        rhead = rhead->next;
        tail = *phead;
    }
    else if (lhead->n < rhead->n)
    {
        *phead = lhead;
        lhead = lhead->next;
        tail = *phead;
    }
    else
    {
        ++cnt;
        *phead = lhead;
        tmp = lhead->next;
        lhead->next = rhead;
        lhead = tmp;
        rhead = rhead->next;
        tail = (*phead)->next;
    }
    while (lhead || rhead)            //为提高效率而分成四种情况
    {
        if (lhead == NULL)            //若一端为空则将另一端剩余部分全部接上去
        {
            tail = tail->next = rhead;
            rhead = NULL;
        }
        else if (rhead == NULL)
        {
            tail = tail->next = lhead;
            lhead = NULL;
        }
        else if (lhead->n > rhead->n)
        {
            tail = tail->next = rhead;
            rhead = rhead->next;
        }
        else if (lhead->n < rhead->n)
        {
            tail = tail->next = lhead;
            lhead = lhead->next;
        }
        else
        {
            ++cnt;                     //可保证每组相同的数都只在cnt里加一次
            tail->next = lhead;
            tmp = lhead->next;
            tail = lhead->next = rhead;
            lhead = tmp;
            rhead = rhead->next;
        }
    }
    return *phead;                    //这一步至关重要，相当于把部分数组排序完成后第一个元素的位置传出去
}
//*phead不断移动到需要合并的两段链表首元素中的最小元素，最终一定会到整段初始链表中的最小元素位置上
single *linkMergeSort(single *head, single **phead)
{
    if (head->next == NULL)
        return head;
    single *rhead = head, *ast = head->next; //为不丢失前一段链表的末尾(为将其截断)，让ast先走一步
    while (ast && ast->next)          //借辅助指针ast以一倍步长之差求出链表中点位置
    {
        ast = ast->next->next;
        rhead = rhead->next;
    }
    ast = rhead;
    rhead = rhead->next;
    ast->next = NULL;                //将链表截断一分为二
    single *p = linkMergeSort(head, phead);   //获取排序完成后第一个元素的位置
    single *q = linkMergeSort(rhead, phead);  //同上
    return linkMerge(p, q, phead);
}
void freelink(single *head)
{
    single *temp = head, *cltemp;
    while (cltemp)                   //不可以先将temp指针free后再移动到下一个位置，此时temp->next已经无迹可寻
    {
        cltemp = temp->next;
        free(temp);
        temp = cltemp;
    }
}
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    single *head;
    single **phead = &head;
    creatlink(phead, m + n);
    linkMergeSort(head, phead);
    printf("%d\n", cnt);
    single *former = head, *latter = head->next;
    int judge = cnt;
    while (latter)                  //若排序完成后的链表中有相邻的元素相同则将其输出，
    {                               //(continued)这也得益于每个集合中没有重复的元素
        if (former->n == latter->n)
        {
            if (judge != cnt)
                printf(" ");
            printf("%d", former->n);
            judge--;
        }
        former = latter;
        latter = former->next;
    }
    freelink(head);
}
//二级指针在此处发挥了巨大的作用