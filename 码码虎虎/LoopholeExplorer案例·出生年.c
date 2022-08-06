//Loophole Explorer
/*案例:7-2 出生年 (20分)

以上是新浪微博中一奇葩贴：“我出生于1988年，直到25岁才遇到4个数字都不相同的年份。”也就是说，直到2013年才达到“4个数字都不相同”的要求。
本题请你根据要求，自动填充“我出生于y年，直到x岁才遇到n个数字都不相同的年份”这句话。

输入格式：
输入在一行中给出出生年份y和目标年份中不同数字的个数n，其中y在[1, 3000]之间，n可以是2、或3、或4。注意不足4位的年份要在前面补零，例如:
公元1年被认为是0001年，有2个不同的数字0和1。

输出格式：
根据输入，输出x和能达到要求的年份。数字间以1个空格分隔，行首尾不得有多余空格。年份要按4位输出。注意：所谓“n个数字都不相同”是指不同的数字正好是n个。如“2013”被视为满足“4位数字都不同”的条件，但不被视为满足2位或3位数字不同的条件。

输入样例1：
1988 4
输出样例1：
25 2013
输入样例2：
1 2
输出样例2：
0 0001*/

//初始代码:
#include<stdio.h>
int main()
{
    int bir,x,cnt=0,judge,j;
    
    scanf("%d %d",&bir,&x);
    int s[4];
    for(j=bir;;++j)
    {
    int cup=j;
    for(int i=0;i<4;++i)
    {
        s[i]=cup%10;
        cup/=10;
    }
    judge=(s[0]==s[1])+(s[0]==s[2])+(s[0]==s[3])+(s[2]==s[1])+(s[3]==s[1])+(s[3]==s[2]);
    if(judge==(5-x)*(4-x)/2) break;       //judge判断：此处设计了一个映射关系,该表达式可以直接计算，也可以用二次函数
        ++cnt;                            //(continued)(因为x只有三个取值，三个映射关系可以直接确定一个二次函数)标准式直接待定系数
    }
    printf("%d %04d",cnt,bir+cnt);
    return 0;
}
/*这题目确实并不难，但笔者在提交时一直无法通过测试点4，而在苦苦凝视之后依旧一无所获.在另一个提交处给出了测试点4的如下提示：n是2，输出有前补0.
可还是毫无头绪，在输入多个测试数据却无差错之后，笔者决定依靠正确代码查找漏洞点.*/

//好友阿呆(网名)给我提供了网上的一段代码，我先在测试平台上证明了该代码的正确性，而后设计了如下检漏代码：
#include<stdio.h>
int myf(int bir);
int trf(int m);
int main()
{
    for(int i=1;i<=3000;++i)
    {
        if(myf(i)!=trf(i))
        printf("%d:Mine was %d instead of %d\n",i,myf(i),trf(i));
    }
    return 0;
}
int myf(int bir)
{
    int s[4],judge,cnt=0;
    const int x=2;
    for(int j=bir;;++j)
    {
    int cup=j;
    for(int i=0;i<4;++i)
    {
        s[i]=cup%10;
        cup/=10;
    }
    judge=(s[0]==s[1])+(s[0]==s[2])+(s[0]==s[3])+
        (s[2]==s[1])+(s[3]==s[1])+(s[3]==s[2]);
    if(judge==(4-x)*(5-x)/2) break;
        ++cnt;
    }
    return cnt;
}
//阿呆提供的代码(改造后)：
int trf(int m)
{
	int i,j,k,l,ch[4];
    const int n=2;
	for(i=m;i<10000;i++)
	{
		j=1;l=i;
		for(k=0;k<4;k++,l/=10)
		ch[k]=l%10;
		if(ch[0]!=ch[1]&&ch[0]!=ch[2]&&ch[0]!=ch[3])
		j++;
		if(ch[1]!=ch[2]&&ch[1]!=ch[3])
		j++;
		if(ch[2]!=ch[3])
		j++;
		if(j==n)
		break;
	}
	return i-m;
}

/*P.s.
1.本质上是寻找出现问题的数据点，问题数据点的共性往往能明显揭露问题核心 
2.这里之所以只比较输出数据中的一个是因为之前已验证两个输出数据存在联动关系且排除了仅其中一个出错的可能*/

/*根据检漏代码的输出迅速发现了AABB(A与B无顺序之分,即亦包含ABAB)类的年份不满足我设计的judge判断方法，
我的judge判断方法在n=2时仅能判断AAAB类的年份*/

//发现问题之后:
#include<stdio.h>
int main()
{
    int bir,x,cnt=0,judge,j;
    
    scanf("%d %d",&bir,&x);
    int s[4];
    for(j=bir;;++j)
    {
    int cup=j;
    for(int i=0;i<4;++i)
    {
        s[i]=cup%10;
        cup/=10;
    }
    judge=(s[0]==s[1])+(s[0]==s[2])+(s[0]==s[3])+(s[2]==s[1])+(s[3]==s[1])+(s[3]==s[2]);
    if(judge==2) judge=3;               //补丁!
    if(judge==(5-x)*(4-x)/2) break;
        ++cnt;
    }
    printf("%d %04d",cnt,bir+cnt);
    return 0;
}
//bingo!!!