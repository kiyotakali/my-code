#include<iostream>
using namespace std;
#include<string>
int main()
{
	string a[100];
	int i=0;
	while(cin>>a[i])
	{	
		i++;
		if (cin.get() == '\n')break;
	}
	int final_num=0;
	for(int j=1;j<i;j++)
	{
		if(a[j].length()>a[j-1].length())
		{
			final_num=j;
		}
	}
	cout<<a[final_num];
}


