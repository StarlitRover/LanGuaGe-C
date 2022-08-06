#include<stdio.h>
int main()
{
    for (int i=1,j=4;i<=4;i++,j--){
        int s=i;
        while(s>1){
            printf(" ");
            s--;
        }
        int v=j;
        while(v>0){
            printf("* ");
            v--;
        }
        printf("\n");
    }
    return 0;
}
