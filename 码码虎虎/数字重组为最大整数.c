#include<stdio.h>
int main() {
    int x, y, n = 0, min, maxint = 0, q = 1, k = 0, count = 0, temperory = 0;

    scanf("%d", &x);
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
            if(s[j] < min && s[j] >= temperory) {
                min = s[j];
                k = j;
            }
        }
        maxint += q*min;
        temperory = min;
        q *= 10;
        ++count;
        s[k] = 10;
    }
    printf("%d", maxint);
    return 0;
}
//这个程度的弊端在于x的值不能超出int型变量范围!