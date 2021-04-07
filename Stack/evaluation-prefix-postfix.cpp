#include<iostream>
#include<stack>
#include<string>
#include<string.h>
/*
Application of Stack: Evaluation of Prefix and Postfix
Logic: Push if char is not a symbol 
       and when a symbol comes evaluate last 2 element from stack 
	   and pop them and push the evaluated sum.

For Prefix: Iterate from end
For Postfix: Iterate from starting
*/
using namespace std;
int evaluate(char c[],int i,int op1,int op2)
{
	int r;
	if(c[i]=='*')
			r=op1*op2;
			else if(c[i]=='/')
			r=op1/op2;
			else if(c[i]=='+')
			r=op1+op2;
			else if(c[i]=='-')
			r=op1-op2;
	return r;
}
int postfix_evaluation(char c[],int n)
{
	stack<int> s;
	for(int i=0;i<n;i++)
	{
		
		
		if(c[i]!='+' && c[i]!='-' && c[i]!='*' && c[i]!='/')
		{
			s.push(c[i]-'0');
			
			
		}
		else if(!s.empty() && s.size()>1)
		{
			int op2=s.top();
			s.pop();
			int op1=s.top();
			s.pop();
			int r=evaluate(c,i,op1,op2);
			s.push(r);
			
			
		}
	}
	return s.top();
}

int prefix_evaluation(char c[],int n)
{
	stack<int> s;
	for(int i=n-1;i>=0;i--)
	{
	
		if(c[i]!='+' && c[i]!='-' && c[i]!='*' && c[i]!='/')
		{
			s.push(c[i]-'0');
		}
		else if(!s.empty() && s.size()>1)
		{
			int op1=s.top();
			s.pop();
			int op2=s.top();
			s.pop();
			int r=evaluate(c,i,op1,op2);
			s.push(r);
			
			
		}
	}
	return s.top();
}
int main()
{
	char c[100],d[100];
	cout<<"Enter the string for Prefix Evaluation "<<endl;
	gets(c);
	int result=prefix_evaluation(c,strlen(c));
	cout<<"Result is "<<result;
	cout<<"Enter the string for Postfix Evaluation "<<endl;
	gets(d);
	int result=postfix_evaluation(c,strlen(c));
	cout<<"Result is "<<result;
}
