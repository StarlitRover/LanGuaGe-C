/*7-49 Have Fun with Numbers (20分)
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

//导读：请设计程序判断一个数×2后是否是原来所含数字(包括一个数字出现的次数)的一个排列
#include <stdio.h>
int main() 
{
    const int K = 20;                   //no more than (K=)20 digits
    char c[K];
    int n[K+1], m[K], cup, num = 0, flag, k = 1;

    do {
        ++num;
        scanf("%c", &c[num]);
    }while(c[num] != '\n');             //这里巧妙地算出了n的位数

    for(int i = num-1; i >= 1; --i) 
    {
        n[i] = m[i] = c[i]-'0';         //ASCII码转数字本身
        n[i] *= 2;
    }
    for(int i = num-1; i >= 1; --i)
    if(i > 1 && n[i] > 9) 
    {
        n[i] %= 10;
        ++n[i-1];
    }                                   //这里自己编制了double(×2)的算法
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
            }                           //这里需细细品味如何验证两者所含数字结构相同的方式
            if (flag == 0) {printf ("No\n"); break;}
        }
        if(flag == 1) printf("Yes\n");
    }
    for(k; k < num; ++k)
    printf("%d", n[k]);
    return 0;
}
//这个程序的伟大之处在于它打破了int型变量的范围限制，数组在其中起到了非常大的作用，请好好体会其中各个细节的精妙吧！
//不过在简洁程度上确实不敢堪称完美.