#include<stdio.h>
int main ()
{
    int a,b,c,d,Sum;
    double Average;
    
    scanf("%d %d %d %d",&a,&b,&c,&d);
    Sum=a+b+c+d;
    Average=Sum/4.0; /*������4���������������Average���������*/
    printf("Sum = %d; Average = %.1f",Sum,Average);
    return 0;
}
