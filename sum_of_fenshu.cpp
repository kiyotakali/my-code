#include<iostream>
using namespace std;
struct fs
{
	int fz;
	int fm;
};
struct fs Fs[100];
int min_(int a,int b)
{
	int min;
	if(a<=b)
	{
		min=a;
	}
	else
	{
		min=b;
	}
	return min;
}	
void yu(int& tmp1,int &tmp2,int min)
{
	 for(int j=2;j<=min;j++)
        {
                if(tmp1%j==0&&tmp2%j==0)
                {
                        tmp1=tmp1/j;
                        tmp2=tmp2/j;
                        min=min_(tmp1,tmp2);
                }
        }
}
void addfs(struct fs* a,int i)
{
	int tmp1=Fs[0].fz*Fs[i].fm+Fs[i].fz*Fs[0].fm;
	int tmp2=Fs[0].fm*Fs[i].fm;
	int min=min_(tmp1,tmp2);
	for(int j=2;j<=min;j++)
	{
		yu(tmp1,tmp2,min);
	}
	Fs[0].fz=tmp1;
	Fs[0].fm=tmp2;
}	
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d/%d",&Fs[i].fz,&Fs[i].fm);
	}
	for(int i=1;i<n;i++)
	{	
		addfs(Fs,i);
	}
	int zs=Fs[0].fz/Fs[0].fm;
	int fz_=Fs[0].fz-zs*Fs[0].fm;
	if(zs!=0)
	{
		if(fz_==0)
		{
			cout<<zs;
		}
		else
		{
			cout<<zs<<" "<<fz_<<"/"<<Fs[0].fm;
		}
	}
	else
	{
		if(fz_==0)
		{
			cout<<"0";
		}
		else
		{
			cout<<fz_<<"/"<<Fs[0].fm;
		}
	}
}



