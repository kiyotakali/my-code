#include<iostream>
using namespace std;
void add(int *a,int &time,int number)
{
	if(number==0)
	{
		time+=a[number]*6+5;
	}
	else
	{
		if(a[number-1]>a[number])
		{
			time+=(a[number-1]-a[number])*4+5;
		}
		else if(a[number-1]<a[number])
		{
			time+=(a[number]-a[number-1])*6+5;
		}
		else 
		{
			time+=5;
		}
	}
}
int main()
{
	int a[100];
	int count=0;
	int b;
	cin>>b;
	while(b!=0)
	{
		a[count]=b;
		count++;
		cin>>b;
	}
	a[count]=0;
	count++;
	int number=0;
	int time=0;
	while(a[number]!=0)
	{
		add(a,time,number);
		number++;
	}
	cout<<time;
}
		

