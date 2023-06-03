#include<bits/stdc++.h>
using namespace std;
struct doubletree
{
	char letter;
	int leftson;
	int rightson;
};
struct doubletree doubletree[10000];
void left_insert(int father,int leftson,char number)
{
	if(leftson!=0)
	{
		doubletree[father].leftson=leftson;
		doubletree[leftson].letter=number;
	}
	else
	{
		doubletree[father].leftson=0;
	}
}
void right_insert(int father,int rightson,char number)
{
	if(rightson!=0)
	{
		doubletree[father].rightson=rightson;
		doubletree[rightson].letter=number;
	}
	else
	{
		doubletree[father].rightson=0;
	}
}
void forwardcout(int root)
{
	cout<<doubletree[root].letter;
	if(doubletree[root].leftson!=0)
	{
		forwardcout(doubletree[root].leftson);

	}
	if(doubletree[root].rightson!=0)
	{
		forwardcout(doubletree[root].rightson);
	}
}
int main()
{
	int n;
	cin>>n;
	int root;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			string s;
			cin>>s;
			int father=s[0];
			root=father;
			doubletree[father].letter=s[0];
			if(s[1]>='a'&&s[1]<='z')
			{
				int left=s[1];
			       	left_insert(father,left,s[1]);
			}
			else
			{
				int left=0;
				left_insert(father,left,s[1]);
			}
			if(s[2]>='a'&&s[2]<='z')
			{
				int right=s[2];
				right_insert(father,right,s[2]);
			}
			else
			{
				int right=0;
				right_insert(father,right,s[2]);
			}
		}
		else
		{
			string s;
			cin>>s;
			int father=s[0];
			if(s[1]>='a'&&s[1]<='z')
			{
				int left=s[1];
				left_insert(father,left,s[1]);
			}
			else
			{
				int left=0;
				left_insert(father,left,s[1]);
			}
			if(s[2]>='a'&&s[2]<='z')
			{
				int right=s[2];
				right_insert(father,right,s[2]);
			}
			else
			{
				int right=0;
				right_insert(father,right,s[2]);
			}
		}
	}
	forwardcout(root);
}
		



			
