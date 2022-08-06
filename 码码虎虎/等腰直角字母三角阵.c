#include<stdio.h>
int main()
{
    char m='A';
    int r,v;
    
    scanf("%d",&r);
    for (r;r>=1;r--){
        for (v=0;v<=r-1;v++)
            printf("%c ",m+v);
        printf("\n");
        m+=r;
    }
    return 0;
}
