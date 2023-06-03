#include<iostream>
using namespace std;
void shai(int *a,int n,int b)
{
	for(int i=1;i<n;i++)
	{
		if((i+1)%b==0&&(i+1)/b!=1)
		{
			a[i]=0;
		}
	}
}
int checkzero(int *a,int n,int i)
{
	int j=i+1;
	while(j!=n-1)
	{
		if(a[j]!=0)
		{
			return 1;
		}
		j++;
	}
	return 0;
}
int main()
{
	int n;
	cin>>n;
	int a[10000];
	int b[100];
	for(int i=1;i<n;i++)
	{
		a[i]=i+1;
	}
	for(int i=1;i<100;i++)
	{
		b[i]=i+1;
	}
	a[0]=b[0]=0;
	shai(b,100,2);
	shai(b,100,3);
	shai(b,100,5);
	shai(b,100,7);
	for(int i=1;i<100;i++)
	{
		if(b[i]!=0)
		{
			shai(a,n,b[i]);
		}
	}
	for(int i=1;i<n-1;i++)
	{
		if(a[i]!=0&&checkzero(a,n,i)==1)
		{
			cout<<a[i]<<" ";
		}
		else if(a[i]!=0&&checkzero(a,n,i)==0)
		{
			cout<<a[i];
		}
	}
}

