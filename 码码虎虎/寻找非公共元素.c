/*7-46 �ҳ������������鹲�е�Ԫ�� (20��)
���������������飬����Ҫ���ҳ��������߹��е�Ԫ�ء�

�����ʽ:
����ֱ��������и��������������飬ÿ���ȸ���������N����20���������N������������Կո�ָ���

�����ʽ:
��һ���а������ָ�����˳��������������鹲�е�Ԫ�أ����ּ��Կո�ָ�������ĩ�����ж���Ŀո���Ŀ��֤���ٴ���һ�����������֡�ͬһ���ֲ��ظ������

��������:
10 3 -5 2 8 0 3 5 -15 9 100
11 6 4 8 2 6 -5 9 0 100 8 1
�������:
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
            if (a[j] == temp)                //һ��ʼ�ͽ�ͬһ�����ظ���Ԫ��ɾȥ��
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
//ûʲô�����˼�룬����Ŀ����ϸ�ںܶ࣬��Ҫ����ȫ��
//���㷨�е��߳����Ż���ؽϴ�