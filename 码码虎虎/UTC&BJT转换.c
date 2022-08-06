#include<stdio.h>
int main() {
    int BJT, m, UTC;
    scanf("%d", &BJT);
    if(BJT < 100)
    printf("16%02d", BJT);
    else {
        m = 60*(BJT/100)+BJT%100;
        UTC = m+16*60;
        UTC %= (24*60);
        if(UTC < 10)
        printf("%d", UTC);
        else printf("%d%02d", UTC/60, UTC%60);
    }
    return 0;
}