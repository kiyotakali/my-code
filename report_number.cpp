#include<iostream>
using namespace std;
class soldier
{
private:
	int a[6000];
	int number;
public:
	soldier(int num)
	{
		number=num;
		for(int i=0;i<number;i++)
		{
			a[i]=i+1;
		}
	}
	void pull(int i)
	{
		int tmp=a[i];
		a[i]=0;
		number--;
		//cout<<tmp<<endl;
	}
	int pull_(int i)
	{
		return a[i];
	}
	bool check(int i)
	{
		if(a[i]!=0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int show_num()
	{
		return number;
	}
};
int main()
{
	int N;
	cin>>N;
	soldier a(N);
	int count=1;
	int i=0;
	int jiou=0;
	while(a.show_num()>3)
	{
		while(jiou==0)
		{
			if(count==1)
			{
				count++;
				while(!a.check(i)&&i<N)
				{
					i++;
				}
				if(i>=N)
				{
					break;
				}
				else
				{
					i++;
		//			cout<<"i 现在是"<<i<<endl;
				}
			}
			else
			{
				count=1;
				while(!a.check(i)&&i<N)
				{
					i++;
				}
				if(i>=N)
				{

					break;
				}
				else
				{
					a.pull(i);
					i++;
		//			cout<<"i 现在是"<<i<<endl;
				}
			
			}
		}
		while(jiou==1)
		{
			if(count==1)
			{
				count++;
				while(!a.check(i)&&i<N)
				{
					i++;
				}
				if(i>=N)
				{
					break;
				}
				else
				{
					i++;
		//			cout<<"i 现在是"<<i<<endl;
				}
			
			}
			else if(count==2)
			{
				count++;
				while(!a.check(i)&&i<N)
				{
					i++;
				}
				if(i>=N)
				{
					break;
				}	
				else
				{
					i++;
		//			cout<<"i 现在是"<<i<<endl;
				}
			
			}
			else
			{
				count=1;
				while(!a.check(i)&&i<N)
				{
					i++;
				}
				if(i>=N)
				{
					break;
				}
				else
				{
					a.pull(i);
					i++;
		//			cout<<"i 现在是"<<i<<endl;
				}
			
			}
		}
		jiou=(jiou+1)%2;
		//cout<<"jiou现在是"<<jiou<<endl;
		i=0;
		count=1;
	//	cout<<"还剩"<<a.show_num()<<"个数"<<endl;
	}
	int n=1;
	for(int j=0;j<N;j++)
	{
		if(a.check(j)&&n<a.show_num())
		{
			cout<<a.pull_(j)<<" ";
			n++;
		}
		else if(a.check(j)&&n==a.show_num())
		{
			cout<<a.pull_(j);
			break;
		}

	}
	cout<<endl;
}









