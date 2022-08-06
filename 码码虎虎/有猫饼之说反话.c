/*7-4 说反话-加强版 (14分)
给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：
测试输入包含一个测试用例，在一行内给出总长度不超过500 000的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用若干个空格分开。

输出格式：
每个测试用例的输出占一行，输出倒序后的句子，并且保证单词间只有1个空格。

输入样例：
Hello World   Here I Come
输出样例：
Come I Here World Hello*/
#include<stdio.h>
#include<string.h>
int main()
{
    char *s=malloc(500001*sizeof(char));
    gets(s);
    int n=strlen(s),flag=0;
    while(n>-1)
    {
        int cnt=0;
        while(n>0&&s[--n]!=' ')
                ++cnt;
        if(!n) n-=1;
        for(int i=1;i<=cnt;++i)
            if(s[n+i]!=' ') 
            {
            	printf("%c",s[n+i]);
            	flag=1;
            }
        while(n>0&&s[n-1]==' ')           //s[n-1]是为了和开头while(n>0&&s[--n]!=' ')配套
        --n;
        if(n>0&&flag) printf(" ");        //之所以不是n>-1是防止第一个字符就是空格
    }                                     //flag的作用是防止字符串末尾是0时程序会在开头输出一个空格
    free(s);
    return 0;
}
//本题小细节非常之多，需考虑谨慎！