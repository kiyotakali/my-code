#include<iostream>
#include<string>
using namespace std;
class biao
{
private:
	string a;
	int number1;
	int number2;
public:
	biao(string b)
	{
		number1=number2=b.length();
		a=b;
	}
	void delete_(char c)
	{
		char tmp='^';
		for(int i=0;i<number1;i++)
		{
			if(a[i]==c)
			{
				a[i]=tmp;
				number2--;
			}
		}
	}
	void cout_()
	{
		for(int i=0;i<number1;i++)
		{
			char tmp='^';
			if(a[i]!=tmp)
			{
				cout<<a[i];
			}
		}
		cout<<endl;
		cout<<number2;
	}
};
int main()
{
	string b;
	getline(cin,b);
	biao a(b);
	a.cout_();
	char c;
	cin>>c;
	a.delete_(c);
	a.cout_();
}


