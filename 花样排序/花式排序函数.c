//ð������:��ѡ���������ƣ������������е����Ԫ�ش�����һð��
void BubbleSort(int arr[],int n)
{
	for(int i = 0; i < n; ++i)
    for(int j = n-1; j > i; --j)
    if(arr[j] > arr[j-1]) swap(&arr[j], &arr[j-1]);
}
/*��ð�������ǽ�����Ӵ�С�ŵ�*/

//ѡ������:����Χ��������������,ÿ��ѡ���Ҳ�������������С��Ԫ�ط�����������������ĩβ
void SelectSort(int arr[],int n)
{
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			if(arr[i]>arr[j])
			swap(&arr[i],&arr[j]);
}

//��������:����Χ��������������,ÿ������Ԫ�ز�����������������е�(��С)����λ��
void InsertSort(int arr[],int n)
{
	for(int i=1;i<n;++i)
		for(int j=i;j>0;--j)
			if(arr[j-1]>arr[j])
			swap(&arr[j],&arr[j+1]);
}

//��������:��һ�γ��Եݹ����
void QuickSort(int arr[],int head,int foot)
{
	if(head>=foot) return;
	int first=head;
	int last=foot;
	int pivot=arr[first];
	while(first<last)                         //Ѱ��pivot(��׼��)��λ��
	{
		while(first<last&&arr[last]>=pivot)
			--last;                           //Ѱ�ұ�pivotС�����λ��(����)
		swap(&arr[first],&arr[last]);
		while(first<last&&arr[first]<=pivot)
			++first;                          //Ѱ�ұ�pivot�����Сλ��(����)
		swap(&arr[first],&arr[last]);
	}                                         //�������޴β���������pivot�������Ϊ(*=<pivot=<*)��������
	QuickSort(arr,head,last-1);
	QuickSort(arr,first+1,foot);
}
//�Ľ���:
void QuickSort(int arr[],int head,int foot)
{
	if(head>=foot) return;
	int first=head;
	int last=foot;
	srand(time(0));
	int mid=rand()%(foot-head+1)+head;        //���ﲻȡ��һ������Ԫ����Ϊpivot��Ϊ�ľ��Ƿ�ֹ�ϴ���������ʹ�ÿ���ʱ����ջ���
	int pivot=arr[mid];
	while(mid<last&&arr[last]>=pivot)
		--last;
	swap(&arr[mid],&arr[last]);
	while(first<last)
	{
		while(first<last&&arr[first]<=pivot)
			++first;
		swap(&arr[first],&arr[last]);
		while(first<last&&arr[last]>=pivot)
			--last;
		swap(&arr[first],&arr[last]);
	}
	QuickSort(arr,head,last-1);
	QuickSort(arr,first+1,foot);
}

//�鲢����(����swap����):����ΪС,�ֶ���֮
void MergeSort(int arr[],int temparr[],int first,int last)
{
	if (first>=last) return;                                      //����first>=last-1,��Ȼ��first=last-1ʱ(������Ԫ�ص�������)�����������
	int mid=(first+last)/2;
	MergeSort(arr,temparr,first,mid);
	MergeSort(arr,temparr,mid+1,last);
	merge(arr,temparr,first,mid,last);
}
void merge(int arr[],int temparr[],int first,int mid,int last)
{
	int former=first,latter=mid+1,cnt=first;
	while(former<=mid||latter<=last)
	{
		if(latter>last||arr[former]<arr[latter]&&former<=mid)     //"&&former<=mid"©����������������ĺ��ʹ����ϸ�۲���δ�������һ��Сʱ֮��
			temparr[cnt++]=arr[former++];                         //���û������������ᵼ��firstԽ��mid������һ��(mid+1~last)�����е�Ԫ�ص���
		else                                                      //(continued)�Լ����(first~mid)��Ԫ��  
		temparr[cnt++]=arr[latter++];
	}
	for(int i=first;i<=last;++i)
		arr[i]=temparr[i];
}

//��������:�ֱ�����󰴳��ִ�����С������һ���
void CountSort(int arr[],int n)
{
	int max=arr[0];
	for(int i=1;i<n;++i)
	if(max<arr[i]) max=arr[i];
	int cnt[max+1]={0},num=0;
	for(int i=0;i<n;++i)
		++cnt[arr[i]];
	for(int i=0;i<=max;++i)
		if(cnt[i])
			while(cnt[i]--)
			arr[num++]=i;
}

//swap����:
void swap(int *x, int *y)
{
    int cup;
    cup=*x;
    *x=*y;
    *y = cup;
}
/*�ο���վ:https://blog.csdn.net/weixin_41190227/article/details/86600821*/

/*���
���ù���������PTA������һ�������⣬�������߽��Լ���д�ļ�������(����ͷ�ļ����qsort,��������ð�ݡ�ѡ��Ͳ���.....��֪��������)��
�������ϵ������վ�Ȼֻ��qsort��MergeSortͨ���˲�����������Ŀ���£�

7-82 ���� (30��)
#����

���ⲻ�޶������㷨�����������ݼ����������

С��ģ��n<1000���������ݣ�
С��ģ��n<1000���������ݣ�
С��ģ��n<1000���ݼ����ݣ�
���ģ��10000<n<1000000���������ݣ�
���ģ��10000<n<1000000���������ݣ�
���ģ��10000<n<1000000���ݼ����ݡ�
���ݾ�Ϊ32λint��ȫ����Χ��

##����

��ĳ������Ȼ����һ��������n��1<=n<=1000000��Ȼ����n��������ÿ������һ�С�

##���

��������Ľ����ÿ������һ�С�

ʧ������ʽԭ������:
1.CountSort ջ���[Ԫ����ֵ̫��(32λint)]
2.QuickSort(�Ա�) ���г�ʱ

Conclusion:
1.�ٴ�˵���������򲢷�ȫ��
2.�Ա�Ŀ��������д��Ľ�
3.�鲢���򷢻��ȶ�*/

