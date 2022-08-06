/*7-49 Have Fun with Numbers (20��)
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. 
Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, 
only in a different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, 
you are to tell if the resulting number consists of only a permutation of the digits in the original number.

Input Specification:
Each input contains one test case. Each case contains one positive integer with no more than (K=)20 digits.

Output Specification:
For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation 
of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.

Sample Input:
1234567899
Sample Output:
Yes
2469135798*/

//����������Ƴ����ж�һ������2���Ƿ���ԭ����������(����һ�����ֳ��ֵĴ���)��һ������
#include <stdio.h>
int main() 
{
    const int K = 20;                   //no more than (K=)20 digits
    char c[K];
    int n[K+1], m[K], cup, num = 0, flag, k = 1;

    do {
        ++num;
        scanf("%c", &c[num]);
    }while(c[num] != '\n');             //��������������n��λ��

    for(int i = num-1; i >= 1; --i) 
    {
        n[i] = m[i] = c[i]-'0';         //ASCII��ת���ֱ���
        n[i] *= 2;
    }
    for(int i = num-1; i >= 1; --i)
    if(i > 1 && n[i] > 9) 
    {
        n[i] %= 10;
        ++n[i-1];
    }                                   //�����Լ�������double(��2)���㷨
    if (n[1] >= 10) 
    {
        printf("No\n"); 
		n[0] = 1; 
		n[1] %= 10; 
		k = 0;
    }
    else {
        for(int i = 1; i < num; ++i) 
        {
            flag = 0;
            for(int j = i; j < num; ++j)
            if(m[j] == n[i]) {
                cup = m[j]; 
				m[j] = m[i]; 
				m[i] = cup; 
				flag = 1; 
				break;
            }                           //������ϸϸƷζ�����֤�����������ֽṹ��ͬ�ķ�ʽ
            if (flag == 0) {printf ("No\n"); break;}
        }
        if(flag == 1) printf("Yes\n");
    }
    for(k; k < num; ++k)
    printf("%d", n[k]);
    return 0;
}
//��������ΰ��֮��������������int�ͱ����ķ�Χ���ƣ��������������˷ǳ�������ã���ú�������и���ϸ�ڵľ���ɣ�
//�����ڼ��̶���ȷʵ���ҿ�������.