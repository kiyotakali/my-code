#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n1,n2,n3,N;
	string sample;
	cin>>sample;
	N=sample.length();
	n1=n2=(N+2)/3;
	n3=N+2-n1-n2;
	int space=n3-2;
	int xian1=0;
	int xian2=N-1;
	for(int i=0;i<n1;i++)
	{
		if(i<n1-1)
		{
			cout<<sample[xian1];
			for(int j=0;j<space;j++)
			{
				cout<<" ";
			}
			cout<<sample[xian2]<<endl;
			xian1++;
			xian2--;
		}
		else
		{
			for(int j=xian1;j<=xian2;j++)
			{
				cout<<sample[j];
			}
			cout<<endl;
		}
	}
}



