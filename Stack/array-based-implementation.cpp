#include<iostream>
#define MAX_SIZE 100
using namespace std;
/*
Stack:
It is a list with a constraint that insertion and deletion can happen from 1 end only.
Last In First Out(LIFO)

3 operations:
-> Push
-> Pop
-> Peak


Time Complexity:
All operations takes constant time
*/
class Stack
{
	private:
	int top;
	int A[MAX_SIZE];
	
	public:
		Stack()
		{
			top=-1;
		}
		void push(int ele)
		{
			if(is_full())
			cout<<"Overflow "<<endl;
			else
			A[++top]=ele;
		}
		void pop()
		{
			if(is_empty())
			cout<<"Underflow "<<endl;
			else
			top=top-1;
		}
		int peak()
		{
			return A[top];
		}
		bool is_full()
		{
			if(top==MAX_SIZE-1)
			return true;
			else
			return false;
		}
		bool is_empty()
		{
			if(top==-1)
			return true;
			else
			return false;
		}
		void Print()
		{
			for(int i=0;i<=top;i++)
			cout<<A[i]<<" ";
			cout<<endl;
		}	
};
int main()
{
	Stack s;
	s.push(1); s.Print();
	s.push(2); s.Print();
	s.push(3); s.Print();
	s.pop(); s.Print();
	s.push(7); s.Print();
	int a=s.peak();
	cout<<"Top element is "<<a<<endl;
}
