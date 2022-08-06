/*7-40 到底是不是太胖了 
据说一个人的标准体重应该是其身高（单位：厘米）减去100、再乘以0.9所得到的公斤数。
真实体重与标准体重误差在10%以内都是完美身材（即 | 真实体重 ? 标准体重 | < 标准体重×10%）。
已知市斤是公斤的两倍。现给定一群人的身高和实际体重，请你告诉他们是否太胖或太瘦了。

输入格式：
输入第一行给出一个正整数N（≤ 20）。随后N行，每行给出两个整数，分别是一个人的身高H（120 < H < 200；单位：厘米）和真实体重W（50 < W ≤ 300；单位：市斤），其间以空格分隔。

输出格式：
为每个人输出一行结论：如果是完美身材，输出You are wan mei!；如果太胖了，输出You are tai pang le!；否则输出You are tai shou le!。

输入样例：
3
169 136
150 81
178 155
输出样例：
You are wan mei!
You are tai shou le!
You are tai pang le!*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n,sign,k;                                  //sign的类型意味着n不能太大!
    double w,W,h;
    
    scanf("%d",&n);
    sign=0;
    k=1;
    for(int i=1;i<=n;++i)
    {
        scanf("\n%lf %lf",&h,&w);
        W=(h-100)*0.9;
        if(fabs(w/2-W)>=0.1*W) 
            (w/2<W)?sign+=k:(sign+=2*k);
        else sign+=3*k;                       
        k*=10;
    }
    while (sign)
    {
        switch(sign%10)
        {
            case 1:printf("You are tai shou le!\n");break;
            case 2:printf("You are tai pang le!\n");break;
            case 3:printf("You are wan mei!\n");break;
        }
        sign/=10;
    }
    return 0;
}
//本题并不难，不过上述程序实现了一并输入一并输出的方式，但由于整型的范围限制依旧无法实现(n<=20)的条件.