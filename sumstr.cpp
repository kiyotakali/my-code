#include<iostream>
using namespace std;
int sum(int *n1,int *a,int b,int c)
{
	int sum_bc=0;
	for(int k=a[b];k<a[c];k++)
	{
		sum_bc+=n1[k];
	}
	sum_bc=sum_bc-n1[a[b]];
//	cout<<sum_bc<<endl;
	return sum_bc;
}
void sum_(int *n1,int *a,int **b,int i,int count)
{
	int flag=1;
	int tmp=n1[a[i]];
	for(int j=i+1;j<count;j++)
	{
		int tmp1=sum(n1,a,i,j);
		if(tmp1>tmp)
		{
			tmp=tmp1;
			b[i][0]=tmp;
			b[i][1]=a[i];
			b[i][2]=a[j]-2;
			flag=0;
		}
	}
	if(flag==1)
	{
		b[i][0]=tmp;
		b[i][1]=a[i];
		b[i][2]=a[i];
	}
//	cout<<b[i][0]<<endl;
}
int main()
{
	int n;
	cin>>n;
	int *n1;
	n1=new int[n+2];
	int count1=0;
	int count2=0;
	for(int i=1;i<n+1;i++)
	{
		cin>>n1[i];
		if(n1[i]<0)
		{
			count1++;
		}
		else if(n1[i]==0)
		{
			count2++;
		}
	}
	n1[n+1]=0;
	n1[0]=0;
	if(count1==n)
	{
		cout<<"0 "<<n1[1]<<" "<<n1[n]<<endl;
	}
	else
	{
		int count=count1+count2+2;
		int *a;
		a=new int[count];
		int** b;
		*b=new int[count];
		for(int i=0;i<count;i++)
		{
			b[i]=new int[3];
		}
		int num=0;
		for(int i=0;i<n+2;i++)
		{
			if(n1[i]<=0)
			{
				a[num]=i;
	//			cout<<a[num]<<" ";
				num++;
			}
		}
	//	cout<<endl;
	//	cout<<count<<endl;
		for(int i=0;i<count;i++)
		{
			sum_(n1,a,b,i,count);
		}
		//for(int k=0;k<count;k++)
	//	{
	//		cout<<b[k][0]<<" "<<b[k][1]<<" "<<b[k][2]<<endl;
	//	}
		for(int i=count-1;i>0;i--)
		{
			for(int j=i-1;j>=0;j--)
			{
				if(b[i][0]>b[j][0])
				{
					int tmp1=b[j][0];
					b[j][0]=b[i][0];
					b[i][0]=tmp1;
					int tmp2=b[j][1];
					b[j][1]=b[i][1];
					b[i][1]=tmp2;
					int tmp3=b[j][2];
					b[j][2]=b[i][2];
					b[i][2]=tmp3;
				}
				else 
				{
					break;
				}
			}
		//	cout<<i<<" :"<<endl;
		//	for(int k=0;k<count;k++)
		//	{
		//		cout<<b[k][0]<<" "<<b[k][1]<<" "<<b[k][2]<<endl;
		//	}
		}
		cout<<b[0][0]<<" "<<b[0][1]<<" "<<b[0][2]<<endl;
		//cout<<b[1][0]<<" "<<b[1][1]<<" "<<b[1][2]<<endl;
	}
}
	
