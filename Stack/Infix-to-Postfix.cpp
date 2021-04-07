#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
/*
Application of Stack.

      INFIX      ->               POSTFIX
e.g. ((A+B)*C-D)*E              AB+C*D-E*

Logic:
->If a * or / comes then push it.

-> Any other operator(+,-) comes then pop the stack if the top element has 
   higher priority(in loop) also till we get '(' and continously append in the result.
   Atlast push the operator.
   (1st rule is special case of this: When *,/ is there then they will have 
   highest priority and nothing will be popped only * or / will be pushed.
   
-> If ( comes then push the element.

-> Atlast pop all the operator from stack and append in the result.
*/
bool is_opening(char c)
{
	if(c=='(') return true;
	else false;
}
bool is_highest_priority(char d)
{
	if(d=='*' || d=='/') return true;
	else return true;
}
string infix_to_postfix(char c[],int n)
{
	string postfix="";
	stack<char> s;
	for(int i=0;i<n;i++)
	{
		if(c[i]!='*' && c[i]!='-' && c[i]!='/' && c[i]!='+' && c[i]!='(' && c[i]!=')')
		{
			postfix=postfix+c[i];
		}
		else if(c[i]=='(')
		{
			s.push(c[i]);
		}
		else if(c[i]==')')
		{
			while(!s.empty()&& !is_opening(s.top()))
			{
				postfix=postfix+s.top();
				s.pop();
			}
			s.pop();
		}
		else 
		{
			while(!s.empty() && is_highest_priority(c[i]) && !is_opening(s.top()))
			{
			
				postfix=postfix+s.top();
				s.pop();
			}
			s.push(c[i]);
		}
		
	}
	while(!s.empty())
			{
				postfix=postfix+s.top();
				s.pop();
			}
	return postfix;
}
int main()
{
	char c[100];
	cout<<"Enter the string:  ";
	gets(c);
	string result=infix_to_postfix(c,strlen(c));
	cout<<"Postfix is "<<result;
}
