/*7-44 黑洞数 (20分)
黑洞数也称为陷阱数，又称“Kaprekar问题”，是一类具有奇特转换特性的数。

任何一个各位数字不全相同的三位数，经有限次“重排求差”操作，总会得到495。最后所得的495即为三位黑洞数。所谓“重排求差”操作即组成该数的数字重排后的最大数减去重排后的最小数。（6174为四位黑洞数。）

例如，对三位数207：

第1次重排求差得：720 - 27 ＝ 693；
第2次重排求差得：963 - 369 ＝ 594；
第3次重排求差得：954 - 459 ＝ 495；
以后会停留在495这一黑洞数。如果三位数的3个数字全相同，一次转换后即为0。

任意输入一个三位数，编程给出重排求差的过程。

输入格式：
输入在一行中给出一个三位数。

输出格式：
按照以下格式输出重排求差的过程：

序号: 数字重排后的最大数 - 重排后的最小数 = 差值
序号从1开始，直到495出现在等号右边为止。

输入样例：
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
//以上程序已推广到任意位数的整数,although 可能还有少许不整洁