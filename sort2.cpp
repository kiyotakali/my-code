#include<iostream>
#include<string.h>
using namespace std;
struct student
{
	int num;
	string name;
	int score;
};
void swap(student* stu,int i,int j)
{
	int tmp1=stu[i].num;
	string tmp2=stu[i].name;
	int tmp3=stu[i].score;
	stu[i].num=stu[j].num;
	stu[i].name=stu[j].name;
	stu[i].score=stu[j].score;
	stu[j].num=tmp1;
	stu[j].name=tmp2;
	stu[j].score=tmp3;
}
void bubble_sort(student* stu,int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(stu[i].score<stu[j].score)
			{
				swap(stu,i,j);
			}
		}
	}
}
int main()
{
	int n;
	cin>>n;
	student* stu;
	stu=new student[n];
	for(int i=0;i<n;i++)
	{
		cin>>stu[i].num>>stu[i].name>>stu[i].score;
	}
	bubble_sort(stu,n);
	for(int i=0;i<n;i++)
	{
		cout<<stu[i].num<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
	}
}

