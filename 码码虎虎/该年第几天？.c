#include<stdio.h>
int main()
{
    int y,m,d,n;
    
    n=0;
	printf("Enter year/month/day:");
    scanf("%d/%d/%d",&y,&m,&d);
    if (m<=2)
        n=(m+1)%2*31+d;
    else {
        for(int i=m-1;i>=1;i--){
            if(i==2)
                n+=28;
            else if(i<=7&&i%2==1)
                n+=31;
            else if(i<7&&i%2==0)
                n+=30;
            else if(i>7&&i%2==1)
                n+=30;
            else n+=31;
        }
        n+=d;
        if((y%4==0&&y%100!=0)||y%400==0)
        n++;
    }
    printf("%d",n);
    return 0;
}
