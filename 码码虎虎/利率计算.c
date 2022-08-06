#include<stdio.h>
#include<math.h>
int main ()
{
	int year;
	double money,sum;
	const double rate=0.025;
	
	printf("Enter money:");
	scanf("%lf",&money);
	printf("Enter year:");
	scanf("%d",&year);
	sum=money*pow (rate+1,year);
	printf("sum=%f",sum);
	return 0;
}