/*7-1 ������Ĵ���������������
�Ӽ���������������������������-1���������������Щ����(������-1)�� ��ʾ�� 1�����򴴽��������������������������ÿ����һ���������������в���һ����㡣������-1ʱ��������Ĵ����� 2�����������������������ֵ�� 3��������ɺ�Ҫ�����ٸ�����

�����ʽ:
������������������������-1������

�����ʽ:
���������Щ������������-1����

��������:
3 8 2 9 7 4 -1
�������:
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
// ��һ��������ҵ����˵�����������