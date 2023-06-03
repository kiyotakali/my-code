#include<iostream>
#include<queue>
using namespace std;
int h,n;
struct dot{
	int l;
	int r;
	int w;
};
dot a[100010];
int b[100010];
bool c[100010];
int d[100010],hh;
void create()
{
	while(h<2*n-1)
	{
		int min1=0x7f,min2=0x7f,left=0,right=0;
		for(int i=1;i<=h;i++)
		{
			if(b[i]<=min1&&!c[i])
			{
				
				min1=b[i];		
				left=i;
				//cout<<min1<<endl;
			}
		}
		for(int i=1;i<=h;i++)
		{
			if(b[i]<=min2&&b[i]!=min1&&!c[i])
			{
				min2=b[i];
				right=i;
			}
		}
		//cout<<left<<" "<<right<<endl;
		c[left]=1;
		c[right]=1;
		a[++h].r=right;
		a[h].l=left;
		a[h].w=min1+min2;
		b[h]=a[h].w;
	}
	return ;
}
int tot(int x)
{
	if(a[x].l==0&&a[x].r==0) 
	{
		return 0;
	}
	return a[a[x].l].w+a[a[x].r].w+tot(a[x].l)+tot(a[x].r);
}
void print(int x)
{
	if(a[x].l==0&&a[x].r==0) 
	{
		cout<<a[x].w;
		return ;
	}
	cout<<a[x].w<<"(";
	print(a[x].l);
	cout<<",";
	print(a[x].r);
	cout<<")";
}
void check(int x)
{
	//cout<<x<<" "<<hh<<endl;
	if(a[x].l==0&&a[x].r==0) 
	{	
		for(int i=1;i<=hh;i++) cout<<d[i];
		cout<<" ";
		return;
	}
	d[++hh]=0;
	check(a[x].l);
	hh--;
	d[++hh]=1; 
	check(a[x].r);
	hh--;
	return ;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		b[++h]=x;
		a[h].w=x;
		a[h].l=0,a[h].r=0;
	}
	create();
	cout<<tot(2*n-1)<<endl;
	
	print(2*n-1);
	cout<<endl;
	check(2*n-1);
	return 0;
}

