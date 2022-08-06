#include<stdio.h>
int main () {
    double x, y;

    printf("Enter x(x>=0):");
    scanf("%lf", &x);
    if (x<=15){
        y = 4*x/3;
    }
    else {
        y = 2.5*x-10.5;
    }
    printf ("y=f(%f)=%.7f",x,y);
    return 0;
}
