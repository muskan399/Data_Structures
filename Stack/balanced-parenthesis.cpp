#include <iostream>
#include<stack>
#include<string.h>
using namespace std;
/*
Balancing the parenthesis is one of the most imp application of the Stack D.S

Logic: Push all the {,(,[ in stack and whenever },),] look for it in the top of the stack.
       If found: Pop the top element (Repeat the same process until stack become empty)
       Not found: Not Balanced
       
       Also at last if stack is not empty then: Not Balanced
            at last if stack is empty then: Balanced

Note: You may think of using logic No. of opening bracket==No. of closing brackets but this 
      will fail for cases like {[}]
*/
bool balanced_parenthesis(char c[],int n)
{
	stack<char> s;
	for(int i=0;i<n;i++)
	{
		if(c[i]=='{' || c[i]=='[' || c[i]=='(')
		s.push(c[i]);
		else if(c[i]=='}')
		{
			if(s.empty() || s.top()!='{')
			return false;
			else
			s.pop();
		}
			else if(c[i]==']')
		{
			if(s.empty() || s.top()!='[')
			return false;
			else
			s.pop();
		}
			else if(c[i]==')' || c[i]==']' || c[i]==')')
		{
			if(s.empty() || s.top()!='(')
			return false;
			else
			s.pop();
		}
		
	}
	if(s.empty()) return true;
	else return false;
}
int main()
{
	char c[100];
	cout<<"Enter:  ";
	gets(c);
	bool result=balanced_parenthesis(c,strlen(c));
	cout<<result;
}
