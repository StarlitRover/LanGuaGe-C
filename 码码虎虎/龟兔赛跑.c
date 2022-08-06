/*7-39 龟兔赛跑
乌龟与兔子进行赛跑，跑场是一个矩型跑道，跑道边可以随地进行休息。乌龟每分钟可以前进3米，兔子每分钟前进9米；兔子嫌乌龟跑得慢，觉得肯定能跑赢乌龟，于是，每跑10分钟回头看一下乌龟，若发现自己超过乌龟，就在路边休息，每次休息30分钟，否则继续跑10分钟；而乌龟非常努力，一直跑，不休息。假定乌龟与兔子在同一起点同一时刻开始起跑，请问T分钟后乌龟和兔子谁跑得快？

输入格式：
输入在一行中给出比赛时间T（分钟）。

输出格式：
在一行中输出比赛的结果：乌龟赢输出@_@，兔子赢输出^_^，平局则输出-_-；后跟1空格，再输出胜利者跑完的距离。*/
//投机取巧式：人工分析+代码辅助(借助函数图像进行单周期分析,只是可以想的简单一些,而代码还是一样的繁琐)
#include<stdio.h>
void winner(int t)
{
    int q=t%90;
    const int v=3;
    const int V=9;
    if(q%30==0||q==45)printf ("-_- %d",v*t);
    else if((q>0&&q<30)||(q>45&&q<60))
    {
        int d,p;
        
        p=q%40;
        if(p>=0&&p<=10)d=t/90*270+q/40*90+V*p;
        else d=t/90*270+(q/40+1)*V*10;
        printf("^_^ %d",d);
    }
    else printf("@_@ %d",v*t);
}
int main()
{
    int T;
    
    scanf("%d",&T);
    winner(T);
    return 0;
}
//正常方法(好吧其实也挺简便的):
#include<stdio.h>
int main() {
    int w, r, T, t, sign;
    const int V = 9;
    const int v = 3;

    scanf("%d", &T);
    w = r = sign = t = 0;
    while(t < T) {
        w = v*t;
        if (r > w) t += 30;
        else {
            t += 10;
            if (t > T) sign = 1;
            else r += V*10;
        }
    }
    if (sign == 1) r += T%10*V;
    w = v*T;
    if (r > w) printf("^_^ %d", r);
    else if(r < w) printf("@_@ %d", w);
    else printf("-_- %d", r);
    return 0;
}
