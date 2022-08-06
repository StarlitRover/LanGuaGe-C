#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *x, int *y);
void BubbleSort(int arr[],int n);
void SelectSort(int arr[],int n);
void InsertSort(int arr[],int n);
void QuickSort(int arr[],int head,int foot);
void MergeSort(int arr[],int temparr[],int first,int last);
void merge(int arr[],int temparr[],int first,int mid,int last);
void CountSort(int arr[],int n);
int cmp(const void*a,const void *b)
{return *(int *)a-*(int *)b;}
int main() {
    srand(time(0));
    const int n=1000;
	
    // int *s=malloc(n*sizeof(int));
    // int *cup=malloc(n*sizeof(int));
	//int i;
    /*or*/
    int s[n],cup[n],i;
	
    for(int i=0;i<n;++i)
	s[i]=cup[i]=rand();
    /*or*/
    // for(int i=0;i<n;++i)
	// s[i]=rand();
	// CountSort(s,n);
    // for(int i=0;i<50;++i)
    // swap(&s[rand()%n],&s[rand()%n]);
    // for(int i=0;i<n;++i)
    // cup[i]=s[i];
    
    printf("The number of elements in the unordered array:%d\n",n);
    /*or*/
    // printf("The number of elements in the nearly orderly array:%d\n",n);
	
    clock_t start,end;

    start=clock();
	BubbleSort(cup,n);
    end=clock();
    for(i=1;i<n;++i)
    if(cup[i]<cup[i-1])
    {printf("BubbleSort ERROR!\n");break;}
    if(i==n)
    printf("the elapsed time of BubbleSort:%d ms\n",end-start);
    
    for(int i=0;i<n;++i)
    cup[i]=s[i];
    start=clock();
	SelectSort(cup,n);
    end=clock();
    for(i=1;i<n;++i)
    if(cup[i]<cup[i-1])
    {printf("SelectSort ERROR!\n");break;}
    if(i==n)
    printf("the elapsed time of SelectSort:%d ms\n",end-start);
    
    for(int i=0;i<n;++i)
    cup[i]=s[i];
    start=clock();
	InsertSort(cup,n);
    end=clock();
    for(i=1;i<n;++i)
    if(cup[i]<cup[i-1])
    {printf("InsertSort ERROR!\n");break;}
    if(i==n)
    printf("the elapsed time of InsertSort:%d ms\n",end-start);
    
    for(int i=0;i<n;++i)
    cup[i]=s[i];
    start=clock();
	QuickSort(cup,0,n-1);
    end=clock();
    for(i=1;i<n;++i)
    if(cup[i]<cup[i-1])
    {printf("QuickSort ERROR!\n");break;}
    if(i==n)
    printf("the elapsed time of QuickSort:%d ms\n",end-start);
    
    for(int i=0;i<n;++i)
    cup[i]=s[i];
    start=clock();
	qsort(cup,n,sizeof(cup[0]),cmp);
    end=clock();
    for(i=1;i<n;++i)
    if(cup[i]<cup[i-1])
    {printf("qsort ERROR!\n");break;}
    if(i==n)
    printf("# the elapsed time of qsort:%d ms\n",end-start);
    
    int temparr[n];
    /*or*/
    // int *temparr=malloc(n*sizeof(int));
    
    for(int i=0;i<n;++i)
    temparr[i]=0;
    for(int i=0;i<n;++i)
    cup[i]=s[i];
    start=clock();
	MergeSort(cup,temparr,0,n-1);
    end=clock();
    
    // free(temparr);
    
    for(i=1;i<n;++i)
    if(cup[i]<cup[i-1])
    {printf("MergeSort ERROR!\n");break;}
    if(i==n)
    printf("the elapsed time of MergeSort:%d ms\n",end-start);
    
    for(int i=0;i<n;++i)
    cup[i]=s[i];
    start=clock();
	CountSort(cup,n);
    end=clock();
    for(i=1;i<n;++i)
    if(cup[i]<cup[i-1])
    {printf("CountSort ERROR!\n");break;}
    if(i==n)
    printf("the elapsed time of CountSort:%d ms\n",end-start);
    
    // free(s);
    // free(cup);
    
    return 0;
}
void swap(int *x, int *y)
{
    int cup;
    cup=*x;
    *x=*y;
    *y = cup;
}
void BubbleSort(int arr[],int n)
{
	for(int i = 0; i < n; ++i)
    for(int j = n-1; j > i; --j)
    if(arr[j] < arr[j-1]) swap(&arr[j], &arr[j-1]);
}
void SelectSort(int arr[],int n)
{
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			if(arr[i]>arr[j])
			swap(&arr[i],&arr[j]);
}
void InsertSort(int arr[],int n)
{
	for(int i=1;i<n;++i)
	{
		int j=i,temp=arr[i];
		while(arr[--j]>temp)
		swap(&arr[j],&arr[j+1]);
	}
}
void QuickSort(int arr[],int head,int foot)
{
	if(head>=foot) return;
	int first=head;
	int last=foot;
	srand(time(0));
	int mid=rand()%(foot-head+1)+head;
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
void MergeSort(int arr[],int temparr[],int first,int last)
{
	if (first>=last) return;
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
		if(latter>last||arr[former]<arr[latter]&&former<=mid)
			temparr[cnt++]=arr[former++];
		else
		temparr[cnt++]=arr[latter++];
	}
	for(int i=first;i<=last;++i)
		arr[i]=temparr[i];
}
void CountSort(int arr[],int n)
{
	int max=arr[0];
	for(int i=1;i<n;++i)
	if(max<arr[i]) max=arr[i];
	int cnt[max+1],num=0;
    for(int i=0;i<max+1;++i)
        cnt[i]=0;
	for(int i=0;i<n;++i)
		++cnt[arr[i]];
	for(int i=0;i<=max;++i)
		if(cnt[i])
			while(cnt[i]--)
			arr[num++]=i;
}