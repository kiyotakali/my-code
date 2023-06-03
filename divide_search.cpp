#include<iostream>
using namespace std;
int divide(int* a,int left,int right,int gl)
{
	int mid=(left+right)/2;
	int tmp;
	if(a[mid]>gl)
	{
		if(right-left>1)
		{
			tmp=divide(a,left,mid,gl);
		}
		else
		{
			if(a[left]!=gl&&a[right]!=gl)
			{
				tmp=-1;
			}
		}
	}
	else if(a[mid]<gl)
	{
		if(right-left>1)
		{
			tmp=divide(a,mid,right,gl);
		}
		else
		{
			if(a[left]!=gl&&a[right]!=gl)
			{
				tmp=-1;
			}
		}
	}
	else
	{
		tmp=mid;
	}
	return tmp;
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
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				int tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	int gl;
	cin>>gl;
	int flag=divide(a,0,n-1,gl);
	cout<<flag<<endl;
}

