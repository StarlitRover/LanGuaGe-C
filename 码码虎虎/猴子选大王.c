/*7-34 猴子选大王 (20分)
一群猴子要选新猴王。新猴王的选择方法是：让N只候选猴子围成一圈，从某位置起顺序编号为1~N号。从第1号开始报数，
每轮从1报到3，凡报到3的猴子即退出圈子，接着又从紧邻的下一只猴子开始同样的报数。如此不断循环，最后剩下的一只
猴子就选为猴王。请问是原来第几号猴子当选猴王？

输入格式：
输入在一行中给一个正整数N（≤1000）。
输出格式：
在一行中输出当选猴王的编号。

输入样例：
11
输出样例：
7*/
#include<stdio.h>
int main()
{
    int n,idex=0,flag=1;            //flag指当前报数的值(我们认为flag=0代表3的报数,此举可以方便后续操作)
    scanf("%d",&n);
    int cnt=n;
    int monkey[n];
    for(int i=0;i<n;++i)
        monkey[i]=1;
    while(1)
    {
        if(monkey[idex])            //这里两个if内外的条件需清楚放置
        {
            if(!flag) 
            {
                monkey[idex]=0;
                --cnt;
                if(!cnt) break;    //当cnt减为0时则代表所有猴子都已退出
            }
            flag=(flag+1)%3;
        }
        idex=(idex+1)%n;           //%n 使得报数可以成圈循环
    }
    printf("%d",idex+1);           //每个猴子对应的编号都是数组下标+1
    return 0;
}
//基本思路:构造一个代表每个猴子状态的标记数组,1代表该猴子还未退出,0则代表已退出.
//最后一个退出的猴子即为所求