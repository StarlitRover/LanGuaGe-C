#include<stdio.h>
int main ()
{
    int a,b,c,d,Sum;
    double Average;
    
    scanf("%d %d %d %d",&a,&b,&c,&d);
    Sum=a+b+c+d;
    Average=Sum/4.0; /*不能是4否则两整数型相除Average会出现问题*/
    printf("Sum = %d; Average = %.1f",Sum,Average);
    return 0;
}
