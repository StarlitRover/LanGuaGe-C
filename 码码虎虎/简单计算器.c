#include<stdio.h>
int main ()
{
	int first,w,outcome,nsign;
	char sign;
	
	scanf("%d%c",&first,&sign);
	outcome=first;
	if(sign!='=') do{
		nsign=sign;
		switch(nsign){                   //�����״�ʹ��switch���
			case 43:scanf("%d",&w);
			outcome+=w;break;
			case 45:scanf("%d",&w);
			outcome-=w;break;
			case 42:scanf("%d",&w);
			outcome*=w;break;
			case 47:scanf("%d",&w);
			if(w==0){nsign=0;break;}
			outcome/=w;break;
			default:nsign=0;break;        //ע��default�Ĵ���
		}
		if(nsign==0){printf("ERROR");break;}
		scanf("%c",&sign);
	}while(sign!='=');
	if (sign=='=') printf("%d",outcome);
	return 0;
}                                         //��д����������Ҫע�����ļ����!
