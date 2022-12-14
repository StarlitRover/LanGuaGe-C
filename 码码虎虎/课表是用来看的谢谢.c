/*7-2 哪几周有课 (20分)
小明看到课表上某课程的上课周次是这样标示的：1, 8,12-17,3-6 。请你编写程序，将从输入设备上输入的如前述类似的周次表示字符串，转换成标准的周次表示。

输入格式:
一个数字表示某一周，两个数字中间以-号分隔的表示某周次区间，a-b表示 区间[a,b]，程序确保a<b，但不能够确保周次间是升序排列的。所有的周次在【1，20】内。 输入有若干行，每行一个课程的上课周次。

输出格式:
从小到大的顺序输出有课程的周次，周与周间以逗号分隔，最后没有逗号。

输入样例:
3-5,8,13-15,17,10-12
13-18,5-9
3-13 , 13 - 17
输出样例:
3,4,5,8,10,11,12,13,14,15,17
5,6,7,8,9,13,14,15,16,17,18
3,4,5,6,7,8,9,10,11,12,13,14,15,16,17*/
#include <stdio.h>
int main()
{
    char s[100], c[100];       //字符串c用于存放剔除空格后的s
    while (gets(s))            //gets()函数的返回值即是读入的字符串，当未读到任何字符时返回NULL
    {
        int sign[20] = {0};
        int i = -1, index = 0;
        while (s[++i])         //剔除该死的空格
            if (s[i] == '-' || s[i] == ',' || s[i] >= '0' && s[i] <= '9')
                c[index++] = s[i];
        c[index++] = ',';     //字符串c的末尾添入了另外的','是为了保持与前面的一致性(将','作为一段结束的标志)方便后续操作
        c[index] = 0;
        int k = -1, flag = 0, mark = 0, x, y;//x是用来记录前面最近的那个数,y是专门给'-'用的
        while (c[++k])
        {
            if (c[k] >= '0' && c[k] <= '9')
            {
                if (mark)                   //mark:标记前面一个字符是否是数字
                    x = (c[k - 1] - '0') * 10 + c[k] - '0';
                else
                {
                    mark = 1;
                    x = c[k] - '0';
                }
            }
            else if (c[k] == '-')           //此时y用来存放'-'前面的那个数
            {
                y = x;
                flag = 1;                   //flag=1表示这一段是一段范围,flag=0代表这一段仅有一个数
                mark = 0;
            }
            else if (c[k] == ',')           //出现','代表一段的结束
            {
                if (!flag)
                    sign[x - 1] = 1;
                else
                    for (int j = y - 1; j < x; ++j)
                        sign[j] = 1;
                flag = mark = 0;
            }
        }
        int notice = 0;
        for (int j = 0; j < 20; ++j)
        {
            if (sign[j])
            {
                if (notice)
                    printf(",");
                printf("%d", j + 1);
                notice = 1;
            }
        }
        printf("\n");
    }
    return 0;
}
/*本题有点意(e)思(xin)哈
1.输入样例中的"3-13 , 13 - 17"说明了字符之间可能存在莫名其妙的空格
2.'-'的处理是本题的一个关键亦是难点