/*7-3 һԪ����ʽ��
��ƺ�����һԪ����ʽ�ĵ�����

�����ʽ:
��ָ���ݽ���ʽ�������ʽ������ϵ����ָ��������ֵ��Ϊ������1000�������������ּ��Կո�ָ���

�����ʽ:
����������ͬ�ĸ�ʽ�����������ʽ�������ϵ����ָ�������ּ��Կո�ָ�������β�����ж���ո�

��������:
3 4 -5 2 6 1 -2 0
�������:
12 3 -10 1 6 0*/
#include <stdio.h>
#include <stdlib.h>
typedef struct pol
{
    int num;
    int pow;
    struct pol *next;
} pol;
void creatlink(pol *p)                   //�ں����б�ʵ���˽��Ĵ���
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
//���⽫����Ĵ������ͷź�����