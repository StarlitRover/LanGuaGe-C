/*对任意一个自然数N0，先将其各位数字相加求和，再将其和乘以3后加上1，变成一个新自然数N1，
然后对N1重复这种操作，可以产生新自然数N2，多次重复这种操作运算，运算结果最终会得到一个
固定不变的数Nk，就像掉入一个数字“陷阱”。
对输入的自然数，给出其掉入“陷阱”的过程，
输入：一个自然数N（N<100000）
输出：多行内容，第i行是自然数N掉入陷阱的第i步，格式为： i:Ni，
当某个第k步的结果Nk与上一步相同时，停止输出。
样例输入：
5
样例输出：
1:16
2:22
3:13
4:13*/
#include<stdio.h>
int main() {
    int N, n, sum1, sum2, cnt;
    scanf("%d", &N);
    sum1 = sum2 = cnt = 0;
    do
    {
        sum1 = sum2;
        sum2=0;
        while(N > 0) {
            sum2 += (N%10);
            N /= 10;
        }
        sum2 = 3*sum2+1;
        ++cnt;
        N = sum2;
        if(cnt!=2||sum2!=sum1)
        printf("%d:%d\n", cnt, N);
    }while(sum1 != sum2);
    return 0;
}
