#include<stdio.h>
int main()
{
    int n,j;
    
    scanf("%d",&n);
    j=0;
    for (int i=1;i<=1000;i++){               //Pay attention to "==" rather than "=".
        if (i/100+i%100/10+i%10==n){
            printf("%8d",i);
            j++;
            if (j%6==0)                      //And it need to seek why.
            printf("\n");
        }
    }
    return 0;
}