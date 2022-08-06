#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void rightguess(int i);
int main()
{
    srand(time(0));
    printf("Let's do some preparation first.\n\n");
    int s, n, range;
    printf("Enter the maximum of the secret number(>=1):\n");
    scanf("%d", &range);
    int x = rand() % range;

    printf("Enter maximum input times(>=3!):\n");
    scanf("%d", &n);
    printf("I already have an integer x (0 =< x < %d)!\nPlease enter numbers:\n", range);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s);
        if (i < n)
        {
            if (s > x)
                printf("Too big\n");
            else if (s < x && s >= 0)
                printf("Too small\n");
            else if (s < 0)
            {
                printf("Game Over");
                break;
            }
            else
            {
                rightguess(i);
                break;
            }
        }
        else
        {
            if (x == s)
                rightguess(i);
            else
                printf("Game Over");
        }
    }
    system("pause");
    return 0;
}
void rightguess(int i)
{
    if (i == 1)
        printf("Bingo!");
    else if (i <= 3)
        printf("Lucky You!");
    else
        printf("Good Guess!");
}
