#include<stdio.h>
int main () {
    int x;

    scanf("%d", &x);
    printf("%d=", x);
    while(x > 1) {
        for (int i = 2; i <= x; ++i) {
            if(x%i == 0) {
                ((x /= i) != 1)?printf("%d*", i): printf("%d", i);
                break;
            }
        }
    }
    return 0;
}