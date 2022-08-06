/*1003 我要通过！ (20分)
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于 PAT 的“答案正确”大派送 ?? 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1.字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
2.任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3.如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式：
每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过 100，且不包含空格。

输出格式：
每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA

输出样例：
YES
YES
YES
YES
NO
NO
NO
NO*/
#include <stdio.h>
#include <string.h>
typedef enum
{
    false,
    true
} bool;
bool jdg(char *s);
int main()
{
    int n;
    scanf("%d", &n);
    char s[101];
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", s);
        if (jdg(s))
            printf("YES\n");
        else
            printf("NO\n");
    }
}
bool jdg(char *s)
{
    if (strlen(s) < 3)                           //这一步很关键,
        return false;
    char tmp;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, index = 0;
    while ((tmp = s[index++]) != 'P')
    {
        if (tmp != 'A')
            return false;
        else
            ++cnt1;
    }
    while ((tmp = s[index++]) != 'T')
    {
        if (tmp != 'A')
            return false;
        else
            ++cnt2;
    }
    while (tmp = s[index++])
    {
        if (tmp != 'A')
            return false;
        else
            ++cnt3;
    }
        if (cnt3 == cnt2 * cnt1 && cnt2 != 0)                     //条件3（可以认为是一种递归）可用该等式代替
        return true;
    	else
        return false;
}
//注意APT和PT