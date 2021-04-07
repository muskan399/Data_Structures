#include<iostream>
#include<stack>
using namespace std;
/*
Application:
Reversal of LinkedList

T.C: O(n)
S.C: O(n)

Note: If we use 
      -> Iterative Approach: T.C: O(n) & S.C: O(1)
      -> Recursive Approach: T.C: O(n) & S.C: O(n)(Implicitly recursive calls use stack)
*/
class Node
{
	public:
	int data;
	Node* next;
};
Node* reverse_ll(Node* temp,int n)
{
    stack<Node*> s;
	for(int i=0;i<n-1;i++)
	{
	s.push(temp);
	temp=temp->next;
	}
	Node* a=temp;
	for(int i=0;i<n-1;i++)
	{
		temp->next=s.top();
		s.pop();
		temp=temp->next;
	}
	temp->next=NULL;
	return a;	
}

void Print(Node* temp)
{
		while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	Node* head=NULL;
	cout<<"Enter the number of elements u want to insert "<<endl;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int j;
		cin>>j;
		Node* n=new Node();
		n->data=j;
		n->next=head;
		head=n;
	}
	cout<<"After Insertion "<<endl;
	Print(head);
	Node* temp=reverse_ll(head,n);
	cout<<"After Reversal "<<endl;
	Print(temp);
}
