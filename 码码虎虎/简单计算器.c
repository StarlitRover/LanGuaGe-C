#include<stdio.h>
int main ()
{
	int first,w,outcome,nsign;
	char sign;
	
	scanf("%d%c",&first,&sign);
	outcome=first;
	if(sign!='=') do{
		nsign=sign;
		switch(nsign){                   //这里首次使用switch语句
			case 43:scanf("%d",&w);
			outcome+=w;break;
			case 45:scanf("%d",&w);
			outcome-=w;break;
			case 42:scanf("%d",&w);
			outcome*=w;break;
			case 47:scanf("%d",&w);
			if(w==0){nsign=0;break;}
			outcome/=w;break;
			default:nsign=0;break;        //注意default的存在
		}
		if(nsign==0){printf("ERROR");break;}
		scanf("%c",&sign);
	}while(sign!='=');
	if (sign=='=') printf("%d",outcome);
	return 0;
}                                         //编写程序依旧需要注意代码的简洁性!
