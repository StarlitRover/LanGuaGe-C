//星期几？
#include<stdio.h>
int main()
{
    int year,month,day,sign,x,y;
    scanf("%d/%d/%d",&year,&month,&day);
    year-=(month-2<1)*1;
    month=month-2+(month-2<1)*12;
    y=year%100;
    x=year/100;
    sign=day+(13*month-1)/5+y+y/4+x/4-2*x;  //该公式参考自《初等数论》 附录
    if(sign<0) sign+=7;                     //一旦sign为负则其模余数亦为负会出问题
    switch(sign%7)
    {
        case 0:printf("sunday");break;
        case 1:printf("monday");break;
        case 2:printf("tuesday");break;
        case 3:printf("wednesday");break;
        case 4:printf("thursday");break;
        case 5:printf("friday");break;
        case 6:printf("saturday");break;
    }
    return 0;
}

#include<stdio.h>
int main()
{
    int d[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}};
    int year,month,day,sign,delta,sum=0;
    scanf("%d/%d/%d",&year,&month,&day);
    sign=year%400==0||year%4==0&&year%100!=0;
    delta=year-1900;                                                //1900.1.1是星期一
    sum=delta*365+(delta-1)/4-(delta-1)/100+(300+delta-1)/400+day;  //关键300:1900本身不是400整除式闰年
    for(int i=month-1;i>0;--i)
    sum+=d[sign][i];
    switch(sum%7)
    {
        case 0:printf("sunday");break;
        case 1:printf("monday");break;
        case 2:printf("tuesday");break;
        case 3:printf("wednesday");break;
        case 4:printf("thursday");break;
        case 5:printf("friday");break;
        case 6:printf("saturday");break;
    }
    return 0;
}