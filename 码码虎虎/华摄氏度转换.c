#include<stdio.h>
int main ()
{
	double celsius,fahr;
	
	printf("Enter fahr:");
	scanf("%lf",&fahr);
	celsius=5*(fahr-32)/9;
	printf("Corresponding celsius:%.4f",celsius); /*%.nfָ����nλС��*/
	return 0;
}