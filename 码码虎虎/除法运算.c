#include<stdio.h>
int main() {
    int x, y, cnt;
    const int max = 200;

    printf("Enter [int x/int y]:");
	scanf("%d/%d", &x, &y);
    x%y == 0?printf("%d", x/y): printf("%d.", x/y);
    cnt = 0;
    x %= y;
    while(x != 0 && cnt < max) {
        x *= 10;
        while(x < y) {
            printf("0");
            ++cnt;
            x *= 10;
        }
        if(cnt < max) printf("%d", x/y);
        ++cnt;
        x %= y;
    }
    return 0;
}
//最多保留到max=200位