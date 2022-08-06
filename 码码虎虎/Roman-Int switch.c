#include<stdio.h>
#include<stdlib.h>
// #include<string.h>
int romanToInt(char *s)
{
    int otc = 0, idx = 0;
    while (s[idx])
    {
        switch (s[idx])
        {
        case 'I':
            if (s[idx + 1] == 'V' || s[idx + 1] == 'X')
                otc -= 1;
            else
                otc += 1;
            break;
        case 'V':otc+=5;break;
        case 'X':
            if(s[idx+1]=='L'||s[idx+1]=='C')
                otc-=10;
            else
                otc+=10;
            break;
        case 'L':otc+=50;break;
        case 'C':
            if(s[idx+1]=='D'||s[idx+1]=='M')
                otc-=100;
            else
                otc+=100;
            break;
        case 'D':otc+=500;break;
        case 'M':otc+=1000;break;
        }
        ++idx;
    }
    return otc;
}
char * intToRoman(int num)
{
    int ast = 1, idx = 0;
    char *Rm = (char *)malloc(15);
    while (10 * ast <= num)
        ast *= 10;
    for (ast; ast > 0; ast /= 10)
    {
        int tmp = num / ast, carry = tmp / 5, rmn = (5 + carry * 5) - tmp;
        char o, f, t;
        switch (ast)
        {
            case 1:
                o = 'I';
                f = 'V';
                t = 'X';
                break;
            case 10:
                o = 'X';
                f = 'L';
                t = 'C';
                break;
            case 100:
                o = 'C';
                f = 'D';
                t = 'M';
                break;
            case 1000:
                o = 'M';
                break;
            default:
                break;
        }
        if (rmn < 2)
        {
            if (rmn)
                Rm[idx++] = o;
            Rm[idx++] = carry ? t : f;
        }
        else
        {
            if(carry)
                Rm[idx++] = f;
            for (int i = 0; i < 5-rmn; ++i)
                Rm[idx++] = o;
        }
        num %= ast;
    }
    Rm[idx] = '\0';
    return Rm;
}
int main()
{
    printf("Welcome to the Roman-Int Switch!\n");
    while(1)
    {
        printf("\nNow you can choose the pattern between the followings.\n\n");
        printf("\t1.Roman->Int\n\t2.Int->Roman\n\n");
        printf("Please enter your choice:");
        short n;
        flag:
        scanf("%d", &n);
        char *s;
        int num;
        switch(n)
        {
            case 1:
                s = (char*)malloc(16);
                printf("\nWARNING:You can only enter the number BETWEEN 1 and 3999!\n\n");
                printf("Now input the Roman Int:");
                scanf("%s",s);
                printf("\n>>%d", romanToInt(s));
                free(s);
                break;
            case 2:
                printf("\nWARNING:You can only enter the number BETWEEN 1 and 3999!\n\n");
                printf("Now input the Int:");
                scanf("%d", &num);
                printf("\n>>%s", intToRoman(num));
                break;
            default:
                printf("ERROR:You can only enter 1 or 2!!!\n");
                goto flag;
        }
        printf("\n\n############################################################\n");
    }
}