/*二进制字符串求和
给你两个二进制字符串，返回它们的和（用二进制表示）。
输入为 非空 字符串且只包含数字 1 和 0。 

示例 1:
输入: a = "11", b = "1"
输出: "100"

示例 2:
输入: a = "1010", b = "1011"
输出: "10101"
 
提示：
每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。*/
char * addBinary(char * a, char * b)
{
    int idxa=strlen(a)-1,idxb=strlen(b)-1,idxc=(idxa>=idxb)*idxa+(idxa<idxb)*idxb,i;
    char *add=(char*)malloc(idxc+3);//+3很关键（包括‘\0’）
    add[idxc+1]='\0';
    int carry=0,sum;
    char *rem;
    for(i=idxc;i>=0;--i)
    {
        sum=a[idxa]+b[idxb]+carry-'0';
        if(sum>'1')
        {
            add[i]=sum-2;
            carry=1;
        }
        else
        {
            add[i]=sum;
            carry=0;    
        }
       --idxa;
       --idxb;
       if(idxa<0) 
       {
           rem=b;
           break;
       }
       else if(idxb<0)
       {
           rem=a;
           break;
       }
    }
    for(i-=1;i>=0;--i)
    {
        add[i]=rem[i]+carry;
        if(add[i]>'1')
            add[i]-=2;
        else 
            carry=0;
    }
    if(carry)
    {
        for(i=idxc+1;i>=0;--i)
            add[i+1]=add[i];
        add[0]='1';
    }
    return add;
}
/*Accepted
294/294 cases passed (0 ms)
Your runtime beats 100 % of c submissions
Your memory usage beats 48.12 % of c submissions (5.7 MB)