#include<iostream>
using namespace std;
void max_heap(int *a,int start,int end)
{
	int parent=start;
	int son=parent*2+1;
	while(son<=end)
	{
		if((son+1)<=end&&a[son]<a[son+1])
		{
			son++;
		}
		if(a[parent]>a[son])
		{
			return;
		}
		else
		{
			int tmp=a[son];
			a[son]=a[parent];
			a[parent]=tmp;
			parent=son;
			son=parent*2+1;
		}
	}
}
void heap_sort(int *a,int n)
{
	for(int i=(n-1)/2;i>=0;i--)
	{
		max_heap(a,i,n-1);
	}
	for(int i=n-1;i>0;i--)
	{
		int tmp=a[0];
		a[0]=a[i];
		a[i]=tmp;
		max_heap(a,0,i-1);
	}
}
int main()
{
	int n;
	cin>>n;
	int *a;
	a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	heap_sort(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}

