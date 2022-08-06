/*7-81 Least Prefix (10分)
Given a non-empty array of N integers A, please find the smallest integer P such that all the numbers in A are in the subarray A[0..P].

Input Format:
A positive number N, followed by a list of N non-negative integers less than 1000000. N is no larger than 1000000.

Output Format:
The smallest integer P.

Sample Input:
5
2 2 1 0 1
Sample Output:
3*/
//Explanation:寻找覆盖数列A所有元素数值的最小子列A'[0,P]，并输出P.
#include<stdio.h>
int main()
{
    int n,idex,max=0,cnt=0;
    scanf("%d",&n);
    int* s=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;++i)
    {
        scanf("%d",&s[i]);
        if(s[i]>max) max=s[i];
    }
    int* flag=(int*)malloc((max+1)*sizeof(int));
    for(int i=0;i<=max;++i)
        flag[i]=0;
    for(int i=0;i<n;++i)
        if(!flag[s[i]])
        {
            flag[s[i]]=1;
            ++cnt;
        }
    for(idex=0;idex<n;++idex)
        if(flag[s[idex]])
        {
            flag[s[idex]]=0;
            --cnt;
            if(!cnt) break;
        }
    printf("%d",idex);
    free(s);
    free(flag);
    return 0;
}
//这里运用了一点CountSort里的思想