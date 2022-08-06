#include<stdio.h>
int main()
{
    int x,y,z;
    
    scanf("%d %d %d",&x,&y,&z);
    switch((x==y)+(y!=z)){           //这里涉及了神奇的逻辑判断手段(根据不等式的运算结果)
        case 2:printf("C");break;
        case 1:printf("B");break;
        case 0:printf("A");break;
    }
    return 0;
}