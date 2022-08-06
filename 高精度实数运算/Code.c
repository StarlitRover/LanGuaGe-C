#include <stdio.h>
#include <stdlib.h>
#define sgn(x) (2 * (x->n > 0) - 1)
#define max(x, y) ((x > y) ? x : y)
#define dgt(x) (abs(x->n) + x->pre->n)
typedef struct single
{
    struct single *pre;
    int n;
    struct single *next;
} sgl;
sgl *scanBigNumber();
void zeroBigNumber(sgl *heada, sgl *headb);
void nmlBigNumber(sgl *heada);
void printBigNumber(sgl *head);
int cmpBigNumber(sgl *heada, sgl *headb);
int jdgBigNumber(sgl *heada, sgl *headb);
sgl *addBigNumber(sgl *heada, sgl *headb);
sgl *sbtBigNumber(sgl *heada, sgl *headb);
sgl *mtpBigNumber(sgl *heada, sgl *headb);
void freeBigNumber(sgl *head);
void printERROR(char s);
int main()
{
    printf("Enter TWO real numbers A and B:\n");
    sgl *heada, *headb, *headc;
    heada = scanBigNumber();
    headb = scanBigNumber();
    nmlBigNumber(heada);
    nmlBigNumber(headb);
    switch (cmpBigNumber(heada, headb))
    {
    case 1:
        printf("A>B");
        break;
    case 0:
        printf("A=B");
        break;
    case -1:
        printf("A<B");
        break;
    }
    printf("\n");

    headc = addBigNumber(heada, headb);
    printf("A+B=");
    printBigNumber(headc);
    freeBigNumber(headc);

    headc = sbtBigNumber(heada, headb);
    printf("A-B=");
    printBigNumber(headc);
    freeBigNumber(headc);

    headc = mtpBigNumber(heada, headb);
    printf("A*B=");
    printBigNumber(headc);
    freeBigNumber(headc);

    freeBigNumber(heada);
    freeBigNumber(headb);
}
sgl *scanBigNumber()
{
    char s;
    int sgn, rcnt = 0, lcnt = 1;
    sgl *phead, *tmp, *tail;
    scanf("%c", &s);
    if (s == '-')
    {
        sgn = -1;
        tail = phead = (sgl *)malloc(sizeof(sgl));
        phead->n = getchar() - '0';
        phead->next = phead->pre = NULL;
    }
    else
    {
        printERROR(s);
        sgn = 1;
        tail = phead = (sgl *)malloc(sizeof(sgl));
        phead->n = s - '0';
        phead->next = phead->pre = NULL;
    }
    while ((s = getchar()) != '\n')
    {
        if (s != '.')
        {
            printERROR(s);
            tmp = (sgl *)malloc(sizeof(sgl));
            tmp->pre = phead;
            tmp->n = s - '0';
            tmp->next = NULL;
            phead->next = tmp;
            phead = tmp;
            ++lcnt;
        }
        else
        {
            while ((s = getchar()) != '\n')
            {
                printERROR(s);
                tmp = (sgl *)malloc(sizeof(sgl));
                tmp->pre = phead;
                tmp->n = s - '0';
                tmp->next = NULL;
                phead->next = tmp;
                phead = tmp;
                ++rcnt;
            }
            break;
        }
    }
    tmp = (sgl *)malloc(sizeof(sgl));
    tmp->pre = phead;
    tmp->n = rcnt;
    tmp->next = NULL;
    phead = (sgl *)malloc(sizeof(sgl));
    phead->pre = tmp;
    phead->n = sgn * lcnt;
    phead->next = tail;
    return phead;
}
void zeroBigNumber(sgl *heada, sgl *headb)
{
    if (abs(heada->n) == abs(headb->n) && heada->pre->n == headb->pre->n)
        return;
    sgl *zerofront = (abs(heada->n) > abs(headb->n)) ? headb : heada,
        *zerorear = (heada->pre->n > headb->pre->n) ? headb->pre : heada->pre,
        *tmp = zerofront->next;
    int fdelta = abs(abs(heada->n) - abs(headb->n)),
        rdelta = abs((heada->pre->n - headb->pre->n));
    zerofront->n = sgn(zerofront) * max(abs(heada->n), abs(headb->n));
    zerorear->n = max(heada->pre->n, headb->pre->n);
    sgl *target = zerofront;
    zerofront = zerofront->next;
    while (fdelta--)
    {
        tmp = (sgl *)malloc(sizeof(sgl));
        tmp->n = 0;
        tmp->next = zerofront;
        zerofront = zerofront->pre = tmp;
    }
    tmp->pre = NULL;
    target->next = tmp;
    tmp = zerorear->pre;
    target = zerorear;
    zerorear = zerorear->pre;
    while (rdelta--)
    {
        tmp = (sgl *)malloc(sizeof(sgl));
        tmp->n = 0;
        tmp->pre = zerorear;
        zerorear = zerorear->next = tmp;
    }
    tmp->next = NULL;
    target->pre = tmp;
}
void nmlBigNumber(sgl *head)
{
    if (head->next->n != 0 && head->pre->pre->n != 0)
        return;
    int sgn = sgn(head);
    sgl *tmp = head->next, *cup;
    int *lcnt = &head->n, *rcnt = &head->pre->n;
    head->n = abs(head->n);
    while (tmp->n == 0 && *lcnt > 1)
    {
        --*lcnt;
        cup = tmp->next;
        free(tmp);
        tmp = cup;
    }
    tmp->pre = NULL;
    head->next = tmp;
    head->n *= sgn;
    tmp = head->pre->pre;
    while (tmp->n == 0 && *rcnt > 0)
    {
        --*rcnt;
        cup = tmp->pre;
        free(tmp);
        tmp = cup;
    }
    tmp->next = NULL;
    head->pre->pre = tmp;
    if (!*rcnt && head->next->n == 0)
        head->n = abs(head->n);
}
void printBigNumber(sgl *head)
{
    // int lcnt = head->n,
    //     rcnt = head->pre->n,
    //     judge = rcnt;
    // head = head->pre->pre;
    // if (lcnt < 0)
    // {
    //     printf("-");
    //     lcnt = abs(lcnt);
    // }
    // int space = lcnt + rcnt - (judge == 0);
    // for (int i = 0; i < space; ++i)
    //     printf(" ");
    // while (rcnt--)
    // {
    //     printf("%d\b\b", head->n);
    //     head = head->pre;
    // }
    // if (judge)
    //     printf(".\b\b");
    // while (lcnt--)
    // {
    //     printf("%d\b\b", head->n);
    //     head = head->pre;
    // }
    // printf("\n");
    /*or*/
    int lcnt = head->n,
        rcnt = head->pre->n;
    if (lcnt < 0)
    {
        printf("-");
        lcnt *= -1;
    }
    head = head->next;
    while (lcnt--)
    {
        printf("%d", head->n);
        head = head->next;
    }
    if (rcnt)
        printf(".");
    while (rcnt--)
    {
        printf("%d", head->n);
        head = head->next;
    }
    printf("\n");
}
int cmpBigNumber(sgl *heada, sgl *headb)
{
    int judge = 0;
    if (heada->n > headb->n)
        judge = 1;
    else if (heada->n < headb->n)
        judge = -1;
    else
    {
        int sgn = sgn(heada);
        heada = heada->next;
        headb = headb->next;
        while (heada && headb)
        {
            if (heada->n > headb->n)
            {
                judge = 1;
                break;
            }
            else if (heada->n < headb->n)
            {
                judge = -1;
                break;
            }
            else
            {
                heada = heada->next;
                headb = headb->next;
            }
        }
        if (heada && !headb)
            judge = 1;
        else if (!heada && headb)
            judge = -1;
        judge *= sgn;
    }
    return judge;
}
int jdgBigNumber(sgl *heada, sgl *headb)
{
    int judge;
    sgl a = *heada, b = *headb;
    a.n = abs(a.n);
    b.n = abs(b.n);
    if (cmpBigNumber(&a, &b) == 1)
        judge = 0;
    else
        judge = 1;
    return judge;
}
sgl *addBigNumber(sgl *heada, sgl *headb)
{
    int sgn = jdgBigNumber(heada, headb);
    zeroBigNumber(heada, headb);
    sgl *headc = (sgl *)malloc(sizeof(sgl)),
        *former = (sgl *)malloc(sizeof(sgl)),
        *starta, *startb, *tmp;
    headc->n = abs(heada->n);
    former->n = heada->pre->n;
    former->next = NULL;
    headc->pre = former;
    int add = 0, carry = 0;
    if (sgn(heada) * sgn(headb) > 0)
    {
        starta = heada->pre->pre;
        startb = headb->pre->pre;
        sgn = sgn(heada);
        while (starta)
        {
            add = starta->n + startb->n + carry;
            carry = add / 10;
            add = add % 10;
            tmp = (sgl *)malloc(sizeof(sgl));
            tmp->n = add;
            tmp->next = former;
            former = former->pre = tmp;
            starta = starta->pre;
            startb = startb->pre;
        }
        if (carry)
        {
            tmp = (sgl *)malloc(sizeof(sgl));
            tmp->n = carry;
            tmp->next = former;
            former->pre = tmp;
            headc->n += 1;
        }
        headc->n *= sgn;
    }
    else
    {
        starta = sgn ? headb : heada;
        startb = sgn ? heada : headb;
        headc->n *= sgn(starta);
        starta = starta->pre->pre;
        startb = startb->pre->pre;
        while (starta)
        {
            add = starta->n - startb->n - carry;
            if (add < 0)
            {
                carry = 1;
                add += 10;
            }
            else
                carry = 0;
            tmp = (sgl *)malloc(sizeof(sgl));
            tmp->n = add;
            tmp->next = former;
            former = former->pre = tmp;
            starta = starta->pre;
            startb = startb->pre;
        }
    }
    tmp->pre = NULL;
    headc->next = tmp;
    headc->pre->pre->next = NULL;
    nmlBigNumber(heada);
    nmlBigNumber(headb);
    nmlBigNumber(headc);
    return headc;
}
sgl *sbtBigNumber(sgl *heada, sgl *headb)
{
    sgl sbt = *headb;
    sbt.n *= -1;
    return addBigNumber(heada, &sbt);
}
sgl *mtpBigNumber(sgl *heada, sgl *headb)
{
    sgl *headc = (sgl *)malloc(sizeof(sgl)),
        *former = (sgl *)malloc(sizeof(sgl)),
        *tmp;
    former->n = heada->pre->n + headb->pre->n;
    former->next = NULL;
    int digit = dgt(heada) + dgt(headb);
    headc->n = (digit - former->n) * sgn(heada) * sgn(headb);
    headc->pre = former;
    for (int i = 0; i < digit; ++i)
    {
        tmp = (sgl *)malloc(sizeof(sgl));
        tmp->n = 0;
        tmp->next = former;
        former = former->pre = tmp;
    }
    tmp->pre = NULL;
    headc->pre->pre->next = NULL;
    headc->next = tmp;
    sgl *starta = heada->pre->pre,
        *startb = headb->pre->pre,
        *start = headc->pre->pre;
    tmp = headc->pre->pre;
    int mtp = 0, carry = 0;
    while (starta)
    {
        startb = headb->pre->pre;
        while (startb)
        {
            mtp = startb->n * starta->n + carry;
            tmp->n += mtp;
            carry = tmp->n / 10;
            tmp->n = tmp->n % 10;
            tmp = tmp->pre;
            startb = startb->pre;
        }
        if (carry)
        {
            tmp->n += carry;
            carry = 0;
        }
        starta = starta->pre;
        tmp = start = start->pre;
    }
    nmlBigNumber(headc);
    return headc;
}
void freeBigNumber(sgl *head)
{
    sgl *tmp = head;
    while (tmp)
    {
        tmp = head->pre;
        free(head);
        head = tmp;
    }
}
void printERROR(char s)
{
    if (s < '0' || s > '9')
    {
        printf("ERROR!!!\nILLEGAL input!");
        system("pause");
        exit(0);
    }
}