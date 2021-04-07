#include<iostream>
using namespace std;
class Node
{
	public:
	Node *link;
	int data;
};
class Stack
{
private:

public:
	Node *top;
	Stack()
	{
		
		top=NULL;
	}
	
	void push(int ele)
	{
		Node *temp=new Node();
		temp->data=ele;
		temp->link=top;
		top=temp;
	}
	
	void pop()
	{
		top=top->link;
		//delete(top->link);
	}
	void Print()
	{
		Node* temp=top;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->link;
		}
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
	s.push(4); s.Print();
}
