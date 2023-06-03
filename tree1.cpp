# include<bitsdc++.h>
# include<algorithm>
typedef long long ll;
using namespace std;
struct node
{
	char value;
	int lson=0;
	int rson=0;
	
};
node tree[114514];
void insert(int x,int y,int judge)
{
	if(y==0)
	return;
	
	if(judge==1)
	{
		
		tree[x].lson=y;
	}
	else
	tree[x].rson=y;
	
}
void preorder(int x)
{
	if(x==0)
	return;
	cout<<tree[x].value;
	preorder(tree[x].lson);
	preorder(tree[x].rson);
	
}
int main (void)
{
	ll n;
	cin>>n;
	int root;
	for(int i=1;i<=n;i++)
	{
		string in;
		cin>>in;
		if(i==1)
		root=in[0];
		int father=in[0];
		tree[father].value=in[0];
		int lson;
		int rson;
		if(in[1]>='a'&&in[1]<='z')
		{
			lson=in[1];
			tree[lson].value=in[1];
		}
		else
		lson=0;
		if(in[2]>='a'&&in[2]<='z')
		{
			rson=in[2];
		tree[rson].value=in[2];
		}
		else
		rson=0;
		insert(father,lson,1);
		insert(father,rson,0);
	}
		preorder(root);
		return 0;
		
}
