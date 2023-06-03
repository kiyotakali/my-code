#include<iostream>
using namespace std;
int check(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]>=5)
		{
			return 1;
		}
	}
	return 0;
}
void add(int *a,int n,int &number)
{
	for(int i=0;i<n;i++)
	{
		if((a[i]%5)==0&&a[i]!=0)
		{
			number++;
			a[i]=a[i]/5;
		}
		else
		{
			a[i]=0;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int *a;
	a=new int[n];
	int number=0;
	for(int i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	while(check(a,n)==1)
	{
		add(a,n,number);
	}
	cout<<number<<endl;
}
