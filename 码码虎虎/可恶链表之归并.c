/*7-4 �����󼯺Ͻ��� (25��)
���������������ϣ�ÿ��������û���ظ�Ԫ�أ�������Ԫ�ظ���<=100000���������Ͻ����������ǽ��������

�����ʽ:
��һ����n��m����ʾ�������ϵ�Ԫ�ظ����� ��������n������m������

�����ʽ:
��һ���������Ԫ�ظ����� �ڶ��а��ǽ����������Ԫ�أ�Ԫ��֮���Կո�ָ������һ��Ԫ�غ���û�пո�

��������:
5 6
8 6 0 3 1
1 8 9 0 4 5
�������:
3
0 1 8*/
#include <stdio.h>
#include <stdlib.h>
int cnt = 0;                               //ȫ�ֱ���cntʹ�����������б������
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
        temp = temp->next = q;             //���ָ�ֵ��ʽ�����Ч���������ɽ��ͬʱʹtemp����һλ
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
    while (lhead || rhead)            //Ϊ���Ч�ʶ��ֳ��������
    {
        if (lhead == NULL)            //��һ��Ϊ������һ��ʣ�ಿ��ȫ������ȥ
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
            ++cnt;                     //�ɱ�֤ÿ����ͬ������ֻ��cnt���һ��
            tail->next = lhead;
            tmp = lhead->next;
            tail = lhead->next = rhead;
            lhead = tmp;
            rhead = rhead->next;
        }
    }
    return *phead;                    //��һ��������Ҫ���൱�ڰѲ�������������ɺ��һ��Ԫ�ص�λ�ô���ȥ
}
//*phead�����ƶ�����Ҫ�ϲ�������������Ԫ���е���СԪ�أ�����һ���ᵽ���γ�ʼ�����е���СԪ��λ����
single *linkMergeSort(single *head, single **phead)
{
    if (head->next == NULL)
        return head;
    single *rhead = head, *ast = head->next; //Ϊ����ʧǰһ�������ĩβ(Ϊ����ض�)����ast����һ��
    while (ast && ast->next)          //�踨��ָ��ast��һ������֮����������е�λ��
    {
        ast = ast->next->next;
        rhead = rhead->next;
    }
    ast = rhead;
    rhead = rhead->next;
    ast->next = NULL;                //������ض�һ��Ϊ��
    single *p = linkMergeSort(head, phead);   //��ȡ������ɺ��һ��Ԫ�ص�λ��
    single *q = linkMergeSort(rhead, phead);  //ͬ��
    return linkMerge(p, q, phead);
}
void freelink(single *head)
{
    single *temp = head, *cltemp;
    while (cltemp)                   //�������Ƚ�tempָ��free�����ƶ�����һ��λ�ã���ʱtemp->next�Ѿ��޼���Ѱ
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
    while (latter)                  //��������ɺ�������������ڵ�Ԫ����ͬ���������
    {                               //(continued)��Ҳ������ÿ��������û���ظ���Ԫ��
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
//����ָ���ڴ˴������˾޴������