/*7-5 ����Լɪ������ (25��)
���Ϊ1��N��N��С��������Ϸ�����ǰ����˳ʱ��Χ��һȦ���ӵ�һ���˿�ʼ����ʱ���������������M���˳��У�Ȼ���ٴ��¸��˿�ʼ��˳ʱ���������������K���˳��У��ٴ���һ���˿�ʼ����ʱ���������������M���˳��У��ٴ��¸��˿�ʼ��˳ʱ���������������K���˳��С����Դ����Ʋ���ѭ����ֱ�����һ�˳��С����д����˳����������˵ı�š�

pic.jpg

�����ʽ:
����Ϊ3�����������ֱ��ʾN��M��K����������1000��

�����ʽ:
���Ϊһ��������Ϊ�����˵ı�š�ÿ��������һ���ո�

��������:
6 3 5
�������:
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
}*/           //���ڽ��Ĳ��϶�ʧ������һ��free
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
    head->p = tail;                   //��β�����γɱջ�
    int flag = 1, cnt;
    while (k--)
    {
        if (flag)
        {
            cnt = m;
            while (--cnt)
                head = head->p;
            printf("%d ", head->n);
            head->q->p = head->p;     //ɾ�����
            head->p->q = head->q;
			tail=head;                //����tail��free�ý��
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