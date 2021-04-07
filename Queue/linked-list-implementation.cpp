#include<iostream>
using namespace std;
/*
Linked-list-based-implementation-of-stack

-> Resolve the challenge of array-based-implementation-of-stack: No more issue of size.
-> Use 2 pointers rear and front-> To avoid traversal cost

*/
class Node
{
	public:
	int data;
	Node* link;
};
class Queue
{
	private:
		Node* rear;
		Node* front;
	public:
		Queue()
		{
			rear=NULL;
			front=NULL;
		}
		void enqueue(int ele)
		{
			Node* temp=new Node();
			temp->data=ele;
			temp->link=NULL;
			if(front==NULL && rear==NULL)
			{
				front=temp;
				rear=temp;
			}
			else
			{
				rear->link=temp;
				rear=temp;
			}
			
		}
		void dequeue()
		{
			delete(front);
			front=front->link;
		}
		void Print()
		{
			Node* temp=front;
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
	Queue q;
	q.enqueue(1); q.Print();
	q.enqueue(2); q.Print();
	q.enqueue(3); q.Print();
	q.enqueue(4); q.Print();
	q.enqueue(5); q.Print();
	q.dequeue(); q.Print();
	q.enqueue(6); q.Print();
	q.dequeue(); q.Print();
}
