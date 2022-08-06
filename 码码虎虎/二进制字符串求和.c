/*�������ַ������
���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����
����Ϊ �ǿ� �ַ�����ֻ�������� 1 �� 0�� 

ʾ�� 1:
����: a = "11", b = "1"
���: "100"

ʾ�� 2:
����: a = "1010", b = "1011"
���: "10101"
 
��ʾ��
ÿ���ַ��������ַ� '0' �� '1' ��ɡ�
1 <= a.length, b.length <= 10^4
�ַ���������� "0" ���Ͷ�����ǰ���㡣*/
char * addBinary(char * a, char * b)
{
    int idxa=strlen(a)-1,idxb=strlen(b)-1,idxc=(idxa>=idxb)*idxa+(idxa<idxb)*idxb,i;
    char *add=(char*)malloc(idxc+3);//+3�ܹؼ���������\0����
    add[idxc+1]='\0';
    int carry=0,sum;
    char *rem;
    for(i=idxc;i>=0;--i)
    {
        sum=a[idxa]+b[idxb]+carry-'0';
        if(sum>'1')
        {
            add[i]=sum-2;
            carry=1;
        }
        else
        {
            add[i]=sum;
            carry=0;    
        }
       --idxa;
       --idxb;
       if(idxa<0) 
       {
           rem=b;
           break;
       }
       else if(idxb<0)
       {
           rem=a;
           break;
       }
    }
    for(i-=1;i>=0;--i)
    {
        add[i]=rem[i]+carry;
        if(add[i]>'1')
            add[i]-=2;
        else 
            carry=0;
    }
    if(carry)
    {
        for(i=idxc+1;i>=0;--i)
            add[i+1]=add[i];
        add[0]='1';
    }
    return add;
}
/*Accepted
294/294 cases passed (0 ms)
Your runtime beats 100 % of c submissions
Your memory usage beats 48.12 % of c submissions (5.7 MB)