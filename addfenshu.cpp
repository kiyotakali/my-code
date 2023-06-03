#include<iostream>
using namespace std;
struct huffmantree
{
	int layer;
	int power,lc,rc;
	int father;
};
class newstack
{
private:
        int a[100];
        int head;
        int tail;
public:
        newstack()
        {
                head=0;
                tail=0;
        }
	int pop()
	{
		tail--;
		return a[tail];	
        }
        void push(int b)
        {
                a[tail]=b;
                tail++;
        }
        bool isempty()
        {
                if(head==tail-1)
                {
                        return true;
                }
                else
                {
                        return false;
                }
        }
	void set_order()
	{
		for(int i=tail-1;i>0;i--)
		{
			for(int j=i-1;j>=0;j--)
			{
				if(a[i]>a[j])
				{
					int tmp=a[i];
					a[i]=a[j];
					a[j]=tmp;
				}
			}
		}
	}

};
bool check_same(int *c,int N,int b)
{
	for(int
struct huffmantree Tr[100];
int main()
{
	int N;
	cin>>N;
	newstack a;
	int c[100];
	int b;
	for(int i=0;i<N;i++)
	{
		cin>>b;
		a.push(b);
		c[i]=b;
	}
	int countlayer=1;
	int countnumber1=1;
	int countnumber2=N+1;
	int tmp1,tmp2,tmp3;
	tmp3=0;
	while(!a.isempty())
	{	
		a.set_order();
		tmp1=a.pop();
		tmp2=a.pop();
		if(tmp3==tmp1)
		{
			countlayer++;
			Tr[countnumber2].lc=countnumber2-1;
			Tr[countnumber2-1].father=countnumber2;
			Tr[countnumber1].layer=countlayer;
			Tr[countnumber1].power=tmp2;
			Tr[countnumber1].lc=0;
			Tr[countnumber1].rc=0;
			Tr[countnumber1].father=countnumber2;
			Tr[countnumber2].rc=countnumber1;
			Tr[countnumber2].power=tmp1+tmp2;
			countnumber1++;
			countnumber2++;
		}
		else if(tmp3==tmp2)
		{
			countlayer++;
			Tr[countnumber2].rc=countnumber2-1;
			Tr[countnumber2-1].father=countnumber2;
			Tr[countnumber1].layer=countlayer;
			Tr[countnumber1].power=tmp1;
			Tr[countnumber1].lc=0;
			Tr[countnumber1].rc=0;
			Tr[countnumber1].father=countnumber2;
			Tr[countnumber2].lc=countnumber1;
			countnumber1++;
			countnumber2++;
		}
		else
		{
			if(countlayer==1)
			{
				Tr[countnumber1].layer=countlayer;
				Tr[countnumber1].power=tmp1;
				Tr[countnumber1].lc=0;
				Tr[countnumber1].rc=0;
				Tr[countnumber1].father=countnumber2;
				Tr[countnumber2].lc=countnumber1;
				countnumber1++;
				Tr[countnumber1].layer=countlayer;
				Tr[countnumber1].power=tmp2;
				Tr[countnumber1].lc=0;
				Tr[countnumber1].rc=0;
				Tr[countnumber1].father=countnumber2;
				Tr[countnumber2].rc=countnumber1;
				Tr[countnumber2].layer=countlayer+1;
				Tr[countnumber2].power=tmp1+tmp2;
				countnumber1++;
				countnumber2++;
			}
			else
			{
				Tr[countnumber1].layer=countlayer;
				Tr[countnumber1].power=tmp1;
				Tr[countnumber1].lc=0;
				Tr[countnumber1].rc=0;
				Tr[countnumber1].father=countnumber2;
				Tr[countnumber2].lc=countnumber1;
				countnumber1++;
				Tr[countnumber1].layer=countlayer;
				Tr[countnumber1].power=tmp2;
				Tr[countnumber1].lc=0;
				Tr[countnumber1].rc=0;
				Tr[countnumber1].father=countnumber2;
				Tr[countnumber2].rc=countnumber1;
				Tr[countnumber2].layer=countlayer+1;
				Tr[countnumber2].power=tmp1+tmp2;
				countnumber1++;
				countnumber2++;
			}
		}
		tmp3=tmp1+tmp2;
		a.push(tmp3);
	}
	for(int i=1;i<=2*N;i++)
	{
		Tr[i].layer=-Tr[i].layer+countlayer;
	}
	int WPL=0;
	for(int i=0;i<2*N;i++)
	{
		if(Tr[i].lc==0)
		{
			WPL+=Tr[i].power*Tr[i].layer;
		}
	}
	cout<<WPL<<endl;
}





	


