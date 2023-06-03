#include<iostream>
using namespace std;
void merge_sort(int* a,int *b,int left,int mid,int right)
{
	int l_=left;
	int r_=mid+1;
	int pos=left;
	while(l_<=mid&&r_<=right)
	{
		if(a[l_]<a[r_])
		{
			b[pos]=a[l_];
		//	cout<<"the number a is "<<b[pos]<<endl;
			pos++;
			l_++;
		}
		else
		{
			b[pos]=a[r_];
		//	cout<<"the number b is "<<b[pos]<<endl;
			pos++;
			r_++;
		}
	}
	while(l_<=mid)
	{
		b[pos]=a[l_];
//		cout<<"the number c is "<<b[pos]<<endl;
		pos++;
		l_++;
	}
	while(r_<=right)
	{
		b[pos]=a[r_];
//		cout<<"the number d is "<<b[pos]<<endl;
		pos++;
		r_++;
	}
	for(int i=left;i<=right;i++)
	{
		a[i]=b[i];
	}
/*	for(int i=0;i<4;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;*/
}			
void divide(int *a,int *b,int left,int right)
{
	if(left>=right)
	{
		return;
	}
	else if(left<right)
	{
		int mid=(left+right)/2;
		divide(a,b,left,mid);
		divide(a,b,mid+1,right);
		merge_sort(a,b,left,mid,right);
	}
}
void max_heap(int *a,int start,int end)
{
        int parent=start;
        int son=parent*2+1;
        while(son<=end)
        {
                if((son+1)<=end&&a[son]<a[son+1])
                {
                        son++;
                }
                if(a[parent]>a[son])
                {
                        return;
                }
                else
                {
                        int tmp=a[son];
                        a[son]=a[parent];
                        a[parent]=tmp;
                        parent=son;
                        son=parent*2+1;
                }
        }
}
void heap_sort(int *a,int n)
{
        for(int i=(n-1)/2;i>=0;i--)
        {
                max_heap(a,i,n-1);
        }
        for(int i=n-1;i>0;i--)
        {
                int tmp=a[0];
                a[0]=a[i];
                a[i]=tmp;
                max_heap(a,0,i-1);
        }
}
int main()
{
	int n;
	cin>>n;
	int *a;
	int *b;
	int *c;
	a=new int[n];
	b=new int[n];
	c=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=0;
		c[i]=a[i];
	}
	divide(a,b,0,n-1);
	for(int i=0;i<n;i++)
	{
		if(i!=n-1)
		{
			cout<<b[i]<<" ";
		}
		else
		{
			cout<<b[i];
		}
	}
	cout<<endl;
	heap_sort(c,n);
	for(int i=n-1;i>=0;i--)
	{
		if(i!=0)
		{
			cout<<c[i]<<" ";
		}
		else
		{
			cout<<c[i];
		}
	}
}
