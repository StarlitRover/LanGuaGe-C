/*7-6 ɾ���ַ����е��Ӵ� (15��)
����2���ַ���S1��S2��Ҫ��ɾ���ַ���S1�г��ֵ������Ӵ�S2��������ַ����в��ܰ���S2��

�����ʽ��
������2���зֱ����������80���ַ����ȵġ��Իس�������2���ǿ��ַ�������ӦS1��S2��

�����ʽ��
��һ�������ɾ���ַ���S1�г��ֵ������Ӵ�S2��Ľ���ַ�����

����������
Tomcat is a male ccatat                   //ע�⡰ccatat��������
cat
���������
Tom is a male*/
#include <stdio.h>
#include <string.h>
char *deleStr(char *s1, char *s2, char *s) 
{ //���s�ַ����ں����ڹ���ʱ�ᷢ����󴫳�ȥ��ָ��Ϊ��ָ�룬ԭ�����������ʱ����������������ʱ���Զ�����
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