#include<iostream>
#include<math.h>
using namespace std;
int newpow(int a,int b)
{
	int tmp=1;
	for(int i=0;i<b;i++)
	{
		tmp*=a;
	}
	return tmp;
}
void turn(int *a,int number,int N1,int b)
{
	int i=0;
	while(i!=number)
	{
		int tmp=N1;
		a[i]=tmp/(newpow(b,number-1-i));
		N1=N1-a[i]*(newpow(b,number-1-i));
		i++;
	}
}
int define(int *a,int number,int *c)
{
	for(int i=0;i<number;i++)
	{
		if(a[i]!=c[i])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int N,b;
	cin>>N>>b;
	int max=0;
	int N1=N;
	int number=0;
	while(N!=0)
	{
		N=N/b;
		number++;
	}
	int *a;
	a=new int[number];
	turn(a,number,N1,b);
	int *c;
	c=new int[number];
	for(int i=0;i<number;i++)
	{
		c[i]=a[number-1-i];
	}
	if(define(a,number,c))
	{
		cout<<"Yes"<<endl;
		for(int i=0;i<number-1;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<a[number-1];
	}
	else
	{
		cout<<"No"<<endl;
                for(int i=0;i<number-1;i++)
                {
                        cout<<a[i]<<" ";
                }
                cout<<a[number-1];
        }
}	
