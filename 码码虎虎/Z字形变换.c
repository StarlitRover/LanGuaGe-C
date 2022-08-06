/*Z���α任
��һ�������ַ��� s ���ݸ��������� numRows ���Դ������¡������ҽ��� Z �������С�

���������ַ���Ϊ "PAYPALISHIRING" ����Ϊ 3 ʱ���������£�

P   A   H   N
A P L S I I G
Y   I   R

֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"PAHNAPLSIIGYIR"��

����ʵ��������ַ�������ָ�������任�ĺ�����

string convert(string s, int numRows);
 

ʾ�� 1��
���룺s = "PAYPALISHIRING", numRows = 3
�����"PAHNAPLSIIGYIR"

ʾ�� 2��
���룺s = "PAYPALISHIRING", numRows = 4
�����"PINALSIGYAHRPI"
���ͣ�
P     I    N
A   L S  I G
Y A   H R
P     I      */
char *convert(char *s, int numRows)
{
    int n = strlen(s), idx = 0, cycle = 2 * numRows - 2;
    if(n<numRows||cycle==0)
        return s;               //�������������һ����
    char *otc = (char *)malloc(n+1);
    for (int i = 0; i < n; i += cycle)
        otc[idx++] = s[i];
    for (int i = 1; i < numRows - 1; ++i)
    {
        int trc = 2 * i;
        for (int j = i; j < n; j += trc)
        {
            otc[idx++] = s[j];
            trc = cycle - trc;	//ע��trcת������ĺô�
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