#include<cstring>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,b;
	int a[10000];
	int k=0;
	cin>>n>>b;
	if(n==0)
        {
		cout<<"Yes"<<endl;
		cout<<"0";
        }
	else
	{
		while(n!=0)
		{
			a[k]=n%b;
			n=n/b;
			k++;
		}
		bool flag=true;
		for(int i=0; i<k; i++)
		{
			if(a[i]!=a[k-i-1]) 
			{
				flag=false;
			}
		}
		if(flag) 
		{
			cout<<"Yes"<<endl;
		}
		else 
		{
			cout<<"No"<<endl;
		}
		for(int i=k-1; i>=0; i--)
       		{
                	if(i!=k-1) cout<<" ";
                	cout<<a[i];
       		}
	}
}
