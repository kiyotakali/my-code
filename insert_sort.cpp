#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		int tmp=i;
		for(int j=i-1;j>=0;j--)
		{
			if(a[tmp]<a[j])
			{
				swap(a[tmp],a[j]);
				tmp=j;
				j=tmp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
