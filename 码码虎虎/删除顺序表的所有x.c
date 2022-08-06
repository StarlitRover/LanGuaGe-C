#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define init_size 50
typedef struct
{
    int *elem;
    int len;
    int size;
} SqList;
void deleteAll(SqList *L,int n)
{
    int step = 0;
    srand(time(NULL));
    for (int i = 0; i < L->len; ++i)
    {
        if(L->elem[i]==n)
        {
            ++step;
            continue;
        }
        if(step)
            L->elem[i - step] = L->elem[i];
    }
    L->len -= step;
}
void print(SqList *L)
{
    for (int i = 0; i < L->len; ++i)
    {
        printf("%4d", L->elem[i]);
        if((i+1)%10==0)
            printf("\n");
    }
}
int main()
{
    SqList tmp;
    tmp.elem = (int *)malloc(init_size * sizeof(int));
    tmp.len = tmp.size = init_size;
    for (int i = 0; i < tmp.len; ++i)
        tmp.elem[i] = rand()%20;
    print(&tmp);
    printf("Input the number you wanna delete:");
    int d;
    scanf("%d", &d);
    deleteAll(&tmp, d);
    print(&tmp);
    free(tmp.elem);
}