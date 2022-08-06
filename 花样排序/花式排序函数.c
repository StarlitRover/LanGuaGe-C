//冒泡排序:与选择排序类似，无序子数组中的最大元素从中逐一冒出
void BubbleSort(int arr[],int n)
{
	for(int i = 0; i < n; ++i)
    for(int j = n-1; j > i; --j)
    if(arr[j] > arr[j-1]) swap(&arr[j], &arr[j-1]);
}
/*该冒泡排序是将数组从大到小排的*/

//选择排序:有序范围从左至右逐渐扩大,每次选择右侧无序数组中最小的元素放入左侧有序子数组的末尾
void SelectSort(int arr[],int n)
{
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			if(arr[i]>arr[j])
			swap(&arr[i],&arr[j]);
}

//插入排序:有序范围从左至右逐渐扩大,每个数组元素插入左边有序子数组中的(大小)合理位置
void InsertSort(int arr[],int n)
{
	for(int i=1;i<n;++i)
		for(int j=i;j>0;--j)
			if(arr[j-1]>arr[j])
			swap(&arr[j],&arr[j+1]);
}

//快速排序:第一次尝试递归调用
void QuickSort(int arr[],int head,int foot)
{
	if(head>=foot) return;
	int first=head;
	int last=foot;
	int pivot=arr[first];
	while(first<last)                         //寻找pivot(基准数)的位置
	{
		while(first<last&&arr[last]>=pivot)
			--last;                           //寻找比pivot小的最大位置(项数)
		swap(&arr[first],&arr[last]);
		while(first<last&&arr[first]<=pivot)
			++first;                          //寻找比pivot大的最小位置(项数)
		swap(&arr[first],&arr[last]);
	}                                         //经过有限次操作即可用pivot将数组分为(*=<pivot=<*)左右两块
	QuickSort(arr,head,last-1);
	QuickSort(arr,first+1,foot);
}
//改进版:
void QuickSort(int arr[],int head,int foot)
{
	if(head>=foot) return;
	int first=head;
	int last=foot;
	srand(time(0));
	int mid=rand()%(foot-head+1)+head;        //这里不取第一个数组元素作为pivot，为的就是防止较大有序数组使用快排时发生栈溢出
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

//归并排序(无需swap函数):化大为小,分而治之
void MergeSort(int arr[],int temparr[],int first,int last)
{
	if (first>=last) return;                                      //不能first>=last-1,不然当first=last-1时(即两个元素的子数组)不会进行排序
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
		if(latter>last||arr[former]<arr[latter]&&former<=mid)     //"&&former<=mid"漏下这个条件所引发的后果使我仔细观察这段代码足有一个小时之久
			temparr[cnt++]=arr[former++];                         //如果没有这个条件将会导致first越过mid而将后一段(mid+1~last)数列中的元素当作
		else                                                      //(continued)自己这段(first~mid)的元素  
		temparr[cnt++]=arr[latter++];
	}
	for(int i=first;i<=last;++i)
		arr[i]=temparr[i];
}

//计数排序:分别计数后按出现次数从小到大逐一输出
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

//swap函数:
void swap(int *x, int *y)
{
    int cup;
    cup=*x;
    *x=*y;
    *y = cup;
}
/*参考网站:https://blog.csdn.net/weixin_41190227/article/details/86600821*/

/*后记
不久过后码者在PTA上遇到一道排序题，于是码者将自己编写的几种排序(包括头文件里的qsort,但不包含冒泡、选择和插入.....自知必死无疑)，
出人意料的是最终竟然只有qsort和MergeSort通过了测评，具体题目如下：

7-82 排序 (30分)
#排序

本题不限定排序算法，所给的数据集有种情况：

小规模（n<1000）无序数据；
小规模（n<1000）递增数据；
小规模（n<1000）递减数据；
大规模（10000<n<1000000）无序数据；
大规模（10000<n<1000000）递增数据；
大规模（10000<n<1000000）递减数据。
数据均为32位int的全部范围。

##输入

你的程序首先会读到一个正整数n，1<=n<=1000000。然后是n个整数，每个数字一行。

##输出

输出排序后的结果，每个数字一行。

失败排序方式原因如下:
1.CountSort 栈溢出[元素数值太大(32位int)]
2.QuickSort(自编) 运行超时

Conclusion:
1.再次说明计数排序并非全能
2.自编的快速排序有待改进
3.归并排序发挥稳定*/

