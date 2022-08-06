#include<stdio.h>
int main ()
{
	double celsius,fahr;
	
	printf("Enter fahr:");
	scanf("%lf",&fahr);
	celsius=5*(fahr-32)/9;
	printf("Corresponding celsius:%.4f",celsius); /*%.nf指保留n位小数*/
	return 0;
}