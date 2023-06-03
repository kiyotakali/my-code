#include<iostream>
using namespace std;
struct HuffmanTree
{
	int weight;                 
	int parent;                 
	int LChild;                 
	int RChild;                 
}; 
struct HuffmanTree huffmantree[10000];
void select(HuffmanTree *ht,int m,int& s1,int& s2)
{
	int min1,min2;
	int flag1=1;
	int flag2=1;
	for(int i=0;i<m;i++)
	{
		if(flag1==1&&flag2==1&&ht[i].parent==0)
		{
			min1=ht[i].weight;
			s1=i;
			flag1=0;
		}
		else if(flag1==0&&flag2==1&&ht[i].parent==0)
		{
			min2=ht[i].weight;
			s2=i;
			flag2=0;
			if(min1>min2)
			{
				int tmp1=min2;
				int tmp2=s2;
				min2=min1;
				s2=s1;
				min1=tmp1;
				s1=tmp2;
			}
		}
		else if(flag1==0&&flag2==0&&ht[i].parent==0)
		{
			if(ht[i].weight<min1)
			{
				min2=min1;
				s2=s1;
				min1=ht[i].weight;
				s1=i;
			}
			else if(ht[i].weight>min1&&ht[i].weight<min2)
			{
				min2=ht[i].weight;
				s2=i;
			}
		}
	}
}
void CrtHuffmanTree(HuffmanTree *ht, int *w, int n)
{
	int m;	
	for (int i=0;i<n;i++)
	{
		ht[i]={w[i],0,0,0};
		m=2*n-1;
	}
	for (int i=n;i<m;i++)
	{
		ht[i]={0,0,0,0};
	}
	for (int i=n;i<m;i++)
  	{
		int s1,s2;
		select(ht,i,s1,s2);
		//cout<<"s1 is "<<s1<<" and s2 is "<<s2<<endl;
    		ht[i].weight=ht[s1].weight+ht[s2].weight;
   		ht[s1].parent=i;
    		ht[s2].parent=i;
    		ht[i].LChild=s1;
    		ht[i].RChild=s2;
	}
}
int num_layer(HuffmanTree *ht,int i)
{
	int count=0;
	while(ht[i].parent!=0)
	{
		count++;
		i=ht[i].parent;
	}
	return count;
}
void print(HuffmanTree *ht,int x)
{
	if(ht[x].LChild==0&&ht[x].RChild==0)
	{
		cout<<ht[x].weight;
		return;
	}
	cout<<ht[x].weight<<"(";
	print(ht,ht[x].LChild);
	cout<<",";
	print(ht,ht[x].RChild);
	cout<<")";
}
void code(HuffmanTree *ht,int i,int n,int num)
{
	int number=0;
	int *a;
	a=new int[n];
	while(ht[i].parent!=0)
	{
		int tmp=ht[i].parent;
		if(ht[tmp].LChild==i)
		{
			a[number]=0;
			number++;
		}
		else if(ht[tmp].RChild==i)
		{
			a[number]=1;
			number++;
		}
		i=ht[i].parent;
	}
	if(num<=n)
	{
		for(int j=number-1;j>=0;j--)
		{
			cout<<a[j];
		}
		cout<<" ";
	}
	else
	{
		for(int j=number-1;j>=0;j--)
		{
			cout<<a[j];
		}
	}	
}
bool check_zero(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]!=0)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	int *a;
	a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	CrtHuffmanTree(huffmantree,a,n);
	int WSL=0;
	for(int i=0;i<n;i++)
	{
		WSL+=num_layer(huffmantree,i)*huffmantree[i].weight;
	}
	cout<<WSL<<endl;
	print(huffmantree,2*n-2);
	cout<<endl;
	int num=1;
	while(check_zero(a,n))
	{
		int flag=1;
		int tmp;
		int suoyin;
		for(int i=0;i<n;i++)
		{
			if(a[i]!=0&&flag==1)
			{
				tmp=a[i];
				suoyin=i;
				flag=0;
			}
			else if(a[i]!=0&&flag==0&&a[i]<tmp)
			{
				tmp=a[i];
				suoyin=i;
			}
		}
		a[suoyin]=0;
		code(huffmantree,suoyin,n,num);
		num++;
	}
/*	for(int i=0;i<2*n-1;i++)
	{
		cout<<huffmantree[i].weight<<endl;
	}*/
}


