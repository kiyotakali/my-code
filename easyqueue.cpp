#include<iostream>
using namespace std;
class newqueue
{
private:
	int a[100000];
	int head;
	int tail;
public:
	newqueue(int N)
	{
		head=0;
		tail=N-1;
		for(int i=0;i<N;i++)
		{
			cin>>a[i];
		}
	}
	void pop()
	{
		head++;
	}
	void push(int b)
	{
		tail++;
		a[tail]=b;
	}
	void cout_()
	{
		for(int i=head;i<tail;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<a[tail];
	}
};
int main()
{
	int N;
	cin>>N;
	newqueue c(N);
	c.pop();
	c.pop();
	c.push(11);
	c.push(12);
	c.cout_();
}


