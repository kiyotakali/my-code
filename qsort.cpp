#include<iostream>
using namespace std;
void swap(int* a,int i,int j)
{
	int tmp=a[i];
	a[i]=a[j];
	a[j]=tmp;
}
void qsort(int m,int n,int* a)
{
	int mid=a[(m+n)/2];
	int i=m;
	int j=n;
	while(i<=j)
	{
		while(a[i]<mid)
		{
			i++;
		}
		while(a[j]>mid)
		{
			j--;
		}
		if(i<=j)
		{
			swap(a,i,j);
			i++;
			j--;
		}
	}
	if(i<n)
	{
		qsort(i,n,a);
	}
	if(j>m)
	{
		qsort(m,j,a);
	}
}
int main()
{
	int n;
	cin>>n;
	int *a;
	a=new int[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	qsort(1,n,a);
	for(int i=1;i<=n;i++)
	{
		if(i!=n)
		{
			cout<<a[i]<<" ";
		}
		else
		{
			cout<<a[i];
		}
	}
}
	
