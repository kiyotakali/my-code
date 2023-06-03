#include<cstring>
#include<iostream>
#include<string>
using namespace std;
int n,b,a[100000];
int main()
{
	int k=-1;
	cin>>n>>b;
	int t=n;
	while(n!=0)
	{
		k++;
		a[k]=n%b;
		n=n/b;
	}
	bool flag=true;
	for(int i=0; i<=k/2; i++)
	{
		if(a[i]!=a[k-i]) flag=false;
	}
	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	if(t==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=k; i>=0; i--)
	{
		if(i!=k) cout<<" ";
		cout<<a[i];
	}
}
