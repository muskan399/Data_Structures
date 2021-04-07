#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	Node *link;
};
Node *head;
void reverse()
{
	Node *prev,*current,*next;
	current=head;
	prev=NULL;
	while(current!=NULL)
   {
	next=current->link;
	current->link=prev;
	prev=current;
	current=next;
	}
	head=prev;
}
void rreverse(struct Node* p)
{
	
	if(p->link==NULL)
	{
		head=p;
		return ;
	}
	rreverse(p->link);
	Node *q=p->link;
	q->link=p;
	printf("%d\n",q->data);
	p->link=NULL;
}
void insert(int a)
{
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=a;
	temp->link=NULL;
	if(head==NULL)
	{
		head=temp;
		return;
	}
	else
	{
		Node *temp1=head;
		
		while(temp1->link!=NULL)
		{
			temp1=temp1->link;
			
		}
		temp1->link=temp;
		
	}
}
void print()
{
	Node *temp=head;
	while(temp->link!=NULL)
	{
		printf("%d  ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}
void delet(int d)
{
	Node *d1=head;
	Node *temp=head;
	while(temp->data!=d)
	{
		d1=temp;
		temp=temp->link;
	}
	if(temp==head)
	{
		head=temp->link;
		free(temp);
		return;
	}
	else
	{
		d1->link=temp->link;
		free(temp);
	}
}
void d_index(int h)
{
	Node *temp=head;
	if(h==1)
	{
		head=temp->link;
	}
	else
	{
		for(int i=0;i<h-2;i++)
		{
			temp=temp->link;
		}
		Node *temp1=temp->link;
		temp->link=temp1->link;
		free(temp);
	}
}

int main()
{
	head=NULL;
	int n,a,d,k;
	printf("Enter the no. of element you want to insert\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter the element\n");
		scanf("%d",&a);
		insert(a);
		print();
		
	}
	reverse();
	printf("Reversed list is\n");
	print();
	
	//Firstly list get reversed because of above reverse() Now we will get original list
	rreverse(head);
	printf("Using Recursion Reversed list is\n");
	print();
	
	
	printf("Enter the element you want to delete\n");
	scanf("%d",&d);
	delet(d);
	print();
	
	printf("Enter the index(Using One-indexing) you want to delete\n");
	scanf("%d",&k);
	d_index(k);
	print();
	
	
}
