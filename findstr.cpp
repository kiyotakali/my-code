#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string s1;
	string s2;
	getline(cin,s1);
	getline(cin,s2);
	int count1=s1.length();
	int count2=s2.length();
	int number=0;
	int flag=0;
	while(number+count2<=count1)
	{
		if(s2==s1.substr(number,count2))
		{
			flag=1;
			break;
		}
		else
		{
			number++;
		}
	}
	if(flag==1)
	{
		cout<<number;
	}
	else
	{
		cout<<"-1";
	}
}	

