/*1003 ��Ҫͨ���� (20��)
������ȷ�����Զ�����ϵͳ�����������˻�ϲ�Ļظ����������� PAT �ġ�����ȷ�������� ?? ֻҪ������ַ�����������������ϵͳ�����������ȷ��������������𰸴��󡱡�

�õ�������ȷ���������ǣ�

1.�ַ����б������ P�� A�� T�������ַ��������԰��������ַ���
2.�������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
3.��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a�� b�� c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
���ھ�����Ϊ PAT дһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�

�����ʽ��
ÿ������������� 1 �������������� 1 �и���һ�������� n (<10)������Ҫ�����ַ���������������ÿ���ַ���ռһ�У��ַ������Ȳ����� 100���Ҳ������ո�

�����ʽ��
ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ��������� YES��������� NO��

����������
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA

���������
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
    if (strlen(s) < 3)                           //��һ���ܹؼ�,
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
        if (cnt3 == cnt2 * cnt1 && cnt2 != 0)                     //����3��������Ϊ��һ�ֵݹ飩���øõ�ʽ����
        return true;
    	else
        return false;
}
//ע��APT��PT