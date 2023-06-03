#include<iostream>
using namespace std;
int converse(int num);
int main()
{
    int x,y;
    int a,b;
    cin>>x>>y;
    a=(x+y)/2;
    b=x-a;
    a=converse(a); 
    b=converse(b);
    int result1=a+b;
    int result2= a-b;
    cout<<result1<<" "<<result2;
    return 0;
}
int converse(int num)
{
    int result=0;
    int i;
    while(num!=0)
    {
        i=num%10;			 
        result=result*10+i;
        num=num/10;		
	}
    return result;
}
