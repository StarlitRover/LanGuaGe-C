/*7-40 �����ǲ���̫���� 
��˵һ���˵ı�׼����Ӧ��������ߣ���λ�����ף���ȥ100���ٳ���0.9���õ��Ĺ�������
��ʵ�������׼���������10%���ڶ���������ģ��� | ��ʵ���� ? ��׼���� | < ��׼���ء�10%����
��֪�н��ǹ�����������ָ���һȺ�˵���ߺ�ʵ�����أ�������������Ƿ�̫�ֻ�̫���ˡ�

�����ʽ��
�����һ�и���һ��������N���� 20�������N�У�ÿ�и��������������ֱ���һ���˵����H��120 < H < 200����λ�����ף�����ʵ����W��50 < W �� 300����λ���н������Կո�ָ���

�����ʽ��
Ϊÿ�������һ�н��ۣ������������ģ����You are wan mei!�����̫���ˣ����You are tai pang le!���������You are tai shou le!��

����������
3
169 136
150 81
178 155
���������
You are wan mei!
You are tai shou le!
You are tai pang le!*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n,sign,k;                                  //sign��������ζ��n����̫��!
    double w,W,h;
    
    scanf("%d",&n);
    sign=0;
    k=1;
    for(int i=1;i<=n;++i)
    {
        scanf("\n%lf %lf",&h,&w);
        W=(h-100)*0.9;
        if(fabs(w/2-W)>=0.1*W) 
            (w/2<W)?sign+=k:(sign+=2*k);
        else sign+=3*k;                       
        k*=10;
    }
    while (sign)
    {
        switch(sign%10)
        {
            case 1:printf("You are tai shou le!\n");break;
            case 2:printf("You are tai pang le!\n");break;
            case 3:printf("You are wan mei!\n");break;
        }
        sign/=10;
    }
    return 0;
}
//���Ⲣ���ѣ�������������ʵ����һ������һ������ķ�ʽ�����������͵ķ�Χ���������޷�ʵ��(n<=20)������.