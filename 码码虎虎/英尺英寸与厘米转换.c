/*如果已知英制长度的英尺foot和英寸inch的值，
那么对应的米是(foot+inch/12)×0.3048。现在，
如果用户输入的是厘米数，那么对应英制长度的英
尺和英寸是多少呢？别忘了1英尺等于12英寸。*/

#include<stdio.h>
int main()
{
    int foot,inch;
    double meter,cm;
    
    scanf("%lf",&cm);
    meter=0.01*cm;
    inch=meter/0.3048*12;
    foot=inch/12;
    inch%=12;
    printf("%d %d",foot,inch);
    return 0;
}
