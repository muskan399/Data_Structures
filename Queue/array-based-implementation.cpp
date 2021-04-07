#include<iostream>
#include<string.h>
using namespace std;
/*

To use the space wasted by popped element: Circular implemetation is used.
                                        rear=(rear+1)%N , front=(front+1)%N

Take care of border case

1. Queue is empty: front=rear=-1
2. When 1st element is inserted: front=rear=0
3. If element is inserted: rear=(rear+1)%N
4. If element is deleted and queue is not empty: front=(front+1)%N

*/
class Queue{
	private:
		int arr[5];
		int top,rear,N;
	public:
		Queue()
		{
			top=-1;
			rear=-1;
			N=5;
		};
		void enqueue(int ele)
		{
			if(isempty())
			{
				rear=0;
				top=0;
				arr[rear]=ele;
			}
			else if()
			{
				rear=(rear+1)%N;
				arr[rear]=ele;
			}
			
		}
		void dequeue()
		{
			if(isempty())
			return;
			else
			{
				top=(top+1)%N;
			}
			
		}
		bool isempty()
		{
			if(top==-1 && rear==-1)
			return true;
			else
			return false;
		}
	
		void Print()
		{
			for(int i=0;i<N;i++)
			cout<<arr[i]<<" ";
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
