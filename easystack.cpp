#include<iostream>
using namespace std;
class newstack
{
private:
	char a[100];
	int head;
	int tail;
public:
	newstack()
	{
		head=0;
		tail=0;
	}
	void pop(int n)
	{
		head++;
	}
	void push(char b)
	{
		a[tail]=b;
		tail++;
	}
	void match_check()
	{
		if(tail>=2)
		{
			if(a[tail-2]=='('&&a[tail-1]==')')
			{
				tail-=2;
			}
		}
	}
	bool isempty()
	{
		if(head==tail)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
int main()
{
	char c;
	newstack a;
	while(cin.get(c))
	{
		if(c=='('||c==')')
		{
			a.push(c);
			a.match_check();
		}
		if(c=='\n')
		{
			break;
		}
	}
	if(a.isempty())
	{
		cout<<"括号匹配！";
	}
	else
	{
		cout<<"括号不匹配！";
	}
}
	


	
