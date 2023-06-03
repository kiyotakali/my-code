#include<bits/stdc++.h>
using namespace std;
class stack_
{
private:
	int top;
	char a[100];
public:
	stack_()
	{
		top=0;
	}
	int isempty()
	{
		if(top==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int isfull()
	{
		if(top==100)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void pop()
	{
		if(isempty()==0)
		{
			top--;
		}
	}
	void push(char c)
	{
		a[top]=c;
		top++;
	}
	void define()
	{
		if(top>=2)
		{
			if((a[top-2]=='('&&a[top-1]==')')||(a[top-2]=='['&&a[top-1]==']'))
			{
				top=top-2;
			}
		}
	}
};
int main()
{
	stack_ b;
	char c;
	while(cin>>c)
	{
		b.push(c);
		b.define();
	}
	if(b.isempty()==1)
	{
		cout<<"match"<<endl;
	}
	else
	{
		cout<<"not match"<<endl;
	}
}

