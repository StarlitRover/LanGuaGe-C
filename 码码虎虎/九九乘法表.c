#include<stdio.h>
int main()
{
    int N;
    
    scanf("%d",&N);
    for (int r=1;r<=N;r++){
        for (int j=1;j<=r;j++){
            printf ("%d*%d=%d",j,r,j*r);
            if (j*r>=10)
                printf("  ");
            else printf("   ");
        }
        printf("\n");
    }
    return 0;
}