/*Z字形变换
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
 

示例 1：
输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"

示例 2：
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I      */
char *convert(char *s, int numRows)
{
    int n = strlen(s), idx = 0, cycle = 2 * numRows - 2;
    if(n<numRows||cycle==0)
        return s;               //特殊情况依旧是一根刺
    char *otc = (char *)malloc(n+1);
    for (int i = 0; i < n; i += cycle)
        otc[idx++] = s[i];
    for (int i = 1; i < numRows - 1; ++i)
    {
        int trc = 2 * i;
        for (int j = i; j < n; j += trc)
        {
            otc[idx++] = s[j];
            trc = cycle - trc;	//注意trc转变带来的好处
        }
    }
    for (int i = numRows - 1; i < n; i += cycle)
        otc[idx++] = s[i];
    otc[idx] = '\0';
    return otc;
}
/*Accepted
1157/1157 cases passed (8 ms)
Your runtime beats 80.02 % of c submissions
Your memory usage beats 56.12 % of c submissions (6.5 MB)