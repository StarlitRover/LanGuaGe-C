/*7-1 顺时针矩阵 (14分)
读入20内正整数正整数n，输出顺时针分布的矩阵。矩阵内容为1，2，。。。到n*n。

输入格式:
每个实例包含一个20内正整数。
输出格式:
顺时针分布的矩阵，每个数据占4位。

输入样例:
7
输出样例:
  19  20  21  22  23  24   1
  18  37  38  39  40  25   2
  17  36  47  48  41  26   3
  16  35  46  49  42  27   4
  15  34  45  44  43  28   5
  14  33  32  31  30  29   6
  13  12  11  10   9   8   7*/
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int r[n][n],s=1;
    for(int i=n;i>n/2;--i)
    {
        for(int j=n-i;j<i;++j)
            r[j][i-1]=s++;
        for(int j=i-2;j>=n-i;--j)
            r[i-1][j]=s++;
        for(int j=i-2;j>=n-i;--j)
            r[j][n-i]=s++;
        for(int j=n-i+1;j<i-1;++j)
            r[n-i][j]=s++;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            printf("%4d",r[i][j]);
        printf("\n");
    }
            return 0;
}
//将每一圈作为一个循环
