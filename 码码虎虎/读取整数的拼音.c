#include<stdio.h>
int main()
{
	int x,q,s,f;
	q=1;
	
	scanf("%d",&x);
	if(x<0){
	printf("fu ");
	x=-x;
	}
	f=x;
	while(f>9){                            //����������λ������q
	q*=10;
	f/=10;	
	}
	while(q>=1){                           //ע��������ѡȡ��q������x����Ϊһ������ĩβ�ж��0�ͻ��������
		s=x/q;
		switch(s){
			case 0:printf("ling");break;
			case 1:printf("yi");break;
			case 2:printf("er");break;
			case 3:printf("san");break;
			case 4:printf("si");break;
			case 5:printf("wu");break;
			case 6:printf("liu");break;
			case 7:printf("qi");break;
			case 8:printf("ba");break;
			case 9:printf("jiu");break;
		}
		if(q>=10)printf(" ");              //ͬ��
		x%=q;
		q/=10;
	}
	return 0;
}
