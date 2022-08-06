#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#define STACK_INIT_SIZE 100
#define BLOCK_SIZE 50
typedef struct stack
{
    int size; //Õ»µÄ´æ´¢¿Õ¼ä
    int top;  //Õ»¶¥ÔªËØÐòºÅ
    int *data;//Êý¾Ý´æ´¢
} stack;
void InitStack(stack *stk);        //³õÊ¼»¯Õ»
void PushStack(stack *stk, int n); //Ñ¹Õ»
int PopStack(stack *stk);          //³öÕ»
void InflateStack(stack *stk);     //À©³äÕ»
void newQSort(int arr[], int size, stack *stk);
void printArray(int array[], int size);
void swap(int *x, int *y);
int main()
{
    int size, flag;
    stack stk;
    InitStack(&stk);
    printf("Enter the size of array:\n");
    scanf("%d", &size);
    int *array = (int *)malloc(size * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; ++i)
        array[i] = rand();
    printf("Enter 0 to make the Array invisible,or enter any other numbers.\n");
    scanf("%d", &flag);
    if (flag)
    {
        printf("the initial Array:\n");
        printArray(array, size);
    }
    clock_t start = clock();
    newQSort(array, size, &stk);
    clock_t end = clock();
    if (flag)
    {
        printf("the random Array in order:\n");
        printArray(array, size);
    }
    printf("Elapsed time:%f s\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(stk.data);
    free(array);
}
void InitStack(stack *stk)
{
    assert(stk);
    stk->top = 0;
    stk->size = STACK_INIT_SIZE;
    stk->data = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
}
void PushStack(stack *stk, int n)
{
    if (stk->size == stk->top)
        InflateStack(stk);
    stk->data[stk->top++] = n;
}
int PopStack(stack *stk)
{
    assert(stk);
    if (stk->size - stk->top > 100)
        stk->data = (int *)realloc(stk->data, (stk->size -= 2 * BLOCK_SIZE) * sizeof(int));
    return stk->data[(stk->top--) - 1];
}
void InflateStack(stack *stk)
{
    stk->data = (int *)realloc(stk->data, (stk->size += BLOCK_SIZE) * sizeof(int));
    assert(stk->data);
}
void newQSort(int arr[], int size, stack *stk)
{
    int head, foot, first, last, mid, pivot;
    PushStack(stk, size - 1);
    PushStack(stk, 0);
    while (stk->top)
    {
        first = head = PopStack(stk);
        last = foot = PopStack(stk);
        if (head >= foot)
            continue;
        mid = rand() % (foot - head + 1) + head;
        pivot = arr[mid];
        while (mid < last && arr[last] >= pivot)
            --last;
        swap(&arr[mid], &arr[last]);
        while (first < last)
        {
            while (first < last && arr[first] <= pivot)
                ++first;
            swap(&arr[first], &arr[last]);
            while (first < last && arr[last] >= pivot)
                --last;
            swap(&arr[first], &arr[last]);
        }
        PushStack(stk, last - 1);
        PushStack(stk, head);
        PushStack(stk, foot);
        PushStack(stk, first + 1);
    }
}
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}
void swap(int *x, int *y)
{
    int cup = *x;
    *x = *y;
    *y = cup;
}