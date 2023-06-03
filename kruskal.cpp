#include<iostream>
using namespace std;
int check_circle_a[100000];
int check_circle_b[100000];
bool findnumber(int* a,int* b,int sum,int tmp)
{
	int time=0;
	for(int i=0;i<sum;i++)
	{
		if(a[i]==tmp||b[i]==tmp)
		{
			time++;
		}
	}
	if(time==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool define_circle(int* a,int *b,int sum)
{
	int *a1;
	int *b1;
	a1=new int[sum];
	b1=new int[sum];
	for(int i=0;i<sum;i++)
	{
		a1[i]=a[i];
		b1[i]=b[i];
	}
	for(int i=0;i<sum;i++)
	{
		for(int j=0;j<sum;j++)
		{
			int tmp1=a1[j];
			int tmp2=b1[j];
			if(findnumber(a1,b1,sum,tmp1)||findnumber(a1,b1,sum,tmp2))
			{
				a1[j]=b1[j]=0;
			}
		}
	}
	int he=0;
	for(int i=0;i<sum;i++)
	{
		he+=a1[i]+b1[i];
	}
	if(he!=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
struct Node
{
	int a,b;
	int w;
};
struct Pic
{
	int len,n;
	struct Node* list;
};
void set(struct Pic g)
{
	g.len=0;
	g.list=new Node[1000];
}
void get_data(Pic g,int i)
{
	cin>>g.list[i].a>>g.list[i].b>>g.list[i].w;
}
void newswap(Pic g,int m,int n)
{
	int tmp1=g.list[m].a;
	int tmp2=g.list[m].b;
	int tmp3=g.list[m].w;
	g.list[m].a=g.list[n].a;
	g.list[m].b=g.list[n].b;
	g.list[m].w=g.list[n].w;
	g.list[n].a=tmp1;
	g.list[n].b=tmp2;
	g.list[n].w=tmp3;
}
void sortnode(Pic g)
{
	for(int i=0;i<g.len-1;i++)
	{
		for(int j=i+1;j<g.len;j++)
		{
			if(g.list[i].w>g.list[j].w)
			{
				newswap(g,i,j);
			}
		}
	}
}
void kruskal(Pic g)
{
	int sum=0;
	int count=0;
	for(int i=0;i<g.len;i++)
	{
		sortnode(g);
		int tmp=g.list[i].w;
		check_circle_a[sum]=g.list[i].a;
		check_circle_b[sum]=g.list[i].b;
		sum++;
		if(define_circle(check_circle_a,check_circle_b,sum))
		{
			sum--;
		}
		else
		{
		/*	cout<<"w in this turn is"<<g.list[i].w<<" and a is "<<g.list[i].a<<" b is "<<g.list[i].b<<endl;
*/			count+=g.list[i].w;
		}
	}
	cout<<count<<endl;;
}
int main()
{
	Pic g;
	set(g);
	cin>>g.n>>g.len;
	for(int i=0;i<g.len;i++)
	{
		get_data(g,i);
	}
	sortnode(g);
/*	cout<<endl;
	for(int i=0;i<g.len;i++)
	{
		cout<<g.list[i].a<<" "<<g.list[i].b<<" "<<g.list[i].w<<endl;
	}*/
	kruskal(g);
}
