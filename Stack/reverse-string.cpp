#include <iostream>
#include <stack>
#include <string.h>
/*
Application of Stack:
Reversal of String (Reversal of Linked list is better using stack)

T.C: O(N)-- O(1) for push and pop
S.C: O(N)-- Extra space for stack

Note: Better method are availiable for reversal of string.
      Using Swap T.C: O(N) and S.C: O(1)
*/
using namespace std;
class Reverse
{
	public:
		reverse_string(char c[],int n)
		{
			stack<char> s;
			for(int i=0;i<n;i++)
			{
				s.push(c[i]);
			}
			for(int i=0;i<n;i++)
			{
				c[i]=s.top();
				s.pop();
			}
		}
};
int main()
{
	Reverse r;
	char c[100];
	cout<<"Enter the string"<<endl;
	gets(c);
	r.reverse_string(c,strlen(c));
	cout<<"Output is "<<c<<endl;
}
