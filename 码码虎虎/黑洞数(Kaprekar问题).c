/*7-44 �ڶ��� (20��)
�ڶ���Ҳ��Ϊ���������ֳơ�Kaprekar���⡱����һ���������ת�����Ե�����

�κ�һ����λ���ֲ�ȫ��ͬ����λ���������޴Ρ��������������ܻ�õ�495��������õ�495��Ϊ��λ�ڶ�������ν����������������ɸ������������ź���������ȥ���ź����С������6174Ϊ��λ�ڶ�������

���磬����λ��207��

��1���������ã�720 - 27 �� 693��
��2���������ã�963 - 369 �� 594��
��3���������ã�954 - 459 �� 495��
�Ժ��ͣ����495��һ�ڶ����������λ����3������ȫ��ͬ��һ��ת����Ϊ0��

��������һ����λ������̸����������Ĺ��̡�

�����ʽ��
������һ���и���һ����λ����

�����ʽ��
�������¸�ʽ����������Ĺ��̣�

���: �������ź������� - ���ź����С�� = ��ֵ
��Ŵ�1��ʼ��ֱ��495�����ڵȺ��ұ�Ϊֹ��

����������
123*/
#include<stdio.h>
int main() {
    int min, x, y, n, temporary, maxint, minint, q, difference, previous, count, k;
    int cnt = 0;

    scanf("%d", &x);
    do
    {
        previous = x;
        q = 1; temporary = n = maxint = count = minint = k = 0;
        y = x;
        while(y > 0) {
            ++n;
            y /= 10;
        }
        int s[n];
        for (int i = 0; i < n; ++i) {
            s[i] = x%10;
            x /= 10;
        }
        while (count < n) {
            min = 10;
            for(int j = 0; j < n; ++j) {
                if(s[j] < min && s[j] >= temporary) {
                    min = s[j];
                    k = j;
                }
            }
            maxint += q*min;
            temporary = min;
            q *= 10;
            ++count;
            s[k] = 10;
        }
        y = maxint;
        while(y > 0) {
            minint = minint*10+y%10;
            y /= 10;
        }
        difference = maxint-minint;
        ++cnt;
        if (cnt == 1 || previous != difference) printf("%d: %d - %d = %d\n", cnt, maxint, minint, difference);
        else break;
        x = difference;
    }while(1);
    return 0;
}
//���ϳ������ƹ㵽����λ��������,although ���ܻ�����������