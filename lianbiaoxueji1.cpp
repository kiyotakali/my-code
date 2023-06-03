#include<bits/stdc++.h>
using namespace std;
struct student
{
	string Id;
	int class1;
	string name;
	float score1;
	float score2;
	float score3;
	string judge;
	float total_score;
	struct student *next;
};
void fixed_output()
{
        cout<<"1.input"<<endl;
        cout<<"2.delete"<<endl;
        cout<<"3.select"<<endl;
        cout<<"4.order"<<endl;
        cout<<"5.output"<<endl;
        cout<<"6.quit"<<endl;
        cout<<"please input your option"<<endl;
        return;
}
void easy_input(struct student *p)
{
	cout<<"Id ";
        cin>>p->Id;
        cout<<"class ";
        cin>>p->class1;
        cout<<"name ";
        cin>>p->name;
        cout<<"score1 ";
        cin>>p->score1;
        cout<<"score2 ";
        cin>>p->score2;
        cout<<"score3 ";
        cin>>p->score3;
	cout<<"continue?"<<endl;
	cin>>p->judge;
}
void easycout(struct student *p)
{
	cout<<p->Id<<",";
	cout<<p->class1<<",";
	cout<<p->name<<",";
	cout<<fixed<<setprecision(1);
	cout<<p->score1<<",";
	cout<<p->score2<<",";
	cout<<p->score3<<",";
	cout<<p->total_score<<endl;
}
struct student *input(int *n)
{
	struct student *head,*p1,*p2;
	p1=new struct student;
	easy_input(p1);
	p1->total_score=p1->score1+p1->score2+p1->score3;
	*n=0;
	head=NULL;
	while(p1->judge=="yes")
	{
		*n=*n+1;
		if(*n==1)
		{
			head=p1;
		}
		else 
		{
			p2->next=p1;
		}
			p2=p1;
			p1=new struct student;
			easy_input(p1);
			p1->total_score=p1->score1+p1->score2+p1->score3;
	}
	p2->next=p1;
	p2=p1;
	p2->next=NULL;
	*n=*n+1;
	return head;
}
void output(struct student *head)
{
	struct student *p;
	p=head;
	while(p!=NULL)
	{
		easycout(p);
		p=p->next;
	}
}
void select(struct student *head)
{
	struct student *p=head;
	int flag=1;
	string stu_select;
	cin>>stu_select;
	while(p!=NULL)
	{
		if(p->Id==stu_select)
		{
			easycout(p);
			flag=0;
		}
		stringstream ss;
		ss<<p->class1;
		string str=ss.str();
		if(str==stu_select)
		{
			easycout(p);
			flag=0;
		}
		p=p->next;
	}
	if(flag==1)
	{
		cout<<"there is no eligible student"<<endl;
	}
	cout<<"continue?"<<endl;
	string s;
	cin>>s;
	if(s=="yes")
	{
		select(head);
	}
}
void delete1(struct student *head)
{
	struct student *p1,*p2;
	p1=head;
	string stu_delete;
	cin>>stu_delete;
	if(((p1->Id==stu_delete)||(p1->name==stu_delete))&&(p1!=NULL))
	{
		head=p1->next;
	}
	else
	{
		p2=p1;
		p1=p1->next;
		while(p1!=NULL)
		{
			if(((p1->Id==stu_delete)||(p1->name==stu_delete))&&(p1->next!=NULL))
			{
				p2->next=p1->next;
				p1=p2->next;
			}
			else if(((p1->Id==stu_delete)||(p1->name==stu_delete))&&(p1->next=NULL))
			{
				p2->next=NULL;
			}
			else 
			{
				p2->next=p1;
				p2=p2->next;
				p1=p1->next;
			}
		}
	}
	output(head);
	cout<<"continue?"<<endl;
	string s;
	cin>>s;
	if(s=="yes")
	{
		delete1(head);
	}

}
void copy(struct student *p1,struct student *p2)
{
	p1->Id=p2->Id;
	p1->class1=p2->class1;
	p1->name=p2->name;	
	p1->score1=p2->score1;
	p1->score2=p2->score2;
	p1->score3=p2->score3;
	p1->total_score=p2->total_score;
	p1->judge=p2->judge;
}
void swap1(struct student *p1,struct student *p2)
{
	struct student *tmp;
	tmp=new struct student;
	copy(tmp,p1);
	copy(p1,p2);
	copy(p2,tmp);
}		
void order(struct student *head,int n)
{
	for(int i=1;i<n;i++)
	{
		struct student *p1=head;
		while(p1->next!=NULL)
		{
			if((p1->class1)>(p1->next->class1))
			{
				swap1(p1,p1->next);
			}
			p1=p1->next;		
		}
	}
	for(int i=1;i<n;i++)
	{
		struct student *p1=head;
		while(p1->next!=NULL)
		{
			if((p1->total_score)<(p1->next->total_score)&&(p1->class1==p1->next->class1))
			{
				swap1(p1,p1->next);
			}
			p1=p1->next;		
		}
	}
	output(head);
}
int main()			
{
	int n;
	struct student *head=NULL;
	int define=0;
	while(define!=6)
	{
		fixed_output();
		cin>>define;
		if(define==1)
		{
			head=input(&n);
		}
		else if(define==2)
		{	
			delete1(head);			
		}
		else if(define==3)
		{
			select(head);	
		}
		else if(define==4)
		{
			order(head,n);
		}
		else if(define==5)
		{
			output(head);
		}
	}
}
	
			


