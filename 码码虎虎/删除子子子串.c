/*7-6 删除字符串中的子串 (15分)
输入2个字符串S1和S2，要求删除字符串S1中出现的所有子串S2，即结果字符串中不能包含S2。

输入格式：
输入在2行中分别给出不超过80个字符长度的、以回车结束的2个非空字符串，对应S1和S2。

输出格式：
在一行中输出删除字符串S1中出现的所有子串S2后的结果字符串。

输入样例：
Tomcat is a male ccatat                   //注意“ccatat”！！！
cat
输出样例：
Tom is a male*/
#include <stdio.h>
#include <string.h>
char *deleStr(char *s1, char *s2, char *s) 
{ //如果s字符串在函数内构造时会发生最后传出去的指针为空指针，原因可能在于临时变量在跳出生存期时会自动销毁
    int len1 = strlen(s1), len2 = strlen(s2), idx = 0, i;
    if (len1 < len2)
    {
        strcpy(s, s1);
        return s;
    }
    for (i = 0; i <= len1 - len2; ++i)
    {
        if (s1[i] == s2[0] && !strncmp(s1 + i, s2, len2))
            i += len2 - 1;
        else
            s[idx++] = s1[i];
    }
    s[idx] = '\0';
    if (i < len1)
        strcat(s, s1 + len1 - len2 + 1);
    return s;
}
int main()
{
    char s1[81];
    char s2[81];
    char s[81];
    gets(s1);
    gets(s2);
    char *tmp = deleStr(s1, s2, s), *pre = s1;
    while (strcmp(tmp, pre))
    {
        pre = tmp;
        tmp = deleStr(tmp, s2, s);
    }
    puts(tmp);
    free(s);
} 