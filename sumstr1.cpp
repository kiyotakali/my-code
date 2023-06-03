#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int a[10001],b[10001];
	int K;
	cin>>K;
	for(int i=0; i<K; i++)
	{
		cin>>a[i];
		if(i==0)
		{
			b[i]=a[i];
		}
		else
		{
			b[i]=b[i-1]+a[i];
		}
	}
	int max=b[0];
	int c=0,d=0;
	for(int i=1; i<K; i++)
	{
		for(int j=i; j<K; j++)
		{
			if(max<b[j]-b[i-1])
			{
				c=i;
				d=j;
				max=b[j]-b[i-1];
			}
		}
	}
	if(max<0) cout<<0<<" "<<a[0]<<" "<<a[K-1];
	else cout<<max<<" "<<c<<" "<<d;
}
