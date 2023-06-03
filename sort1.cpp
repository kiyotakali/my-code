#include<iostream>
using namespace std;
void bubble(int* a,int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>=a[j])
			{
				int tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
}
void choose(int* a,int n)
{
	for(int i=0;i<n-1;i++)
	{
		int tmp=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[tmp]<a[j])
			{
				tmp=j;
			}
		}
		int tmp1=a[tmp];
		a[tmp]=a[i];
		a[i]=tmp1;
	}
}
int main()
{
	int n=10;
	int a[10];
	int b[10];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	bubble(a,n);
	choose(b,n);
	for(int i=0;i<n;i++)
	{
		if(i!=n-1)
		{
			cout<<a[i]<<" ";
		}
		else
		{
			cout<<a[i];
		}
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		if(i!=n-1)
		{
			cout<<b[i]<<" ";
		}
		else
		{
			cout<<b[i];
		}
	}
}
