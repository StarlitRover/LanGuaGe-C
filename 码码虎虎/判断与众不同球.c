#include<stdio.h>
int main()
{
    int x,y,z;
    
    scanf("%d %d %d",&x,&y,&z);
    switch((x==y)+(y!=z)){           //�����漰��������߼��ж��ֶ�(���ݲ���ʽ��������)
        case 2:printf("C");break;
        case 1:printf("B");break;
        case 0:printf("A");break;
    }
    return 0;
}