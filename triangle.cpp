#include<bits/stdc++.h>
using namespace std;
class queue_
{
private:
	int maxsize;
	int *a;
	int front;
	int rear;
public:
	queue_(int n)
	{
		maxsize=n;
		a=new int[maxsize];
		front=rear=0;
	}
	~queue_()
	{
		delete []a;
	}
	bool isempty()
	{
		int a=front%maxsize;
		int b=front%maxsize;
		int c=a-b;
		if(c==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isfull()
	{
		int a=front%maxsize;
		int b=front%maxsize;
		int c=a-b;
		if(c==maxsize||c==-maxsize)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void inqueue(int number)
	{
		if(isfull())
		{
			cout<<"the queue is full"<<endl;
		}
		else
		{			
			a[rear%maxsize]=number;
			rear++;
		}
	}
	void outqueue()
	{	
		front++;
	}
	int getfirst()
	{
		return a[front%maxsize];
	}
	void plus()
	{
		int q=a[front%maxsize]+a[(front+1)%maxsize];
		outqueue();
		inqueue(q);
		cout<<q<<" ";
	}
};
int main()
{
	int n;
	cin>>n;
	queue_ d(n);
	d.inqueue(1);
	d.inqueue(1);
	d.inqueue(1);
	cout<<"1"<<endl;
	cout<<"1 1"<<endl;
	d.outqueue();
	for(int i=3;i<=n;i++)
	{
		d.inqueue(1);
		cout<<"1 ";
		for(int j=2;j<=i;j++)
		{
			if(j<i)
			{
				d.plus();
			}
			else 
			{
				d.inqueue(1);
				cout<<"1"<<endl;
				d.outqueue();
			}
		}
	}
}
			

	

	
	
