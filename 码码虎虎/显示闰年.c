#include<stdio.h>
int main ()
{
    int year,i;
    
    scanf("%d",&year);
    if (year<=2000)
        printf("Invalid year!");
    else if (year>2100)
        printf("Invalid year!");
    else if (year>2000&&year<2004)
        printf("None");
    else {
        i=2004;
        while (i<=year&&i%100!=0){
            printf("%d\n",i);
            i+=4;
        }
    }
    return 0;
}
//²»¹»ÍêÉÆ£¡