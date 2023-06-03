#include<bits/stdc++.h>
using namespace std;
void insert_sort(int *a,int begin,int n,int num)
{
        if(begin+num>n)
        {
                return;
        }
        else
        {
                for(int i=begin+num;i<=n;i+=num)
                {
                        int tmp=i;
                        for(int j=i-num;j>0;j-=num)
                        {
                                if(a[tmp]<a[j])
                                {
                                        swap(a[tmp],a[j]);
                                        tmp=j;
                                        j=tmp;
                                }
                        }
                }
        }
}
void shell(int *a,int n,int num)
{
	if(num!=1)
	{
		for(int i=1;i<num;i++)
		{
			insert_sort(a,i,n,num);
		}
	}
	else
	{
		insert_sort(a,1,n,1);
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int tmp=n/2;
	while(tmp!=0)
	{
		shell(a,n,tmp);
		tmp=tmp/2;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


