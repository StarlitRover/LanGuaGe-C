/*7-5 时间换算 (14分)
本题要求编写程序，以hh:mm:ss的格式输出某给定时间再过n秒后的时间值（超过23:59:59就从0点开始计时）。

输入格式：
输入在第一行中以hh:mm:ss的格式给出起始时间，第二行给出整秒数n（<60）。

输出格式：
输出在一行中给出hh:mm:ss格式的结果时间。

输入样例：
11:59:40
30
输出样例：
12:00:10*/
#include<stdio.h>
int main ()
{
    int h,m,s,t;
    
    scanf("%d:%d:%d\n",&h,&m,&s);
    scanf("%d",&t);
    if (t+s>=60){
        if (m!=59){
            m=m+1,s=t+s-60;
        }
        else {
            if (h!=23){
                h=h+1,m=0,s=t+s-60;
            }
            else {
                h=0,m=0,s=t+s-60;
            }
        }
    }
    else
        s=t+s;
	printf("%02d:%02d:%02d",h,m,s);/*ATTENTION:%0kd表示恒为k位数且空格用0填充*/
    return 0;
}
