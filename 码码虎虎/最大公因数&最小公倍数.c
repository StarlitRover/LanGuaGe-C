//����һ:
#include<stdio.h>
int main ()
{
    int x,y,d,D;
    
    scanf("%d %d",&x,&y);
    d=x;
    if (x>y)
        d=y;
    while (x%d!=0||y%d!=0)     //"||"��ʾ���������е�"��"
        d--;
    printf("%d ",d);
    D=(x*y)/d;
    printf("%d",D);
    return 0;
}



//��������շת�����
#include<stdio.h>
int max(int x,int y)
{
    int max=x;
    if (y>x) max=y;
    return max;
}
int min(int x,int y)
{
    int min=x;
    if (y<x) min=y;
    return min;
}
int main ()
{
    int x,y,s,q,d,D;
    
    scanf("%d %d",&x,&y);
    q=max(x,y)%min(x,y);
    s=min(x,y);
    while(q>0){
        d=q;q=s%q;s=d;
    }
    printf("%d ",s);
    D=(x*y)/s;
    printf("%d",D);
    return 0;
}
