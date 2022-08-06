#include<stdio.h>
#define pi 3.1415926
int main()
{
    int n=1;
    while(n==1||n==2||n==3)
    {
    printf("1-Ball\n");
    printf("2-Cylinder\n");
    printf("3-Cone\n");
    printf("other-Exit\n");
    printf("Please enter your command:\n");
    scanf("%d",&n);
    double v,r,h;
    switch(n)
    {
        case 1:printf("Please enter the radius:\n");
               scanf("%lf",&r);
               printf("%.2f\n",4.0/3*pi*r*r*r);
               break;
        case 2:printf("Please enter the radius and the height:\n");
               scanf("%lf%lf",&r,&h);
            printf("%.2f\n",pi*r*r*h);
            break;
        case 3:printf("Please enter the radius and the height:\n");
            scanf("%lf%lf",&r,&h);
            printf("%.2f\n",1.0/3*pi*r*r*h);
            break;
        default:break;
    }
    }
    return 0;
}