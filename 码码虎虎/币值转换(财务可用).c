/*7-83 ��ֵת�� (20��)
����һ��������λ��������9λ������һ�������ֵ����λΪԪ������ת���ɲ���Ҫ��Ĵ�д���ĸ�ʽ����23108Ԫ��ת�����ɡ�������ǪҼ����ơ�Ԫ��
Ϊ�˼��������СдӢ����ĸa-j˳������д����0-9����S��B��Q��W��Y�ֱ����ʰ���١�Ǫ�����ڡ�����23108ԪӦ��ת�����Ϊ��cWdQbBai��Ԫ��

�����ʽ��
������һ���и���һ��������9λ�ķǸ�������

�����ʽ��
��һ�������ת����Ľ����ע�⡰�㡱���÷������������ϰ�ߡ�

��������1��
813227345
�������1��
iYbQdBcScWhQdBeSf
��������2��
6900
�������2��
gQjB*/
#include<stdio.h>
int main() 
{
    int n, cnt = 0, fn = 0, x, flag = 0;
    char s = 'a';

    scanf("%d", &n);
    if(n == 0) printf("a");
    while(n > 0) 
    {
        fn = 10*fn+n%10;
        n /= 10;
        ++cnt;
    }
    for(int i = cnt; i > 0; --i) 
    {
        x = fn%10;
        if(x) flag = i;                               //Ϊ���(��ʮ��ǧ)��λ���Ƿ���ڷ�������׼��
        fn /= 10;
        if(x != 0 || fn%10 != 0) printf("%c", s+x);   
        if (x != 0 || i == 5 && flag < 9 && flag > 4) //���������(��ʮ��ǧ)��λ���Ƿ���ڷ�����
        switch(i) {
            case 1: break;
            case 2: case 6: printf("S"); break;
            case 3: case 7: printf("B"); break;
            case 4: case 8: printf("Q"); break;
            case 5: printf("W"); break;
            case 9: printf("Y"); break;
        }
    }
    return 0;
}