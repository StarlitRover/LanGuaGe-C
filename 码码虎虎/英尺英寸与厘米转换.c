/*�����֪Ӣ�Ƴ��ȵ�Ӣ��foot��Ӣ��inch��ֵ��
��ô��Ӧ������(foot+inch/12)��0.3048�����ڣ�
����û������������������ô��ӦӢ�Ƴ��ȵ�Ӣ
�ߺ�Ӣ���Ƕ����أ�������1Ӣ�ߵ���12Ӣ�硣*/

#include<stdio.h>
int main()
{
    int foot,inch;
    double meter,cm;
    
    scanf("%lf",&cm);
    meter=0.01*cm;
    inch=meter/0.3048*12;
    foot=inch/12;
    inch%=12;
    printf("%d %d",foot,inch);
    return 0;
}
